#include <stdint.h>
#include "scheduler.h"

/* Task function prototypes */
void task1_handler(void);
void task2_handler(void);
void task3_handler(void);
void task4_handler(void);
void idle_task(void);

/* Global variables */
uint32_t g_tick_count = 0;
Scheduler_t scheduler;

int main(void)
{
    /* Initialize scheduler data structures */
    init_scheduler_stack(SCHED_STACK_START);

    /* Initialize task stacks with initial register values */
    init_tasks_stack();

    /* Load first task and start the scheduler */
    init_systick_timer(TICK_HZ);

    /* Start first task by switching to PSP */
    switch_sp_to_psp();

    /* Task1 execution will begin here */
    task1_handler();

    /* Should never reach here */
    for(;;);
}

/* Initialize scheduler stack */
__attribute__((naked)) void init_scheduler_stack(uint32_t sched_top_of_stack)
{
    __asm volatile("MSR MSP, R0");
    __asm volatile("BX LR");
}

/* Set up task stacks and TCBs */
void init_tasks_stack(void)
{
    /* Initialize all task control blocks */
    uint32_t *pPSP;

    /* Initialize TCBs */
    for(int i = 0; i < MAX_TASKS; i++) {
        scheduler.tasks[i].taskID = i;
        scheduler.tasks[i].state = TASK_READY;
    }

    /* Task 1 initialization */
    scheduler.tasks[0].taskFunction = task1_handler;
    pPSP = (uint32_t*)TASK1_STACK_START;

    /* Task stack frame (Cortex-M Exception stack frame) */
    pPSP--;
    *pPSP = 0x01000000;      /* xPSR - Thumb state set */
    pPSP--;
    *pPSP = (uint32_t)task1_handler;  /* PC */
    pPSP--;
    *pPSP = 0xFFFFFFFD;      /* LR - Return to thread mode using PSP */

    /* R12, R3, R2, R1, R0 dummy values */
    for(int i = 0; i < 5; i++) {
        pPSP--;
        *pPSP = 0;
    }

    /* R11, R10, R9, R8, R7, R6, R5, R4 dummy values */
    for(int i = 0; i < 8; i++) {
        pPSP--;
        *pPSP = 0;
    }

    /* Save stack pointer to TCB */
    scheduler.tasks[0].pStackPtr = pPSP;

    /* Task 2 initialization */
    scheduler.tasks[1].taskFunction = task2_handler;
    pPSP = (uint32_t*)TASK2_STACK_START;

    pPSP--;
    *pPSP = 0x01000000;
    pPSP--;
    *pPSP = (uint32_t)task2_handler;
    pPSP--;
    *pPSP = 0xFFFFFFFD;

    for(int i = 0; i < 5; i++) {
        pPSP--;
        *pPSP = 0;
    }

    for(int i = 0; i < 8; i++) {
        pPSP--;
        *pPSP = 0;
    }

    scheduler.tasks[1].pStackPtr = pPSP;

    /* Task 3 initialization */
    scheduler.tasks[2].taskFunction = task3_handler;
    pPSP = (uint32_t*)TASK3_STACK_START;

    pPSP--;
    *pPSP = 0x01000000;
    pPSP--;
    *pPSP = (uint32_t)task3_handler;
    pPSP--;
    *pPSP = 0xFFFFFFFD;

    for(int i = 0; i < 5; i++) {
        pPSP--;
        *pPSP = 0;
    }

    for(int i = 0; i < 8; i++) {
        pPSP--;
        *pPSP = 0;
    }

    scheduler.tasks[2].pStackPtr = pPSP;

    /* Task 4 initialization */
    scheduler.tasks[3].taskFunction = task4_handler;
    pPSP = (uint32_t*)TASK4_STACK_START;

    pPSP--;
    *pPSP = 0x01000000;
    pPSP--;
    *pPSP = (uint32_t)task4_handler;
    pPSP--;
    *pPSP = 0xFFFFFFFD;

    for(int i = 0; i < 5; i++) {
        pPSP--;
        *pPSP = 0;
    }

    for(int i = 0; i < 8; i++) {
        pPSP--;
        *pPSP = 0;
    }

    scheduler.tasks[3].pStackPtr = pPSP;

    /* Idle task initialization */
    scheduler.tasks[4].taskFunction = idle_task;
    pPSP = (uint32_t*)IDLE_STACK_START;

    pPSP--;
    *pPSP = 0x01000000;
    pPSP--;
    *pPSP = (uint32_t)idle_task;
    pPSP--;
    *pPSP = 0xFFFFFFFD;

    for(int i = 0; i < 5; i++) {
        pPSP--;
        *pPSP = 0;
    }

    for(int i = 0; i < 8; i++) {
        pPSP--;
        *pPSP = 0;
    }

    scheduler.tasks[4].pStackPtr = pPSP;

    /* Set current task to task 1 */
    scheduler.currentTask = 0;
    scheduler.numTasks = MAX_TASKS;
}

/* Configure SysTick timer for context switching */
void init_systick_timer(uint32_t tick_hz)
{
    /* Calculate SysTick reload value */
    uint32_t reload_value = (SYSTICK_TIM_CLK/tick_hz) - 1;

    /* Configure SysTick */
    /* Reload value */
    *SYST_RVR = reload_value;

    /* Clear current value */
    *SYST_CVR = 0;

    /* Enable SysTick with processor clock and interrupts */
    *SYST_CSR = (1 << 0) | (1 << 1) | (1 << 2);

    /* Configure PendSV priority to lowest (highest value) */
    *SHPR3 |= (0xFF << 16);  /* Set PendSV priority to 0xFF (lowest) */

    /* Configure SysTick priority to second lowest (just above PendSV) */
    *SHPR3 |= (0xFE << 24);  /* Set SysTick priority to 0xFE */
}

/* Switch from MSP to PSP */
__attribute__((naked)) void switch_sp_to_psp(void)
{
    //1. initialize the PSP with TASK1 stack start address

	//get the value of psp of current_task
	__asm volatile ("PUSH {LR}"); //preserve LR which connects back to main()
	__asm volatile ("BL get_psp_value");
	__asm volatile ("MSR PSP,R0"); //initialize psp
	__asm volatile ("POP {LR}");  //pops back LR value

	//2. change SP to PSP using CONTROL register
	__asm volatile ("MOV R0,#0X02");
	__asm volatile ("MSR CONTROL,R0");
	__asm volatile ("BX LR");
}


/* SysTick handler - triggers context switch */
void SysTick_Handler(void)
{
    /* Increment global tick count */
    g_tick_count++;

    /* Unblock tasks if their sleep time has expired */
    unblock_tasks();

    /* Trigger PendSV for context switch */
    *ICSR |= (1 << 28);  /* Set PendSV pending bit */
}

/* PendSV handler - performs context switching */
__attribute__((naked)) void PendSV_Handler(void)
{
    /* Save the context of current task */
    /* 1. Get current running task's PSP value */
    __asm volatile("MRS R0, PSP");

    /* 2. Using that PSP value store SF2(R4 to R11) */
    __asm volatile("STMDB R0!, {R4-R11}");

    /* 3. Save the current value of PSP */
    __asm volatile("PUSH {LR}");
    __asm volatile("BL save_psp_value");

    /* Retrieve the context of next task */
    /* 1. Decide next task to run */
    __asm volatile("BL update_next_task");

    /* 2. Get its past PSP value */
    __asm volatile("BL get_psp_value");

    /* 3. Using that PSP value retrieve SF2(R4 to R11) */
    __asm volatile("LDMIA R0!, {R4-R11}");

    /* 4. Update PSP and exit */
    __asm volatile("MSR PSP, R0");
    __asm volatile("POP {LR}");
    __asm volatile("BX LR");
}

/* Save current task's PSP value */
void save_psp_value(uint32_t current_psp)
{
    scheduler.tasks[scheduler.currentTask].pStackPtr = (uint32_t*)current_psp;
}

/* Update task selection - implements round-robin */
void update_next_task(void)
{
    /* Change current task state to READY */
    scheduler.tasks[scheduler.currentTask].state = TASK_READY;

    /* Increment current task index */
    scheduler.currentTask++;

    /* Wrap around if reached end of task list */
    if(scheduler.currentTask >= MAX_TASKS)
    {
        scheduler.currentTask = 0;
    }

    /* Skip blocked tasks */
    uint8_t count = 0;
    while((scheduler.tasks[scheduler.currentTask].state != TASK_READY) && (count < MAX_TASKS))
    {
        scheduler.currentTask++;
        if(scheduler.currentTask >= MAX_TASKS)
        {
            scheduler.currentTask = 0;
        }
        count++;
    }

    /* Change new task state to RUNNING */
    scheduler.tasks[scheduler.currentTask].state = TASK_RUNNING;
}

/* Get PSP of next task to run */
uint32_t get_psp_value(void)
{
    return (uint32_t)scheduler.tasks[scheduler.currentTask].pStackPtr;
}

/* Make task sleep for given ticks */
void task_sleep(uint32_t tick_count)
{
    /* Save wake-up tick count */
    uint32_t current_tick = g_tick_count;
    scheduler.tasks[scheduler.currentTask].wakeup_tick = current_tick + tick_count;

    /* Set task state to BLOCKED */
    scheduler.tasks[scheduler.currentTask].state = TASK_BLOCKED;

    /* Trigger scheduler */
    *ICSR |= (1 << 28);  /* Set PendSV pending bit */

    /* Wait for DSB (Data Synchronization Barrier) */
    __asm volatile("DSB");

    /* Wait for ISB (Instruction Synchronization Barrier) */
    __asm volatile("ISB");
}

/* Unblock tasks that have completed their sleep */
void unblock_tasks(void)
{
    for(int i = 0; i < MAX_TASKS; i++)
    {
        if(scheduler.tasks[i].state == TASK_BLOCKED)
        {
            if(g_tick_count >= scheduler.tasks[i].wakeup_tick)
            {
                /* Task has completed its sleep, mark it as READY */
                scheduler.tasks[i].state = TASK_READY;
            }
        }
    }
}

/* Task handler implementations */
void task1_handler(void)
{
    while(1)
    {
        /* Toggle LED1 */
        printf("Task 1 running - tick count: %lu\n", g_tick_count);
        task_sleep(100);
    }
}

void task2_handler(void)
{
    while(1)
    {
        /* Toggle LED2 */
        printf("Task 2 running - tick count: %lu\n", g_tick_count);

        task_sleep(200);
    }
}

void task3_handler(void)
{
    while(1)
    {
        /* Toggle LED3 */
        printf("Task 3 running - tick count: %lu\n", g_tick_count);
        task_sleep(300);
    }
}

void task4_handler(void)
{
    while(1)
    {
        /* Toggle LED4 */
        printf("Task 4 running - tick count: %lu\n", g_tick_count);
        task_sleep(400);
    }
}

void idle_task(void)
{
    static uint32_t idle_counter = 0;

    while(1)
    {
        idle_counter++;

        /* Occasionally print idle message (every 1000 iterations) */
        if(idle_counter % 1000 == 0) {
            printf("Idle task running - counter: %lu\r\n", idle_counter);
        }
    }
}

/*
 * scheduler.h
 *
 * Created on: May 11, 2025
 * Author: Orr
 */

#ifndef SCHEDULER_H_
#define SCHEDULER_H_

#include <stdint.h>

/* Configuration constants */
#define MAX_TASKS           5
#define SIZE_TASK_STACK     1024U
#define SIZE_SCHED_STACK    1024U
#define SRAM_START          0x20000000U
#define SIZE_SRAM           ((128) * (1024))
#define SRAM_END            ((SRAM_START) + (SIZE_SRAM))

/* Calculate stack addresses */
#define IDLE_STACK_START    (SRAM_END)
#define TASK4_STACK_START   (IDLE_STACK_START - SIZE_TASK_STACK)
#define TASK3_STACK_START   (TASK4_STACK_START - SIZE_TASK_STACK)
#define TASK2_STACK_START   (TASK3_STACK_START - SIZE_TASK_STACK)
#define TASK1_STACK_START   (TASK2_STACK_START - SIZE_TASK_STACK)
#define SCHED_STACK_START   (TASK1_STACK_START - SIZE_SCHED_STACK)

/* SysTick configuration */
#define TICK_HZ             1000U  /* 1000Hz -> 1ms tick */
#define SYSTICK_TIM_CLK     16000000U  /* 16MHz system clock */

/* Cortex-M4 system registers */
#define SYST_CSR            ((volatile uint32_t*)0xE000E010)  /* SysTick Control and Status Register */
#define SYST_RVR            ((volatile uint32_t*)0xE000E014)  /* SysTick Reload Value Register */
#define SYST_CVR            ((volatile uint32_t*)0xE000E018)  /* SysTick Current Value Register */
#define ICSR                ((volatile uint32_t*)0xE000ED04)  /* Interrupt Control and State Register */
#define SHPR3               ((volatile uint32_t*)0xE000ED20)  /* System Handler Priority Register 3 */

/* Task States */
typedef enum {
    TASK_READY,
    TASK_RUNNING,
    TASK_BLOCKED,
    TASK_TERMINATED
} TaskState_t;


typedef enum {
    PRIORITY_LOW = 0,
    PRIORITY_MEDIUM,
    PRIORITY_HIGH,
    PRIORITY_REALTIME
} TaskPriority_t;


/* Task Control Block */
typedef struct {
    uint32_t *pStackPtr;      /* Current stack pointer for task */
    void (*taskFunction)(void);  /* Task entry point function */
    TaskState_t state;        /* Current state of task */
    uint32_t taskID;          /* Unique task identifier */
    uint32_t wakeup_tick;     /* Tick count when task should wake up (if sleeping) */
    TaskPriority_t priority;  /* Task priority level */
} TCB_t;

/* Scheduler Data Structure */
typedef struct {
    TCB_t tasks[MAX_TASKS];   /* Array of task control blocks */
    uint32_t currentTask;     /* Index of current running task */
    uint32_t numTasks;        /* Number of tasks in the system */
} Scheduler_t;

/* Global variables */
extern Scheduler_t scheduler;
extern uint32_t g_tick_count;

/* Function prototypes */
void init_systick_timer(uint32_t tick_hz);
__attribute__((naked)) void init_scheduler_stack(uint32_t sched_top_of_stack);
void init_tasks_stack(void);
__attribute__((naked)) void switch_sp_to_psp(void);
void save_psp_value(uint32_t current_psp);
void update_next_task(void);
uint32_t get_psp_value(void);
void task_sleep(uint32_t tick_count);
void unblock_tasks(void);

#endif /* SCHEDULER_H_ */

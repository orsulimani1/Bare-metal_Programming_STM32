/*
 * semaphore.c
 *
 *  Created on: May 18, 2025
 *      Author: Orr
 */

#include "semaphore.h"
#include "scheduler.h"

/* External scheduler variables */
extern Scheduler_t scheduler;

void semaphore_init(Semaphore_t* sem, uint32_t initial_count)
{
    sem->count = initial_count;
    sem->waiting_count = 0;
}

void semaphore_take(Semaphore_t* sem)
{
    /* Disable interrupts for atomic operation */
//    __disable_irq();

    /* Check if semaphore is available */
    if(sem->count > 0)
    {
        /* Resource available, take it */
        sem->count--;
//        __enable_irq();
    }
    else
    {
        /* Resource unavailable, block task */
        TCB_t* current_task = &scheduler.tasks[scheduler.currentTask];

        /* Add task to waiting list */
        sem->waiting_tasks[sem->waiting_count++] = current_task;

        /* Set task state to BLOCKED */
        current_task->state = TASK_BLOCKED;

        /* Re-enable interrupts */
//        __enable_irq();

        /* Trigger scheduler */
        *ICSR |= (1 << 28);

        /* Wait for DSB and ISB */
        __asm volatile("DSB");
        __asm volatile("ISB");
    }
}

void semaphore_give(Semaphore_t* sem)
{
    /* Disable interrupts for atomic operation */
//    __disable_irq();

    /* Check if tasks are waiting */
    if(sem->waiting_count > 0)
    {
        /* Unblock the first waiting task */
        TCB_t* task = sem->waiting_tasks[0];

        /* Remove task from waiting list */
        for(int i = 0; i < sem->waiting_count - 1; i++)
        {
            sem->waiting_tasks[i] = sem->waiting_tasks[i+1];
        }
        sem->waiting_count--;

        /* Set task to READY state */
        task->state = TASK_READY;
    }
    else
    {
        /* No waiting tasks, increment counter */
        sem->count++;
    }

    /* Re-enable interrupts */
//    __enable_irq();
}

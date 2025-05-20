/*
 * semaphore.h
 *
 *  Created on: May 18, 2025
 *      Author: Orr
 */

#ifndef SEMAPHORE_H_
#define SEMAPHORE_H_

#include "scheduler.h"

typedef struct {
    uint32_t count;
    TCB_t* waiting_tasks[MAX_TASKS];
    uint32_t waiting_count;
} Semaphore_t;

void semaphore_init(Semaphore_t* sem, uint32_t initial_count);
void semaphore_take(Semaphore_t* sem);
void semaphore_give(Semaphore_t* sem);

#endif /* SEMAPHORE_H_ */

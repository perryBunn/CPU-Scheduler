#include "simulator.h"
#include "process.h"
#include <iostream>
#include <chrono>

using namespace std;

simulator::simulator() {
}

void simulator::sim(process *task_list, process *finish_task_list) {
    while (!task_list->empty() or !this->ready_queue->empty()) {
        /* handle new arrivals: module 4.1. See the previous slide */
        /* run first task in the ready queue: module 4.2 */
        process first_task = this->ready_queue->pop();
        /* determine task’s start_time */
        if (first_task.remaining_time == first_task.burst_time) {
            first_task.start_time = chrono::system_clock::time_point.now();/* run first_task */
            first_task.remaining_time--;/* check if first_task finishes or not */
        }
        if (first_task.remaining_time == 0) {
            first_task.finish_time = chrono::system_clock::time_point.now();
            remove first_task from ready_queue;
            place first_task to finish_task_list;
        }
    } /* end while */
}



#ifndef CPU_SCHEDULER_SIMULATOR_H
#define CPU_SCHEDULER_SIMULATOR_H

#include "process.h"
#include <queue>

using namespace std;

class simulator {
    public:
        queue<process> ready_queue;

        simulator();

        void fcfs(queue<process> &task_list, queue<process> &finish_task_list);

        void rr(queue<process> &task_list, queue<process> &finish_task_list);

        void srft(queue<process> &task_list, queue<process> &finish_task_list);

        void is_ready(process p);

        void srft_sort();

        void pop_active_process(process &active);
};
#endif //CPU_SCHEDULER_SIMULATOR_H

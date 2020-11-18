#ifndef CPU_SCHEDULER_SIMULATOR_H
#define CPU_SCHEDULER_SIMULATOR_H

#include "process.h"
#include <queue>

using namespace std;

class simulator {
    public:
        queue<process> ready_queue;

        simulator();

        void sim(queue<process> task_list, queue<process> finish_task_list);

        void is_ready(process p);
};
#endif //CPU_SCHEDULER_SIMULATOR_H

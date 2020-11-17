#ifndef CPU_SCHEDULER_SIMULATOR_H
#define CPU_SCHEDULER_SIMULATOR_H

#include "process.h"

using namespace std;

class simulator {
    public:
        process ready_queue[100];

        simulator();

        void sim(process task_list[], process finish_task_list[]);

        void is_ready(process p);
};
#endif //CPU_SCHEDULER_SIMULATOR_H

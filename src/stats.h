#ifndef CPU_SCHEDULER_STATS_H
#define CPU_SCHEDULER_STATS_H

#include <queue>
#include "process.h"

class stats {
    public:
        float avgWaitingTime;
        float avgResponceTime;
        float avgTurnAround;
        float cpuUsage;

        stats();

        void calculate(queue<process> finished_task_list);
};


#endif //CPU_SCHEDULER_STATS_H

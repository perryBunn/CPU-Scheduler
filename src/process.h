#ifndef CPU_SCHEDULER_PROCESS_H
#define CPU_SCHEDULER_PROCESS_H
#include <string>

using namespace std;

class process {
    public:
        string pid;
        int arrivalTime;
        int burstTime;

        process(string pidIn, int arrivalIn, int burstIn);

        string getPID();

        int getArrivalTime();

        int getBurstTime();

        void setPID(string pidIn);

        void setArrivalTime(int arrivalIn);

        void setBurstTime(int burstIn);
};


#endif //CPU_SCHEDULER_PROCESS_H

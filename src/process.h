#ifndef CPU_SCHEDULER_PROCESS_H
#define CPU_SCHEDULER_PROCESS_H
#include <string>
#include <chrono>
using namespace std;

class process {
    public:
        string pid;
        chrono::system_clock::time_point start_time;
        chrono::system_clock::time_point finish_time;
        int arrival_time;
        int burst_time;
        int remaining_time;

        process();

        process(string pidIn, int arrivalIn, int burstIn);

        process(string pidIn, string arravalIn, string burstIn);

        process(int pidIn, int arrivalIn, int burstIn);

        string getPID();

        int getArrivalTime();

        int getBurstTime();

        void setPID(string pidIn);

        void setArrivalTime(int arrivalIn);

        void setBurstTime(int burstIn);
};

#endif //CPU_SCHEDULER_PROCESS_H

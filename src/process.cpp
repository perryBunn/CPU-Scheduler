#include "process.h"
#include <iostream>
#include <string>


using namespace std;

process::process(string PIDIn, int arrivalIn, int burstIn) {
    pid = PIDIn;
    arrivalTime = arrivalIn;
    burstTime = burstIn;
}

string process::getPID() {
    return pid;
}

int process::getArrivalTime() {
    return arrivalTime;
}

int process::getBurstTime() {
    return burstTime;
}

void process::setPID(string pidIn) {
    pid = pidIn;
}

void process::setArrivalTime(int arrivalIn) {
    arrivalTime = arrivalIn
}

void process::setBurstTime(int burstIn) {
    burstTime = burstIn
}

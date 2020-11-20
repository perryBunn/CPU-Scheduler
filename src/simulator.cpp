#include "simulator.h"
#include "process.h"
#include <queue>
#include <iostream>
#include <chrono>

using namespace std;

simulator::simulator() = default;

void simulator::fcfs(queue<process> &task_list, queue<process> &finish_task_list) {
    cout << "sim" << endl;

    cout << "##### task list check #####" << endl;
    cout << "task list size: " << task_list.size() << endl;
    int list_size = task_list.size();
    queue<process> task_list_copy = task_list;
    for (int i = 0; i < list_size; i++) {
        cout << task_list_copy.front().pid << " " << task_list_copy.front().arrival_time << " " << task_list_copy.front().burst_time << endl;
        task_list_copy.pop();
    }
    cout << &task_list << endl;
    cout << &finish_task_list << endl;
    cout << "##### end task list check #####" << endl;

    int time = 0;
    process active_task = this->ready_queue.front();
    while (!task_list.empty() or !this->ready_queue.empty()) {
        while (task_list.front().arrival_time == time) {
            this->ready_queue.push(task_list.front());
            task_list.pop();
        }
        if (time == 0) {
            active_task = this->ready_queue.front();
        }
        if (active_task.remaining_time == 0) {
            active_task.finish_time = chrono::system_clock::now();
            cout << "<time " << time << "> " << active_task.pid << " is finished..." << endl;
            this->ready_queue.pop();
            finish_task_list.push(active_task);
            if (task_list.empty() and this->ready_queue.empty()) {
                break;
            }
            active_task = this->ready_queue.front();
        }
        /* determine task’s start_time */
        if (active_task.remaining_time == active_task.burst_time) {
            active_task.start_time = chrono::system_clock::now(); /* run active_task */
        }
        cout << "<time " << time << "> " << active_task.pid << " is running" << endl;
        active_task.remaining_time--; /* check if active_task finishes or not */
        time++;
    } /* end while */
    cout << "end sim" << endl;
}

void simulator::srft(queue <process> &task_list, queue <process> &finish_task_list) {
    cout << "sim" << endl;

    cout << "##### task list check #####" << endl;
    cout << "task list size: " << task_list.size() << endl;
    int list_size = task_list.size();
    queue<process> task_list_copy = task_list;
    for (int i = 0; i < list_size; i++) {
        cout << task_list_copy.front().pid << " " << task_list_copy.front().arrival_time << " " << task_list_copy.front().burst_time << endl;
        task_list_copy.pop();
    }
    cout << &task_list << endl;
    cout << &finish_task_list << endl;
    cout << "##### end task list check #####" << endl;

    int time = 0;
    process active_task = this->ready_queue.front();
    while (!task_list.empty() or !this->ready_queue.empty()) {
//        cout << "##### ready_queue check #####" << endl;
//        int list_size = this->ready_queue.size();
//        queue<process> task_list_copy = this->ready_queue;
//        for (int i = 0; i < list_size; i++) {
//            cout << task_list_copy.front().pid << " " << task_list_copy.front().arrival_time << " " << task_list_copy.front().burst_time << endl;
//            task_list_copy.pop();
//        }
//        cout << "##### end ready_queue check #####" << endl;

        while (task_list.front().arrival_time == time) {
            this->ready_queue.push(task_list.front());
            task_list.pop();
            this->srft_sort();
        }

//        cout << "##### ready_queue check #####" << endl;
//        int list_size2 = this->ready_queue.size();
//        queue<process> task_list_copy2 = this->ready_queue;
//        for (int i = 0; i < list_size2; i++) {
//            cout << task_list_copy2.front().pid << " " << task_list_copy2.front().arrival_time << " " << task_list_copy2.front().burst_time << endl;
//            task_list_copy2.pop();
//        }
//        cout << "##### end ready_queue check #####" << endl;

        if (time == 0) {
            active_task = this->ready_queue.front();
        }
        if (active_task.remaining_time == 0) {
            active_task.finish_time = chrono::system_clock::now();
            cout << "<time " << time << "> " << active_task.pid << " is finished..." << endl;
            this->pop_active_process(active_task);
            finish_task_list.push(active_task);
            if (task_list.empty() and this->ready_queue.empty()) {
                break;
            }
            active_task = this->ready_queue.front();
        }
        if (active_task.remaining_time == active_task.burst_time) {
            active_task.start_time = chrono::system_clock::now(); /* run active_task */
        }
        cout << "<time " << time << "> " << active_task.pid << " is running" << endl;
        active_task.remaining_time--; /* check if active_task finishes or not */
        time++;
        //break;
    }
    cout << "end sim" << endl;
}

void simulator::pop_active_process(process &active){
    queue<process> temp = this->ready_queue;
    int list_size = this->ready_queue.size();

    // clear ready_queue
    for (int i = 0; i < list_size; i++) {
        //cout << ready_queue.front().pid << endl;
        this->ready_queue.pop();
    }
    //cout << "----" << endl;
    // readd ready queue without active
    for (int i = 0; i < list_size; i++) {
        if (!(temp.front().equals(active))) {
            //cout << "### info ###" << endl;
            //cout << temp.front().pid << active.pid << endl;
            this->ready_queue.push(temp.front());
            //cout << temp.front().pid << endl;
        }
        temp.pop();
    }
    // check
//    cout << "### check" << endl;
//    queue<process> temp2 = this->ready_queue;
//    for (int i = 0; i < list_size; i++) {
//        cout << temp2.front().pid << endl;
//        temp2.pop();
//    }
}

void simulator::srft_sort() {
    int list_size = this->ready_queue.size();
    process temp[list_size];
    // convert to array
    for (int i = 0; i < list_size; ++i) {
        temp[i] = this->ready_queue.front();
        //cout << ready_queue.front().pid << endl;
        this->ready_queue.pop();
    }
    // sort
    for (int i = 0; i < list_size-1; ++i) {
        for (int j = 0; j < list_size-i-1; ++j) {
            process cur = temp[j];
            if (cur.burst_time > temp[j+1].burst_time) {
                temp[j] = temp[j+1];
                temp[j+1] = cur;
            }
        }
    }
    // place in ready_queue
    //cout << "print ready_queue" << endl;
    for (int i = 0; i < list_size; ++i) {
        //cout << "pid: " << temp[i].pid << " burst: " << temp[i].burst_time << endl;
        this->ready_queue.push(temp[i]);
    }
}

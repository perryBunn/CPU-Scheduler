#include "stats.h"
#include <iostream>

using namespace std;

stats::stats() = default;

void stats::calculate(queue<process> finished_task_list) {
    //cout << "##### finished task list check #####" << endl;

    cout << "task list size: " << finished_task_list.size() << endl;
    int list_size = finished_task_list.size();
    queue<process> task_list_copy = finished_task_list;
    for (int i = 0; i < list_size; i++) {
        cout << task_list_copy.front().pid << " " << task_list_copy.front().arrival_time << " " << task_list_copy.front().burst_time << " ";
        cout << task_list_copy.front().start_time << " " << task_list_copy.front().finish_time << endl;
        task_list_copy.pop();
    }
    cout << &finished_task_list << endl;

    cout << "##### end finsihed task list check #####" << endl;


}
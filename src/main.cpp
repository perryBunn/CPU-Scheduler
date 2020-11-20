#include "process.h"
#include "parser.h"
#include "simulator.h"
#include <iostream>
#include <string>
#include <regex>
#include <queue>
#include "stdio.h"
#include "stats.h"

using namespace std;

void PressEnterToContinue()
{
    int c;
    printf( "Press ENTER to continue... " );
    fflush( stdout );
    do c = getchar(); while ((c != '\n') && (c != EOF));
}

int main(int argc, char* argv[]) {
    //cout << "ARGC: " << argc << endl;
    if (argc <= 2 || argc > 4) { // Single argument commands or to many arguments.
        string arg1 = argv[1];
        if (arg1 == "?h") {
            cout << "Usage: command file_name [FCFS|RR|SRFT] [time_quantum]" << endl;
        } else {
            cout << arg1 << " is not a recognized command. Use ?h for help." << endl;
        }
    } else if (argc > 2) { // Multi argument commands.
        string arg1 = argv[1];
        string arg2 = argv[2];

        const std::regex base_regex("[\\S]+\\.list");
        std::smatch base_match;

        if (std::regex_search(arg1, base_match, base_regex)) { // Some condition for files. Possibly regex?
            //cout << arg1 << endl;
            if (arg2 == "FCFS") {
                cout << "FCFS" << endl;
                parser p;
                queue<process> task_list;
                queue<process> final_task_list;
                task_list = p.readInputFile(arg1);

                //cout << "##### task list check #####" << endl;
                /*
                cout << "task list size: " << task_list.size() << endl;
                int list_size = task_list.size();
                queue<process> task_list_copy = task_list;
                for (int i = 0; i < list_size; i++) {
                    cout << task_list_copy.front().pid << " " << task_list_copy.front().arrival_time << " " << task_list_copy.front().burst_time << endl;
                    task_list_copy.pop();
                }
                cout << &task_list << endl;
                cout << &finish_task_list << endl;
                */
                //cout << "##### end task list check #####" << endl;

                cout << "Scheduling Policy: " << arg2 << endl;
                cout << "There are " << task_list.size() << " task loaded from \"" << arg1 << "\".";
                PressEnterToContinue();
                cout << "==================================================================" << endl;
                simulator sim;
                sim.fcfs(task_list, final_task_list);
                cout << "==================================================================" << endl;
                stats stat;
                stat.calculate(final_task_list);
            } else if  (arg2 == "RR") {
                //cout << "RR" << endl;
                if (argc > 3) { // If argc is larger that 3, continue.
                    int quantum_time = stoi(argv[3]);
                    parser p;
                    queue<process> task_list;
                    queue<process> final_task_list;
                    task_list = p.readInputFile(arg1);

                    //cout << "##### task list check #####" << endl;
                    /*
                    cout << "task list size: " << task_list.size() << endl;
                    int list_size = task_list.size();
                    queue<process> task_list_copy = task_list;
                    for (int i = 0; i < list_size; i++) {
                        cout << task_list_copy.front().pid << " " << task_list_copy.front().arrival_time << " " << task_list_copy.front().burst_time << endl;
                        task_list_copy.pop();
                    }
                    cout << &task_list << endl;
                    cout << &finish_task_list << endl;
                    */
                    //cout << "##### end task list check #####" << endl;

                    cout << "Scheduling Policy: " << arg2 << endl;
                    cout << "There are " << task_list.size() << " task loaded from \"" << arg1 << "\".";
                    PressEnterToContinue();
                    cout << "==================================================================" << endl;
                    simulator sim;
                    sim.rr(task_list, final_task_list, quantum_time);
                    cout << "==================================================================" << endl;
                    stats stat;
                    stat.calculate(final_task_list);
                } else {
                    // help for RR. Not enough arguments.
                    cout << "RR requires additional arguments." << endl;
                }
            } else if (arg2 == "SRFT") {
                cout << "SRFT" << endl;
                parser p;
                queue<process> task_list;
                queue<process> final_task_list;
                task_list = p.readInputFile(arg1);

                //cout << "##### task list check #####" << endl;
                /*
                cout << "task list size: " << task_list.size() << endl;
                int list_size = task_list.size();
                queue<process> task_list_copy = task_list;
                for (int i = 0; i < list_size; i++) {
                    cout << task_list_copy.front().pid << " " << task_list_copy.front().arrival_time << " " << task_list_copy.front().burst_time << endl;
                    task_list_copy.pop();
                }
                cout << &task_list << endl;
                cout << &finish_task_list << endl;
                */
                //cout << "##### end task list check #####" << endl;

                cout << "Scheduling Policy: " << arg2 << endl;
                cout << "There are " << task_list.size() << " task loaded from \"" << arg1 << "\".";
                PressEnterToContinue();
                cout << "==================================================================" << endl;
                simulator sim;
                sim.srft(task_list, final_task_list);
                cout << "==================================================================" << endl;
                stats stat;
                stat.calculate(final_task_list);
            } else {
                cout << arg2 << " is not a recognized task algorithm." << endl;
            }
            cout << "finished with cmd args." << endl;
        } else {
            // No matching file pattern.
            cout << "Something went wrong. Supported file type is *.list" << endl;
        }
    } else {
        // No command line args
        cout << "Not enough or no command line arguments were specified. Use ?h to see usage." << endl;
    }
    return 0;
}


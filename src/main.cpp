#include "process.h"
#include "parser.h"
#include "simulator.h"
#include <iostream>
#include <string>
#include <regex>
#include <queue>

using namespace std;


int main(int argc, char* argv[]) {
    cout << "ARGC: " << argc << endl;
    if (argc <= 2 || argc > 4) { // Single argument commands or to many arguments.
        string arg1 = argv[1];
        if (arg1 == "?h") {
            cout << "Usage: command file_name [FCFS|RR|SRFT] [time_quantum]" << endl;
        } else {
            cout << arg1 << " is not a recognized command. Use ?h for help." << endl;
        }
    } else if (argc > 2) { // Multi argument commands.
//        for (int i = 1; i < argc; i++) {
//            cout << argv[i] << endl; // This line will print out the rest of the commands.
//        }
        string arg1 = argv[1];
        string arg2 = argv[2];

        const std::regex base_regex("[\\S]+\\.list");
        std::smatch base_match;

        if (std::regex_search(arg1, base_match, base_regex)) { // Some condition for files. Possibly regex?
            cout << arg1 << endl;
            if (arg2 == "FCFS") {
                cout << "FCFS" << endl;
                parser p;
                queue<process> task_list = p.readInputFile(arg1);
                queue<process> final_task_list;
                simulator sim;
                sim.sim(task_list, final_task_list);
            } else if  (arg2 == "RR") {
                cout << "RR" << endl;
                if (argc > 3) { // If argc is larger that 3, continue.
                    string arg3 = argv[3];
                    cout << arg3 << endl;
                } else {
                    // help for RR. Not enough arguments.
                    cout << "RR requires additional arguments." << endl;
                }
            } else if (arg2 == "SRTF") {
                cout << "SRTF" << endl;
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
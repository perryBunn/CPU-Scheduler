#include "parser.h"
#include "process.h"
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
    cout << "ARGC: " << argc << endl;
    if (argc == 2) { // Single argument commands.
        string arg1 = argv[1];
        if (arg1 == "?h") {
            cout << "help" << endl;
        }
        cout << arg1 << endl;
    } else if (argc > 2) { // Multi argument commands.
//        for (int i = 1; i < argc; i++) {
//            cout << argv[i] << endl; // This line will print out the rest of the commands.
//        }
        string arg1 = argv[1];
        string arg2 = argv[2];
        if (true) { // Some condition for files. Possibly regex?
            cout << arg1 << endl;
            if (arg2 == "FCFS") {
                cout << "FCFS" << endl;
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
        } else {
            // No matching file pattern.
            cout << "Something went wrong." << endl;
        }
    } else {
        // No command line args
        cout << "Not enough or no command line arguments were specified. Use ?h to see usage." << endl;
    }
    return 0;
}
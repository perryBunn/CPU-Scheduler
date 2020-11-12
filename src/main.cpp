#include "parser.h"
#include "process.h"
#include <iostream>
#include <string>

using namespace std;


int main(int argc, char* argv[]) {
    if (argc > 1) {
        for (int i = 1; i < argc; i++) {
            cout << argv[i] << endl; // This line will print out the rest of the commands
        }
        string file = argv[1];
        if (file.find("list")) {
            cout << file << endl;
        }
    } else {
        // No command line args
    }
    return 0;
}
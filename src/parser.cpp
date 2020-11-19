#include "parser.h"
#include "process.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

parser::parser() {

}

queue<process> parser::readInputFile(string file) {
    queue<process> res;
    ifstream reader;
    reader.open(file);
    if (reader.is_open()) {
        int pid;
        int arrival;
        int burst;
        while (reader >> pid >> arrival >> burst) {
            process temp = process(pid, arrival, burst);
            res.push(temp);
        }
        reader.close();
    }
    return res;
}

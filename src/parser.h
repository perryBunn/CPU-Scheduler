#ifndef CPU_SCHEDULER_PARSER_H
#define CPU_SCHEDULER_PARSER_H

#include "process.h"
#include <string>
#include <queue>

using namespace std;

class parser {
    public:
        parser();

        queue<process> readInputFile(string file);

};

#endif //CPU_SCHEDULER_PARSER_H

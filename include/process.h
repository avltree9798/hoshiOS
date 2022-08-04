#ifndef _PROCESS_H
#define _PROCESS_H

#include "handler.h"
#include "file.h"
#include "stdlib.h"

struct Process {
    int pid;
    int state;
    uint64_t page_map;
    uint64_t stack;
    struct TrapFrame *tf;
};

#define NUM_PROC 10
#define PROC_UNUSED 0
#define PROC_INIT 1
#define PROC_RUNNING 2

void init_process(void);
#endif // _PROCESS_H
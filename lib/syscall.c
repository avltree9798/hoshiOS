#include "../include/syscall.h"
#include "../include/print.h"
#include "../include/debug.h"
#include "stddef.h"

static SYSTEMCALL system_calls[10];


static int write(int64_t *argptr) {
    write_console((char*) argptr[0], (int) argptr[1]);
    return (int) argptr[1];
}


void init_syscall(void) {
    system_calls  [0] = write;
}

void syscall(struct TrapFrame* tf) {
    int64_t i = tf->x16;
    int64_t param_count = tf->x0;
    int64_t *argptr = (int64_t*) tf->x1;

    if (param_count < 0 || i != 0) {
        tf->x0 = -1;
        return;
    }

    tf->x0 = system_calls[i](argptr);
}
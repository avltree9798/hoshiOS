#ifndef _SYSCALL_H
#define _SYSCALL_H

#include "handler.h"

typedef int (*SYSTEMCALL)(int64_t *argptr);
void init_syscall(void);
void syscall(struct TrapFrame* tf);

#endif // _SYSCALL_
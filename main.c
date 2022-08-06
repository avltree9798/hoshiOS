#include "include/uart.h"
#include "include/stdio.h"
#include "include/debug.h"
#include "include/stdlib.h"
#include "include/handler.h"
#include "include/memory.h"
#include "include/file.h"
#include "include/process.h"
#include "include/syscall.h"
#include<stddef.h>

void KMain(void)
{
    init_uart();
    printk("Hello, Raspberry pi\r\n");
    printk("We are at EL %u\r\n", get_el());
 
    init_memory(); 
    init_syscall();
    init_fs();
    init_timer();
    init_interrupt_controller();
    enable_irq();
    init_process();
    
    // while (1) {
    //     ;
    // }
}
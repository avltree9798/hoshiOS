#include "stdint.h"
#include "../include/stdio.h"
#include "../include/stdlib.h"
#include "../include/irq.h"
#include "../include/uart.h"
#include "../include/handler.h"
#include "../include/syscall.h"

void enable_timer(void);
uint32_t read_timer_status(void);
void set_timer_interval(uint32_t value);
uint32_t read_timer_freq(void);

static uint32_t timer_interval = 0;
static uint64_t ticks = 0;

void init_interrupt_controller(void) {
    out_word(DISABLE_BASIC_IRQS, 0xffffffff);
    out_word(DISABLE_IRQS_1, 0xffffffff);
    out_word(DISABLE_IRQS_2, 0xffffffff);

    out_word(ENABLE_IRQS_2, (1 << 25));
}

void init_timer(void) {
    timer_interval = read_timer_freq() / 100;
    enable_timer();
    out_word(CNTP_EL0, (1 << 1));
}

static void timer_interrupt_handler(uint64_t spsr) {
    uint32_t status = read_timer_status();
    if (status & (1 << 2)) {
        ticks++;
        if (ticks % 100 == 0) {
            printk("timer %d %x \r\n", ticks, spsr);
        }

        set_timer_interval(timer_interval);
    }
}

static uint32_t get_irq_number(void) {
    return in_word(IRQ_BASIC_PENDING);
}

void handler(struct TrapFrame* tf) {
    uint32_t irq;
    switch (tf->trapno) {
        case 1:
            printk("sync error at %x: %x\r\n", tf->elr, tf->esr);
            while (1) { }

        case 2:
            irq = in_word(CNTP_STATUS_EL0);
            if (irq & (1 << 1)) {
                timer_interrupt_handler(tf->esr);
            }
            else {
                irq = get_irq_number();
                if (irq & (1 << 19)) {
                    uart_handler();
                }
                else {
                    printk("unknown irq\r\n");
                    while (1) { }
                }
            }
            break;
        case 3:
            syscall(tf);
            break;
        default:
            printk("unknown exception\r\n");
            while (1) { }
    }
}
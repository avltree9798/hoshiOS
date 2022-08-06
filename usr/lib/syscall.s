.section .text
.global write

write:
    sub sp, sp, #16
    mov x16, #0

    stp x0, x1, [sp]
    mov x0, #2
    mov x1, sp
    svc #80

    add sp, sp, #16
    ret

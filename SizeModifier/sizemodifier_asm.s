.text
.align 4

.global ModifyGlobalSizes_LoadAsm
ModifyGlobalSizes_LoadAsm:

    mov     r0, r4
    bl      ModifyGlobalSizes
    
    ldmfd           SP!, {r4-r6, pc}

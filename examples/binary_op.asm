global _start
_start:
    call _MAIN
    mov ebx, eax
    mov eax, 1
    int 0x80
global _MAIN
_MAIN:
    push ebp
    mov ebp, esp
    mov eax, 2
    push eax
    mov eax, 2
    pop ecx
    add eax, ecx
    mov esp, ebp
    pop ebp
    ret
    add esp, 0
    mov esp, ebp
    pop ebp
    mov eax, 0
    ret

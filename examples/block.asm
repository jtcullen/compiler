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
    mov eax, 0
    push eax
    add esp, 4
    mov eax, 1
    push eax
    mov eax, [ebp+-4]
    mov esp, ebp
    pop ebp
    ret
    add esp, 4
    mov esp, ebp
    pop ebp
    mov eax, 0
    ret

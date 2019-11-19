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
    mov eax, [ebp+-4]
    push eax
    mov eax, 1
    pop ecx
    cmp ecx, eax
    mov eax, 0
    sete al
    cmp eax, 0
    je _else1
    mov eax, 0
    mov [ebp+-4], eax
    jmp _elseEnd1
_else1:
    mov eax, 3
    mov [ebp+-4], eax
    add esp, 0
_elseEnd1:
    mov eax, [ebp+-4]
    mov esp, ebp
    pop ebp
    ret
    add esp, 4
    mov esp, ebp
    pop ebp
    mov eax, 0
    ret

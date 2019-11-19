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
    neg eax
    push eax
    mov eax, 1
    push eax
    mov eax, 2
    push eax
    mov eax, 2
    cdq
    pop ecx
    idiv ecx
    push eax
    mov eax, 1
    push eax
    mov eax, 4
    pop ecx
    imul eax, ecx
    pop ecx
    sub eax, ecx
    pop ecx
    sub eax, ecx
    pop ecx
    imul eax, ecx
    push eax
    mov eax, 3
    push eax
    mov eax, 6
    push eax
    mov eax, 2
    pop ecx
    add eax, ecx
    pop ecx
    sub eax, ecx
    push eax
    mov eax, 1
    push eax
    mov eax, 1
    pop ecx
    add eax, ecx
    cmp eax, 0
    mov eax, 0
    sete al
    pop ecx
    add eax, ecx
    pop ecx
    add eax, ecx
    push eax
    mov eax, [ebp+-4]
    push eax
    mov eax, 3
    pop ecx
    add eax, ecx
    mov [ebp+-4], eax
    mov eax, 0
    push eax
    mov eax, 1
    mov [ebp+-8], eax
    mov eax, [ebp+-4]
    push eax
    mov eax, [ebp+-8]
    pop ecx
    add eax, ecx
    mov esp, ebp
    pop ebp
    ret
    add esp, 8
    mov esp, ebp
    pop ebp
    mov eax, 0
    ret

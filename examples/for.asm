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
    mov eax, 1
    push eax
    mov eax, 5
    push eax
    mov eax, 0
    mov [ebp+-4], eax
_forBegin1:
    mov eax, [ebp+-4]
    push eax
    mov eax, 5
    pop ecx
    cmp ecx, eax
    mov eax, 0
    setle al
    cmp eax, 0
    je _forEnd1
    mov eax, [ebp+-8]
    push eax
    mov eax, 1
    pop ecx
    add eax, ecx
    mov [ebp+-8], eax
    add esp, 0
    mov eax, [ebp+-4]
    push eax
    mov eax, 1
    pop ecx
    add eax, ecx
    mov [ebp+-4], eax
    jmp _forBegin1
_forEnd1:
    mov eax, [ebp+-8]
    mov esp, ebp
    pop ebp
    ret
    add esp, 8
    mov esp, ebp
    pop ebp
    mov eax, 0
    ret

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
    mov eax, 0
    push eax
_whileBegin1:
    mov eax, 1
    cmp eax, 0
    je _whileEnd1
    mov eax, [ebp+-4]
    push eax
    mov eax, 1
    pop ecx
    add eax, ecx
    mov [ebp+-4], eax
    mov eax, [ebp+-4]
    push eax
    mov eax, 5
    pop ecx
    cmp ecx, eax
    mov eax, 0
    sete al
    cmp eax, 0
    je _else1
    jmp _whileBegin1
    jmp _elseEnd1
_else1:
_elseEnd1:
    mov eax, [ebp+-8]
    push eax
    mov eax, 1
    pop ecx
    add eax, ecx
    mov [ebp+-8], eax
    mov eax, [ebp+-4]
    push eax
    mov eax, 10
    pop ecx
    cmp ecx, eax
    mov eax, 0
    sete al
    cmp eax, 0
    je _else2
    jmp _whileEnd1
    jmp _elseEnd2
_else2:
_elseEnd2:
    add esp, 0
    jmp _whileBegin1
_whileEnd1:
    mov eax, [ebp+-8]
    mov esp, ebp
    pop ebp
    ret
    add esp, 8
    mov esp, ebp
    pop ebp
    mov eax, 0
    ret

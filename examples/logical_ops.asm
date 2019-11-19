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
    mov eax, 5
    push eax
    mov eax, 4
    pop ecx
    cmp ecx, eax
    mov eax, 0
    sete al
    cmp eax, 0
    je _orRight2
    mov eax, 1
    jmp _orEnd2
_orRight2:
    mov eax, 5
    push eax
    mov eax, 5
    pop ecx
    cmp ecx, eax
    mov eax, 0
    sete al
    cmp eax, 0
    mov eax, 0
    setne al
_orEnd2:
    cmp eax, 0
    je _orRight1
    mov eax, 1
    jmp _orEnd1
_orRight1:
    mov eax, 3
    push eax
    mov eax, 3
    pop ecx
    cmp ecx, eax
    mov eax, 0
    setne al
    cmp eax, 0
    mov eax, 0
    setne al
_orEnd1:
    cmp eax, 0
    jne _andRight5
    jmp _andEnd5
_andRight5:
    mov eax, 5
    push eax
    mov eax, 4
    pop ecx
    cmp ecx, eax
    mov eax, 0
    setg al
    cmp eax, 0
    mov eax, 0
    setne al
_andEnd5:
    cmp eax, 0
    jne _andRight4
    jmp _andEnd4
_andRight4:
    mov eax, 5
    push eax
    mov eax, 5
    pop ecx
    cmp ecx, eax
    mov eax, 0
    setge al
    cmp eax, 0
    mov eax, 0
    setne al
_andEnd4:
    cmp eax, 0
    jne _andRight3
    jmp _andEnd3
_andRight3:
    mov eax, 4
    push eax
    mov eax, 5
    pop ecx
    cmp ecx, eax
    mov eax, 0
    setl al
    cmp eax, 0
    mov eax, 0
    setne al
_andEnd3:
    cmp eax, 0
    jne _andRight2
    jmp _andEnd2
_andRight2:
    mov eax, 5
    push eax
    mov eax, 5
    pop ecx
    cmp ecx, eax
    mov eax, 0
    setle al
    cmp eax, 0
    mov eax, 0
    setne al
_andEnd2:
    cmp eax, 0
    jne _andRight1
    jmp _andEnd1
_andRight1:
    mov eax, 10
    push eax
    mov eax, 5
    pop ecx
    cmp ecx, eax
    mov eax, 0
    setne al
    cmp eax, 0
    mov eax, 0
    setne al
_andEnd1:
    mov esp, ebp
    pop ebp
    ret
    add esp, 0
    mov esp, ebp
    pop ebp
    mov eax, 0
    ret

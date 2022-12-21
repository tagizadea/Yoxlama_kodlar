; Constants
MOD equ 1000000007

section .data

; Matrix structure to store matrix values
matrix struc
    a dd ?
    b dd ?
    c dd ?
    d dd ?
matrix ends

section .text

; Function to multiply two matrices
global mul
mul:
    push ebp
    mov ebp, esp

    ; Save matrix a and b to the stack
    push dword [ebp+8]
    push dword [ebp+12]

    ; Load matrix a and b from the stack
    mov eax, dword [esp+4]
    mov ebx, dword [esp]

    ; Calculate c.a = a.a * b.a + a.b * b.c
    mov ecx, dword [eax+matrix.a]
    mul dword [ebx+matrix.c]
    add ecx, edx
    mov dword [esp+matrix.a], ecx

    ; Calculate c.b = a.a * b.b + a.b * b.d
    mov ecx, dword [eax+matrix.a]
    mul dword [ebx+matrix.d]
    add ecx, edx
    mov dword [esp+matrix.b], ecx

    ; Calculate c.c = a.c * b.a + a.d * b.c
    mov ecx, dword [eax+matrix.c]
    mul dword [ebx+matrix.c]
    add ecx, edx
    mov dword [esp+matrix.c], ecx

    ; Calculate c.d = a.c * b.b + a.d * b.d
    mov ecx, dword [eax+matrix.c]
    mul dword [ebx+matrix.d]
    add ecx, edx
    mov dword [esp+matrix.d], ecx

    ; Return result
    mov eax, esp
    leave
    ret 8

; Function to find the nth Fibonacci number using ternary search
global fib
fib:
    push ebp
    mov ebp, esp

    ; Save n to the stack
    push dword [ebp+8]

    ; Load n from the stack
    mov eax, dword [esp]

    ; Base case: if n is 0, return 0
    cmp eax, 0
    jne .not_base_case
    mov eax, 0
    leave
    ret 4

.not_base_case:
    ; Initialize matrix to store Fibonacci values
    mov dword [esp+matrix.a], 1
    mov dword [esp+matrix.b], 1
    mov dword [esp+matrix.c], 1
    mov dword [esp+matrix.d], 0

    ; Initialize matrix to store power of mat
    mov dword [esp+8+matrix.a], 1
    mov dword [esp+8+matrix.b], 0
    mov dword [esp+8+matrix

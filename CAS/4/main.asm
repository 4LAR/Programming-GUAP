.model small
.stack 100h
.data
message db 'Hello World',13,10,'$' ; для функции 9h прерывания 21h конец строки должен быть обозначен как символ '$', а не 0
.code
start:
    mov ax, @data
    mov ds, ax

    mov dx, offset message
    mov ah, 09h
    int 21h

    mov ah, 4Ch
    int 21h
end start

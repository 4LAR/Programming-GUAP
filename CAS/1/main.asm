; Простая программа:
; (A-1)*2 and (C*2+B)
; ответ будет записан в A3

	.global	 _c_int00

.data
; varray1: .int 12, 1, 2

A .set 10
B .set 20
C .set 30

_c_int00:

.text

	; vMVKL .S array1, A4 ;загружаем адрес массива1 в A4
	; MVKH .S array1, A4

	MVK .S A, A0 		; A = 10
	MVK .S B, A1 		; B = 20
	MVK .S C, A2 		; C = 30

	SUB .L1 A0, 1, A0	; (A - 1) => A
	MPY .M1 A0, 2, A0	; (A * 2) => A

	MPY .M1 A2, 2, A2	; (C * 2) => C
	ADD .L1 A2, A1, A2	; (C + B) => C

	AND .L1 A0, A2, A3	; (A and C) => OUT

	NOP

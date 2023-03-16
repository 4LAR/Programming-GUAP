; Простая программа:
; (A-1)*2 and (C*2+B)
; ответ будет записан в A8

	.global	 _c_int00

; переменные, маски... хз в общем
.data
vareble_A: .ubyte 10
vareble_B: .ubyte 20
vareble_C: .ubyte 30

; константы (не используются)
A .set 10
B .set 20
C .set 30

_c_int00:
; код
.text
	; записываем адреса в регистры
	MVK .S vareble_A, A0 		; (A0)A = 10
	MVK .S vareble_B, A1 		; (A1)B = 20
	MVK .S vareble_C, A2 		; (A2)C = 30

	; достаём из адресов значения
	LDB .D1 *A0, A3				; A3 = A
	NOP 4
	LDB .D1 *A1, A4				; A4 = B
	NOP 4
	LDB .D1 *A2, A5				; A5 = C
	NOP 4

	; (A-1)*2
	SUB .L1 A3, 1, A6	; (A3 - 1) => A6
	MPY .M1 A6, 2, A6	; (A6 * 2) => A6
	NOP 2

	; (C*2+B)
	MPY .M1 A5, 2, A7	; (A5 * 2) => A7
	NOP 2
	ADD .L1 A4, A7, A7	; (A7 + A4) => A7

	; (A-1)*2 and (C*2+B)
	AND .L1 A6, A7, A8	; (A6 and C7) => A8(OUT)

	NOP

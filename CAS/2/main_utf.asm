; Разработать программу подсчета суммы элементов массива у которых нечетные
; индексы.

	.global	 _c_int00
;///////////////////////////////////////
.data ;секция данных

array: .ubyte 1, 2, 3, 4, 5
sum: .ubyte 0
size .set 5
;///////////////////////////////////////
_c_int00:
.text ;секция кода

	;Инициализация:
	MVKL .S1 array, A3 ;загружаем адрес массива1 в A3
	MVKH .S1 array, A3
	MVK .S1 size, A2
	MVK .S1 sum, A4

	LDB .D1 *A4, A0
	NOP 4

LOOP:
	SUB .L1 A2, 1, A2
	[!A2] B .S1 EXIT
	NOP 5
	SHR .S1 A2, 1, A1
	MPY .M1 A1, 2, A1
	NOP 2
	SUB .L1 A2, A1, A1
	[!A1] B .S1 LOOP
	NOP 5

	LDB .D1 *A3[A2], A4
	NOP 4
	ADD .L1 A0, A4, A0

	[A2] B .S1 LOOP ;переход если A2 <> 0
	NOP 5

EXIT:

TITLE CHANGE
;Программа заменяет строчные буквы заглавными в символьной
;строке и выводит на экран преобразованную строку на экран
;Входные параметры:
;текстовая переменная MYTEXT

.MODEL SMALL
.STACK 256
.DATA
MYTEXT DB 'Programming in GUAP is the best', 13, 10, '$' ;
;MYTEXT DB 'Our NativeTown', 13, 10, '$' ; объявляем текстовую
ln = ($ - MYTEXT)-3 ;создание константы счетчика
;весь текс - сам текст - минус доп 3 символа
.CODE
;---------------------- процедура коррекции кода символа --------------
COR PROC NEAR
NOP
AND AH, 0DFh
MOV [BX], AH
RET
COR ENDP
;-----------------------------основная программа----------------------------
Start:
MOV AX, @DATA
MOV DS, AX

LEA DX, MYTEXT ;вывести переменную
MOV AH, 09h ;MYTEXT
INT 21h ;на экран

XOR AX, AX
LEA BX, MYTEXT
MOV CX, ln ;загрузить счетчик циклов
;---------------------------------начало тела цикла---------------------------
MT1: MOV AH, [BX]
CMP AH, 61h
JB MT2
CMP AH, 7Ah
JA MT2
CALL COR
MT2: INC BX
;------------------------конец тела цикла---------------------------------------
LOOP MT1 ;повторить цикл, если (CX) ≠0
LEA DX, MYTEXT ;вывести переменную
MOV AH, 09h ;MYTEXT
INT 21h ;на экран
NOP ;холостая команда
MOV AX, 4C00h ;завершить
INT 21h ;программу
END Start

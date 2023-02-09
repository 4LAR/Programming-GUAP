
; 7 вариант
; 7.1 элемент A
; 7.2 элемент D
; 7.3 список (D)
; 7.4 список (A B C)
; 7.5 список ( A (D) (C))
; 7.6 список (D A B)

(write (car '( A ((B) (C) ) (D) (K) L) ))(terpri) ; A
(write (caaddr '( A ((B) (C) ) (D) (K) L) ))(terpri) ; D
(write (caddr '( A ((B) (C) ) (D) (K) L) ))(terpri) ; (D)

;(write (car '( A ((B) (C) ) (D) (K) L) ))(terpri)
;(write (caaadr '( A ((B) (C) ) (D) (K) L) ))(terpri)
;(write (car(cadadr '( A ((B) (C) ) (D) (K) L) )))(terpri)

; (A B C)
(write
  (cons (car '( A ((B) (C) ) (D) (K) L) )
  (cons (caaadr '( A ((B) (C) ) (D) (K) L) )
  (cons (car(cadadr '( A ((B) (C) ) (D) (K) L) )) nil)))
)(terpri)

; (A (D) (C))
(write
  (cons (car '( A ((B) (C) ) (D) (K) L) )
  (cons (caddr '( A ((B) (C) ) (D) (K) L) )
  (cons (cadadr '( A ((B) (C) ) (D) (K) L) ) nil)))
)(terpri)

; (D A B)
(write
  (cons (caaddr '( A ((B) (C) ) (D) (K) L) )
  (cons (car '( A ((B) (C) ) (D) (K) L) )
  (cons (caaadr '( A ((B) (C) ) (D) (K) L) ) nil)))
)(terpri)

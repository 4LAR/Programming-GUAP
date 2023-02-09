;Разработать функцию, увеличивающую в исходном списке нечетные
;элементы (по значению) на 1 и уменьшающую четные на 2.
;Например:
;Вход: (1 2 3 4 5 6 7 8 9).
;Выход: (2 0 4 2 6 4 6 6 10).

;(defun del-even (lst)
;  (cond ((< (length lst) 2) lst)
;        (t (cons (car lst) (del-even (cddr lst))))))
;(terpri)
;(write (del-even (list 1 2 3 4 5 6 7 8 9)))
;(terpri)

(defun isEven ( num )(zerop(logand num 1)))

(defun transform (lst)
  (write-line "loh")
  (cond ((< (length lst) 2) lst)

    (t (cons (car lst) (transform (cddr lst))))
  )
)

(write (transform (list 1 2 3 4 5 6 7 8)))

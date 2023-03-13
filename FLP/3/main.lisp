; 19 вариант => 3 вариант
; Необходимо расставить на шахматной доске коней и определить, какое
; наибольшее число таких фигур можно расставить на доске 8х8 (конь бьёт
; любую фигуру находящуюся через две клетки по горизонтали или вертикали и
; одну клетку по диагонали)

(defun setHorse (sizeX sizeY currX currY arr tick)
  (setq currX (+ currX 1))
  (cond (
    (eq sizeX currX)
    (setq currX 0)
    (setq currY (+ currY 1))
    (terpri)
  )
  (T (setq tick (not tick)))
  )

  (cond (
      (eq sizeY currY)
      nil
    )
    (T
      ;(write (list currX currY tick))(terpri)
      (cond (
        (not tick)
        ;(setq arr (cons arr (list currX currY)))
        (write 1)
        (cons (list currX currY) (setHorse sizeX sizeY currX currY arr tick))
      )
      (T
        (write 0)
        (setHorse sizeX sizeY currX currY arr tick)
      ))

    )
  )

)

(defun horseInTable (sizeX sizeY)
  (write 0)
  (setHorse sizeX sizeY 0 0 () T)
)

(terpri)
(setq out (horseInTable 8 8))
(write-line "OUT: ")(write out)(terpri)
(write-line "OUT LENGTH: ")(write (length out))(terpri)
(terpri)

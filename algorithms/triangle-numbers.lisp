;; I constructed a triangle of sum(x,y,z) mod 2 for 16 rows - a pattern becomes apparent
;; For all odd rows, the first even number is the second one
;; For the even rows, the first even number alternates between the third and fourth position

(defun first-even (row)
  (if (= (mod row 2) 0)
	  (if (= (mod row 4) 0) 3 4)
	2))

(dotimes (times (read))
  (format t "~a~%" (first-even (read))))

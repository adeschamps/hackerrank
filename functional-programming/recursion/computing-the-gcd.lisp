(defun my-gcd (x y)
  (cond
   ((= x y) x)
   ((> x y) (gcd (- x y) y))
   (t       (gcd (- y x) x))))


(format t "~a~%" (my-gcd (read) (read)))

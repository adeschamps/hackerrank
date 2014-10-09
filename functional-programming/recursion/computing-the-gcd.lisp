(defun my-gcd (x y)
  (cond
   ((= x y) x)
   ((> x y) (my-gcd (- x y) y))
   (t       (my-gcd (- y x) x))))


(format t "~a~%" (my-gcd (read) (read)))

(defun comb (n r)
  (cond ((= n 0) 1)
		((= r 0) 1)
		((= r n) 1)
		(t (+ (comb (1- n) (1- r)) (comb (1- n) r)))))

(dotimes (row (read))
  (loop for i from 0 to row
		do (format t "~a " (comb row i)))
  (format t "~%"))

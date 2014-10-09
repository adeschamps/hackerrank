(defun count-sums (goal power min)
  (cond
   ((= goal 0) 1)
   ((< goal 0) 0)
   ((> (expt min power) goal) 0)
   (t (+ (count-sums goal power (1+ min))
		 (count-sums (- goal (expt min power)) power (1+ min))))))

(format t "~a~%" (count-sums (read) (read) 1))

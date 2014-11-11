(defun e (x)
  (do ((i 1 (1+ i))
	   (pow 1 (* pow x))
	   (fac 1 (* fac i))
	   (sum 0 (+ sum (/ pow fac))))
	  ((< 10 i) sum)))

(dotimes (times (read)) (format t "~,4f~%" (e (read))))

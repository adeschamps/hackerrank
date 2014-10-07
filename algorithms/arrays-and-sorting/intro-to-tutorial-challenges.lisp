(format t "~a~%"
		(let ((V (read)) (n (read)))
		  (do ((i 0 (1+ i)))
			  ((= V (read)) i))))

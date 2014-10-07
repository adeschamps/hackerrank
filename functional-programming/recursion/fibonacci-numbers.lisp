(format t "~a~%"
		(let ((N (read)))
		  (do ((i 1 (1+ i))
			   (next 1 (+ next cur))
			   (cur 0 next))
			  ((= i N) cur))))

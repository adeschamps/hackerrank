(dotimes (times (read))
  (format t "~a~%"
		  (let ((k (read)))
			(* (truncate (/ k 2))
			   (+ (truncate (/ k 2)) (if (= (mod k 2) 0) 0 1))))))

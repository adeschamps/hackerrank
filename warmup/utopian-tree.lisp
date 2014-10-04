(dotimes (cases (read))
  (let ((n (read)))
	(format t "~a~%" (- (expt 2 (truncate (1+ (/ (1+ n) 2))))
						(if (= (mod n 2) 0) 1 2)))))

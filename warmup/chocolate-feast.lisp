(dotimes (times (read))
  (format t "~a~%"
		  (let ((n (read)) (c (read)) (m (read)))
			(let ((initial (truncate (/ n c))))
			  (+ initial
				 (do ((wrappers initial (+ (mod wrappers m) (truncate (/ wrappers m))))
					  (extras 0 (+ extras (truncate (/ wrappers m)))))
					 ((< wrappers m) extras)))))))

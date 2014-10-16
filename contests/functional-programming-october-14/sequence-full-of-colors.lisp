(defun full-of-colors (seq)
  (setq r-minus-g 0)
  (setq y-minus-b 0)
  (loop for ball across seq do
		(cond
		 ((string= ball "R") (setq r-minus-g (1+ r-minus-g)))
		 ((string= ball "G") (setq r-minus-g (1- r-minus-g)))
		 ((string= ball "Y") (setq y-minus-b (1+ y-minus-b)))
		 ((string= ball "B") (setq y-minus-b (1- y-minus-b))))
		(when (not (or (<= -1 r-minus-g 1)
					   (<= -1 y-minus-b 1)))
			(return-from full-of-colors nil)))
  (return-from full-of-colors (and (= r-minus-g 0) (= y-minus-b 0))))

(dotimes (times (read))
  (format t "~a~%"
		  (if (full-of-colors (read-line))
			  "True" "False")))

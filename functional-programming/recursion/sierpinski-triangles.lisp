;; Prints a row of a solid triangle
(defun triangle-row (size row)
  (loop for i from (1+ row) below size do (format t "_"))
  (loop for i from 1 to (1+ (* 2 row)) do (format t "1"))
  (loop for i from (1+ row) below size do (format t "_")))

;; Prints a row of a sierpinski triangle
(defun sierpinski-row (size row depth)
  (if (= depth 0)
	  (triangle-row size row)
	(if (< row (/ size 2))
		   (progn ;; Top half: print half space, then row of smaller triangle, then half space
			 (dotimes (n (/ size 2)) (format t "_"))
			 (sierpinski-row (/ size 2) row (1- depth))
			 (dotimes (n (/ size 2)) (format t "_")))
		   (progn ;; Bottom half: print row of smaller triangle twice
			 (sierpinski-row (/ size 2) (- row (/ size 2)) (1- depth))
			 (format t "_")
			 (sierpinski-row (/ size 2) (- row (/ size 2)) (1- depth))))))

;; Prints the entire triangle of 2^size rows
(defun sierpinski-triangle (size depth)
  (let ((s (expt 2 size)))
	(dotimes (i s)
	  (sierpinski-row s i depth)
	  (format t "~%"))))

;; The challenge called for a 32 row triangle: size log_2(32) = 5
(sierpinski-triangle (read) (read))

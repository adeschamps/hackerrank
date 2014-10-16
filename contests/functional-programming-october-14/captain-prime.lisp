(defun has-0 (id)
  (do ((n id (floor (/ n 10))))
	  ((= n 0) nil)
	(when (= (mod n 10) 0) (return-from has-0 t))))

(defun prime (n)
  (when (= n 1) (return-from prime nil))
  (loop for i from 2 to (sqrt n) do
		(when (= 0 (mod n i)) (return-from prime nil)))
  t)

(defun chop-left (n)
  (mod n (expt 10 (floor (log n 10)))))

(defun left-eligible (id)
  (do ((n id (chop-left n)))
	  ((= 0 n) t)
	(when (not (prime n)) (return-from left-eligible nil))))

(defun right-eligible (id)
  (do ((n id (floor (/ n 10))))
	  ((= 0 n) t)
	(when (not (prime n)) (return-from right-eligible nil))))

(defun assignment (id)
  (when (has-0 id) (return-from assignment 'DEAD))
  (let ((l (left-eligible id))
		(r (right-eligible id)))
	(cond
	 ((and l r) 'CENTRAL)
	 (l         'LEFT)
	 (r         'RIGHT)
	 (t         'DEAD))))

(dotimes (person (read))
  (format t "~a~%" (assignment (read))))

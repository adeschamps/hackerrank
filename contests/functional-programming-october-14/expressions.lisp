(defun read-list ()
  (loop for i from 1 to (read) collecting (read)))

(defun make-graph (numbers target)
  ;; Construct an array (length numbers) long and target [in this case, 101] high
  (setq graph (make-array (list (length numbers) target) :initial-element nil))

  ;; For each remaining number in the list, find the values that are reachable by each operation
  ;; The first value is reachable by the implicit add operation, represented as nil
  (setf (aref graph 0 (car numbers)) (list nil nil))
  (loop for number in (cdr numbers)
		for i from 1 to (length numbers)
		do
		(loop for j from 0 below target do
			  (let ((source (aref graph (1- i) j)))
				(when (not (eq source nil))
				  (progn
					(setf (aref graph i (mod (+ j number) target))
						  (list j '+))
					(setf (aref graph i (mod (- j number) target))
						  (list j '-))
					(setf (aref graph i (mod (* j number) target))
						  (list j '*)))))))
  graph)

(defun find-solution (graph)
  (do ((index
		(1- (first (array-dimensions graph)))
		(1- index))
	   (dest
		0
		(first (aref graph index dest)))
	   (solution
		nil
		(cons (second (aref graph index dest)) solution)))
	  ((= index 0) solution)))

(defun print-expression (list target)
  (format t "~a" (car list))
  (loop for num in (cdr list)
		for op  in (find-solution (make-graph list target))
		do (format t "~a~a" op num))
  (format t "~%"))

(print-expression (read-list) 101)

;; Technically correct, but runs in O(2^n)

(defun read-list ()
  (loop for i from 1 to (read) collecting (read)))

(defun calc (query list)
  (mod
   (cond
	((= (length list) 0) 0)
	((= query 0) 0)
	((= query 1) (+ (car list) (calc query (cdr list))))
	(t (+ (* (car list) (calc (1- query) (cdr list)))
		  (calc query (cdr list)))))
   100003))


(let ((list (read-list)))
  (dotimes (times (read))
	(format t "~a~%" (calc (read) list))))

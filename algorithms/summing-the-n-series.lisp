;; Consider the expression T_n = n^2 - (n-1)^2
;; The trick is that the n^2 term for one T is cancelled out by the (n-1)^2 term for the next T
;; Thus, the expression SUM(T_n) = n^2

(dotimes (times (read))
  (format t "~a~%" (mod (expt (read) 2) (+ (expt 10 9) 7))))

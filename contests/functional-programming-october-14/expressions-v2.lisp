;; Tokenizer

(defun parse-float (str) (with-input-from-string (in str) (read in)))

(defun parse-num ()
  (parse-float
   (coerce
	(do ((chars nil (cons (read-char) chars)))
		((not (is-digit (peek-char t t nil))) (reverse chars)))
	'string)))

(setq *current-token-p* nil)
(setq *current-token* nil)

(defun read-token ()
  (if *current-token-p*
	  (progn (setq *current-token-p* nil)
			 *current-token*)
	(cond
	 ((is-digit (peek-char t t nil)) (parse-num))
	 (t                              (read-char t nil)))))

(defun peek-token ()
  (if *current-token-p* *current-token*
	(progn (setq *current-token* (read-token))
		   (setq *current-token-p* t)
		   *current-token*)))

;; Various predicates

(defun is-digit (token) (and (typep token 'character) (or (char<= #\0 token #\9) (char= token #\.))))

(defun is-num        (token) (typep token 'number))
(defun is-plus       (token) (and (typep token 'character) (string= token #\+)))
(defun is-minus      (token) (and (typep token 'character) (string= token #\-)))
(defun is-mult       (token) (and (typep token 'character) (string= token #\*)))
(defun is-div        (token) (and (typep token 'character) (string= token #\/)))
(defun is-open-paren (token) (and (typep token 'character) (string= token #\()))

;; Grammar

(defun eval-expression ()
  (let ((term (eval-term)))
	(cond
	 ((is-plus  (peek-token)) (progn (read-token) (+ term (eval-expression))))
	 ((is-minus (peek-token)) (progn (read-token) (- term (eval-expression))))
	 (t                                              term))))

(defun eval-term ()
  (let ((factor (eval-factor)))
	(cond
	 ((is-mult (peek-token)) (progn (read-token) (* factor (eval-term))))
	 ((is-div  (peek-token)) (progn (read-token) (/ factor (eval-term))))
	 (t                                             factor))))

(defun eval-factor ()
  (let ((token (read-token)))
	(cond
	 ((is-num        token)     token)
	 ((is-plus       token)    (eval-factor))
	 ((is-minus      token) (- (eval-factor)))
	 ((is-open-paren token) (progn (let ((expression (eval-expression))) (read-token) expression))))))

(format t "~a~%" (mod (eval-expression) 1000000007))

;; I constructed a triangle of sum(x,y,z) mod 2 for 16 rows - a pattern becomes apparent
;; For all odd rows, the first even number is the second one
;; For the even rows, the first even number alternates between the third and fourth position

;;  1 -                1                - 00
;;  2 -               111               - 00
;;  3 -              10101              - 2
;;  4 -             1101011             - 3
;;  5 -            100010001            - 2
;;  6 -           11101110111           - 4
;;  7 -          1010001000101          - 2
;;  8 -         110110111011011         - 3
;;  9 -        10000000100000001        - 2
;; 10 -       1110000011100000111       - 4
;; 11 -      101010001010100010101      - 2
;; 12 -     11010110110101101101011     - 3
;; 13 -    1000100000001000000010001    - 2
;; 14 -   111011100000111000001110111   - 4
;; 15 -  10100010100010101000101000101  - 2
;; 16 - 1101101101101101011011011011011 - 3

(defun first-even (row)
  (if (= (mod row 2) 0)
	  (if (= (mod row 4) 0) 3 4)
	2))

(dotimes (times (read))
  (format t "~a~%" (first-even (read))))

(define (cont n c) (if (= c 0) (+ 1 (- n 1)) (+ 1 (/ (- n 1)(+ 1 (cont n (- c 1)))))))
;(/ (+ 1 (cont 5 100)) 2)
(cont 5 300)

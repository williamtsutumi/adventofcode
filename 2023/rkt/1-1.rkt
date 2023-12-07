#lang racket
(require racket/port)
(require readline/readline)

(define (charIsNumber c)
  (if (string<=? "0" c)
    (string<=? c "9")
    (#f)))

(define (solve in i)
  (cond
    [(charIsNumber (substring ((in) (i) (+ i 1)))) (display (substring ((in) (i) (+ i 1))))]))

(solve "1" 0)

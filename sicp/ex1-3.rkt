#lang sicp

(define (square x) (* x x))

(define (sum-of-squares x y) (+ (square x) (square y)))

(define (fun a b c)
  (cond ((and (<= a b) (<= a c)) (sum-of-squares b c))
        ((and (<= b a) (<= b c)) (sum-of-squares a c))
        (else sum-of-squares a b)))

(= (fun 1 2 3) (sum-of-squares 2 3))
(= (fun 3 5 6) (sum-of-squares 5 6))
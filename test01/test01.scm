;csc test01.scm misc.c -L"-lgmp" -L "-lmpfr" -o test01
#> 
#include "misc.h"
<#

(import 
    (chicken foreign)    
    (chicken base))


;(define calc_one_operand (foreign-lambda int "calc_one_operand" scheme-object double (c-pointer c-string*)))
(define calc_two_operand (foreign-lambda int "calc_two_operand" scheme-object double double (c-pointer c-string*)))



; (define (calc_one type one)
;   (let-location ((out c-string*)) ; out will be a location that frees the memory when dereferenced
;     (let ((rv (calc_one_operand type one (location out))))
;       (if (eqv? rv 0)          
;           (string->number out)
;            "error"))))

(define (calc_two type one two)
  (let-location ((out c-string*)) ; out will be a location that frees the memory when dereferenced
    (let ((rv (calc_two_operand type one two (location out))))
      (if (eqv? rv 0)          
          (string->number out)
           "error"))))

(define a 3)
(define b 2)
(newline)
(display (calc_two 'add a b))
; (newline)
; (display (calc_two 'subtract a b))
; (newline)
; (display (calc_two 'multiply a b))
; (newline)
; (display (calc_two 'divide a b))
; (newline)
; (display (calc_two 'power 4 5))
; (newline)

(newline)
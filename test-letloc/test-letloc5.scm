#>
//#include "chicken.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gmp.h>
#include <mpfr.h>
//#include "ws.h"
#include <assert.h>
#include <stdbool.h>



//csc test-letloc3.scm -L"-lgmp" -L "-lmpfr" -o test3


int calc_two_digits(int type,double in1, double in2, char **out);
static C_word k;

int calc_two_digits(int type,double in1, double in2, char **out) {
    int ret;
   	mpfr_t a,b,result;
    mpfr_init2(a, 200);               // 256-bit precision (~77 decimal digits)
    mpfr_init2(b, 200); 
    mpfr_init2(result, 200); 
    mpfr_set_d (a, in1, MPFR_RNDN);
    mpfr_set_d (b, in2, MPFR_RNDN); 
    switch (type) {
    case 0:
        mpfr_add (result, a, b, MPFR_RNDN); 
        break;
    case 1:
        mpfr_sub (result, a, b, MPFR_RNDN);  
        break;
    case 2:
        mpfr_mul(result, a, b, MPFR_RNDN);
        break; 
    case 3:
        mpfr_div(result, a, b, MPFR_RNDN);
        break; 
    case 4:
        mpfr_pow(result, a, b, MPFR_RNDN);
        break; 
    default:
        // code to be executed if none of the cases match
  }
      
 	ret = mpfr_asprintf (out, "%.17Rg", result);
    mpfr_clears(a,b,result, NULL);                    // mandatory cleanup
    return 0;
}
<#
 ;(gc)
(import (chicken foreign))

(define (get_fun func)
 ( enum-name->value function func))

    (define function  (make-enum-type 
                  '((add 0)
                    (subtract 1)
                    (multiply 2)
                    (divide 3)
                    (power 4))))

(define calc_two_digits (foreign-lambda int "calc_two_digits" int double double (c-pointer c-string*)))

(define (calc type one two)
  (let-location ((out c-string*)) ; out will be a location that frees the memory when dereferenced
    (let ((rv (calc_two_digits type a b (location out))))
      (if (eqv? rv 0)          
          (string->number out)
           "error"))))

;(display (calc_two_digits))
; (thread-sleep! .1)
;(display result)
;(newline)
(define a 3)
(define b 2)
;(display (get_fun 'multiply));
;(newline)
;(display (get_fun 'divide))
(newline)
(display (calc (get_fun 'add) a b))
(newline)
(display (calc (get_fun 'subtract) a b))
(newline)
(display (calc (get_fun 'multiply) a b))
(newline)
(display (calc (get_fun 'divide) a b))
(newline)
(display (calc (get_fun 'power) a b))
(newline)
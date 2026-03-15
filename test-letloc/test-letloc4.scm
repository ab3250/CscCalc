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
    printf("%d\n",type);
    switch (type) {
    case 0:
        mpfr_mul (result, a, b, MPFR_RNDN); 
        break;
    case 1:
         mpfr_div (result, a, b, MPFR_RNDN);  
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
(define calc_two_digits (foreign-lambda int "calc_two_digits" int double double (c-pointer c-string*)))

(define (calc type one two)
  (let-location ((out c-string*)) ; out will be a location that frees the memory when dereferenced
    (let ((rv (calc_two_digits type a b (location out))))
      (if (eqv? rv 0)          
          (string->number out)
          (error "profile error" rv))))
)

;(display (calc_two_digits))
; (thread-sleep! .1)
;(display result)
;(newline)
(define a 1.5)
(define b 2.25)

(display (calc 0 a b))
(newline)
(display (calc 1 a b))
(newline)
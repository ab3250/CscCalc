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


int calc(double in1, double in2, char **out);
static C_word k;

int calc(double in1, double in2, char **out) {
	char *str;
    int ret;
   	mpfr_t a,b,result;
    mpfr_init2(a, 200);               // 256-bit precision (~77 decimal digits)
    mpfr_init2(b, 200); 
    mpfr_init2(result, 200); 
    mpfr_set_d (a, in1, MPFR_RNDN);
    mpfr_set_d (b, in2, MPFR_RNDN); 
    mpfr_mul (result, a, b, MPFR_RNDN);   
 	  ret = mpfr_asprintf (out, "%.17Rg", result);
    mpfr_clears(a,b,result, NULL);                    // mandatory cleanup
    return 0;
}

<#
 ;(gc)
(define calc (foreign-lambda int "calc" double double (c-pointer c-string*)))


;(display (calc))
; (thread-sleep! .1)
;(display result)
;(newline)
(define a 1.22231)
(define b 2.23345553)
(let-location ((out c-string*)) ; out will be a location that frees the memory when dereferenced
  (let ((rv (calc  a b (location out))))
    (if (eqv? rv 0)
        ;(print out) ; Access the string here.
        (display (string->number out))
        (error "profile error" rv))))


#>
#include "chicken.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gmp.h>
#include <mpfr.h>
#include <assert.h>
#include <stdbool.h>
int calc(const char *in, char **out);



<#

; (newline)
; (let-location ((out c-string*)) ; out will be a location that frees the memory when dereferenced
;   (let ((rv (calc "hello" (location out))))
;     (if (eqv? rv 0)
;         (print out) ; Access the string here.
;         (error "profile error" rv))))


   ;int profile(const char *in, char **out);
(define calc
  (foreign-lambda* int (((const c-string) in) ((c-pointer c-string*) out ))
  "
    char *str;
    int ret;
   	mpfr_t pi;
    mpfr_init2(pi, 256);               // 256-bit precision (~77 decimal digits)
    mpfr_const_pi(pi, MPFR_RNDN);      // compute π rounded to nearest
	  ret = mpfr_asprintf (out, \"%.100Rg\", pi);   
    mpfr_clear(pi);                    // mandatory cleanup    return 0;
    C_return(0);
    "))

(newline)
(let-location ((out c-string*)) ; out will be a location that frees the memory when dereferenced
  (let ((rv (calc "some input" (location out))))
    (if (eqv? rv 0)
        (display out) ; Access the string here.
        (error "profile error" rv))))

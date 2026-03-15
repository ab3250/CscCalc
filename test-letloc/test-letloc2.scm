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

int calc(const char* in1, const char* in2, char **out);
static C_word k;

int calc( const char* in1, const char* in2, char **out) {
	char *str;
    int ret;
   	mpfr_t a,b,result;
    mpfr_init2(a, 200);               // 256-bit precision (~77 decimal digits)
    mpfr_init2(b, 200); 
    mpfr_init2(result, 200); 
    mpfr_set_str (a, in1, 10, MPFR_RNDN);
    mpfr_set_str (b, in2, 10, MPFR_RNDN); 
    mpfr_mul (result, a, b, MPFR_RNDN);
   // mpfr_const_pi(pi, MPFR_RNDN);      // compute π rounded to nearest
 	ret = mpfr_asprintf (out, "%.10Rg", result);
    mpfr_clears(a,b,result, NULL);                    // mandatory cleanup
    return 0;
}

<#

 
  (define calc (foreign-lambda int "calc" (const c-string) (const c-string) (c-pointer c-string*)))


;(display (calc))
; (thread-sleep! .1)
;(display result)
(newline)
(let-location ((out c-string*)) ; out will be a location that frees the memory when dereferenced
  (let ((rv (calc "1.2" "2.3" (location out))))
    (if (eqv? rv 0)
        (print out) ; Access the string here.
        (error "profile error" rv))))


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
<#

(define calc
  (foreign-lambda* int ((scheme-object func)(double in1)(double in2) ((c-pointer c-string*) out ))
  "
  int ret;
  char* str = C_c_string(C_symbol_name(func));
  mpfr_t a,b,result;
  mpfr_init2(a, 200);               // 256-bit precision (~77 decimal digits)
  mpfr_init2(b, 200); 
  mpfr_init2(result, 200); 
  mpfr_set_d (a, in1, MPFR_RNDN);
  mpfr_set_d (b, in2, MPFR_RNDN);        
  mpfr_add (result, a, b, MPFR_RNDN); 
  ret = mpfr_asprintf (out, \"%.10Rg\", result);   
  mpfr_clears(a,b,result,NULL);                    // mandatory cleanup    return 0;
  C_return(0);
  "))

(newline)
(let-location ((out c-string*)) ; out will be a location that frees the memory when dereferenced
  (let ((rv (calc 'div 2 3 (location out))))
    (if (eqv? rv 0)
        (begin
          (newline)
          (display (string->number out))
          (newline)) ; Access the string here.
        (error "profile error" rv))))

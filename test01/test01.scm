#> //begin-c

//#include "chicken.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gmp.h>
#include <mpfr.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include <misc.h>

//csc test-letloc3.scm -L"-lgmp" -L "-lmpfr" -o test3


    int calc_two_digits(C_word func,double in1, double in2, char **out);

    int calc_two_digits(C_word func,double in1, double in2, char **out) {
        
    int ret;

    char* str = C_c_string(C_symbol_name(func));
    

    

   	mpfr_t a,b,result;
    mpfr_init2(a, 200);               // 256-bit precision (~77 decimal digits)
    mpfr_init2(b, 200); 
    mpfr_init2(result, 200); 
    mpfr_set_d (a, in1, MPFR_RNDN);
    mpfr_set_d (b, in2, MPFR_RNDN);     
    switch (get_switch_value(str)) {
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
    case 5:
        mpfr_exp2 (result, a, MPFR_RNDN);
    case 6:
        //int mpfr_setsign (mpfr t rop, mpfr t op, int s, mpfr rnd t rnd);
        break; 
    case 7:
        //int mpfr_sgn (mpfr t op);
        break;
    default:
        // code to be executed if none of the cases match
  }
      
 	ret = mpfr_asprintf (out, "%.17Rg", result);
    mpfr_clears(a,b,result, NULL);                    // mandatory cleanup
    return 0;
}
<# ;end-c
 ;(gc)
(import 
    (srfi 209)
    (chicken foreign)    
    (chicken base))

(define calc_two_digits (foreign-lambda int "calc_two_digits" scheme-object double double (c-pointer c-string*)))

(define (calc type one two)
  (let-location ((out c-string*)) ; out will be a location that frees the memory when dereferenced
    (let ((rv (calc_two_digits type a b (location out))))
      (if (eqv? rv 0)          
          (string->number out)
           "error"))))

(define a 3)
(define b 2)
(newline)
(display (calc 'add a b))
(newline)
(display (calc 'subtract a b))
(newline)
(display (calc 'multiply a b))
(newline)
(display (calc 'divide a b))
(newline)
(display (calc 'power a b))
(newline)
(define a 2)
(define b 0)
(display (calc 'square a b))
(newline)
;csc let-location-symbol-example.scm -L"-lgmp" -L "-lmpfr" -o let-location-symbol-example
#> 
#include <string.h>
#include "chicken.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gmp.h>
#include <mpfr.h>
#include <assert.h>
#include <stdbool.h>
;int calc(double in1,double in2, char **out);
int profile(const char *in, char **out);
<#

(import 
    (chicken foreign)    
    (chicken base))


; (define calc
;    (foreign-lambda int "profile" (const c-string) (pointer c-string)))

(define calc (foreign-lambda* int ( ((c-pointer c-string) out))
"
strcpy(out,\"Hello\")  

"
))

; (let-location ((out c-string*))
;   (let ((rv (calc "LAMBDA-CALCULUS.ORG" (location out))))
;     (let ((out out))             ; clean up out
;       (if (eqv? rv 0)
;           (print out)
;           (error "profile error" rv)))))

 


(calc )


  (let-location ((out c-string*)) ; out will be a location that frees the memory when dereferenced
    (let ((rv (calc one two (location out))))
      (if (eqv? rv 0)          
          (string->number out)
           "error")))




        ; int ret;
        ; mpfr_t a,b,result;
        ; mpfr_init2(a, 200);               
        ; mpfr_init2(b, 200); 
        ; mpfr_init2(result, 200); 
        ; mpfr_set_d (a, in1, MPFR_RNDN);
        ; mpfr_set_d (b, in2, MPFR_RNDN);     
        ; mpfr_add (result, a, b, MPFR_RNDN);         
        ; ret = mpfr_asprintf (out, \"%.17Rg\", result);
        ; mpfr_clears(a,b,result, NULL);
        ; C_return(ret);     
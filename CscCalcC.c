
#>
#include "chicken.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <gmp.h>
#include <mpfr.h>
//#include "ws.h"
#include <assert.h>
#include <stdbool.h>

char* calc(void);
static C_word k;
char* result;

char* calc(void){
	char *str;
    int ret;
   	mpfr_t pi;
    mpfr_init2(pi, 256);               // 256-bit precision (~77 decimal digits)
    mpfr_const_pi(pi, MPFR_RNDN);      // compute π rounded to nearest
	ret = mpfr_asprintf (&result, "%.100Rg", pi);
    // if (ret > 0) {
    //     printf("%s", str); // Print the allocated string
    //     free(str);         // Free the memory allocated by mpfr_asprintf
    // } else {
    //     printf("Error in formatting.\n");
    // }

//printf("%s", str);

    mpfr_clear(pi);                    // mandatory cleanup
    return result;
}

<#

(import
  (chicken foreign)    
  (chicken base)
  (chicken platform)
  (scheme)
  (srfi 196)
  (srfi 130)
  (srfi 196)
  (srfi 158)  
  (srfi 69)
  (srfi 13)
  (medea)    
  (chicken process-context) srfi-18)
;;csc -embedded CscCalcC.c CscCalc.scm -L"-lgmp" -L "-lmpfr" -o CscCalc


(define-foreign-variable result  c-string "result")
;(define calc
;  (foreign-lambda* (c-pointer char) () "calc();"))

(define calc
  (foreign-lambda c-string* "calc"))


(define-foreign-variable result  c-string "result")
;(define calc
;  (foreign-lambda* (c-pointer char) () "calc();"))

(define calc
  (foreign-lambda c-string* "calc"))


; (define get-c-string
;   (foreign-lambda c-string* "generate_string"))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;


(define (start)
(display (calc))
; (thread-sleep! .1)
;(display result)
(newline)
;(display (grid->string grid2))
; (let loop ()
;   (if (not (= (string-length wsResponse ) 0))
;     (begin 
;       ;(runthis grid2)      
;       (processString wsResponse)
;       ;(print wsResponse)
      
;       ;
;      (clearResponse)
;     )
;   )
;   (thread-sleep! .001)
; (loop))
)


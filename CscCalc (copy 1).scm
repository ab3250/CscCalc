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
 extern char* calc(void);
 extern char* result;
 int get_switch_number(char* sym);
 int get_switch_number(char* sym){

//char* str = "divide";
  const char *func_array[] = {
        "add",
        "subtract",
        "multiply",
        "divide",
        "power"        
  };
  int i=0;
  int j=sizeof(func_array);
  for (i = 0;i<j;++i)   
        {       
            if(strcmp(func_array[i],sym)==0)
                break;       
        }      
        return(i);
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



(define calc
  (foreign-lambda* int ((scheme-object func)(double in1)(double in2) ((c-pointer c-string*) out ))
  "
  //char* str = C_c_string(C_symbol_name(func));
 // C_word *ptrs[] = {str};
  //C_gc_protect (ptrs, 1);

  char* str = C_c_string(func);
  


  //char* str = \"divide\";
  int sw = get_switch_number(str);
 
  int ret;
  //char* str = C_c_string(C_symbol_name(func)); 
  mpfr_t a,b,result;
  mpfr_init2(a, 200);               // 256-bit precision (~77 decimal digits)
  mpfr_init2(b, 200); 
  mpfr_init2(result, 200); 
  mpfr_set_d (a, in1, MPFR_RNDN);
  mpfr_set_d (b, in2, MPFR_RNDN);        
  switch (sw) {
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
            break; 
        case 6:
            //int mpfr_setsign (mpfr t rop, mpfr t op, int s, mpfr rnd t rnd);
            break; 
        case 7:
            //int mpfr_sgn (mpfr t op);
            break;
        default:
            // code to be executed if none of the cases match
        }
  ret = mpfr_asprintf (out, \"%.10Rg\", result);   
  mpfr_clears(a,b,result,NULL);                    // mandatory cleanup    return 0;
  C_return(0);
  "))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

(newline)
(let-location ((out c-string*)) ; out will be a location that frees the memory when dereferenced
  (let ((rv (calc 'add 2 3 (location out))))
    (if (eqv? rv 0)
        (display out) ; Access the string here.
        (error "profile error" rv))))
  (newline)

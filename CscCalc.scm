
;csc CscCalc.scm -L"-lgmp" -L "-lmpfr" -o test3
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
//extern char* calc(void);
//extern char* result; 
////////////////////////////////////

#define VPNULL (void *)NULL
#define NUM_COMMANDS 5
int get_switch_number(char* sym);
int get_switch_number(char* sym){
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
  char* str=strdup(C_c_string(C_symbol_name(func)));  
  str[3] = '\\0'; 
  printf(\"%s\\n\",str);
  int ret;
  mpfr_prec_t prec = 200;
  mpfr_t a,b,result;
  mpfr_init2(a, prec);               // 256-bit precision (~77 decimal digits)
  mpfr_init2(b, prec); 
  mpfr_init2(result, prec); 
  mpfr_set_d (a, in1, MPFR_RNDN);
  mpfr_set_d (b, in2, MPFR_RNDN); 
  mpfr_printf(\"%.10Rg\\n\", a);
  mpfr_printf(\"%.10Rg\\n\", b);
  struct {
    char *sym;    
    int (*selected)(mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t);
  } requested[NUM_COMMANDS] = 
            {{\"add\", mpfr_add},
             {\"sub\", mpfr_sub},
             {\"mul\", mpfr_mul},
             {\"div\", mpfr_div},
             {\"pow\", mpfr_pow}             
             };
  int i = 0;
  while (i < NUM_COMMANDS) {
    if (!strcmp(requested[i].sym, str)) {
      requested[i].selected(result, a, b, MPFR_RNDN);
      break;
    }
        i = i + 1;
    }
   mpfr_printf(\"%.10Rg\\n\", result);
   if(mpfr_nan_p(result)){
      printf(\"error\\n\"); 
   }
   else
   {
    // mpfr_printf(\"%.10Rg\\n\", result);
     ret=mpfr_asprintf (out, \"%.10Rg\", result); 
   }


 // free(str);
 // str = NULL; 
 mpfr_clears (a,b,result,VPNULL); // mandatory cleanup    return 0;           
 C_return(0);
"))
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
(newline)
(let-location ((out c-string*)) ; out will be a location that frees the memory when dereferenced
  (let ((rv (calc 'div 2 3 (location out))))
    (if (eqv? rv 0)
        (display out) ; Access the string here.
        (error "profile error" rv))))
  (newline)

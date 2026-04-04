
#include <string.h>
// #include <stdbool.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

#include <gmp.h>
#include <mpfr.h>

//tern char* calc(void);
#include <stdio.h>
#include <gmp.h>
#define VPNULL (void *)NULL
#define NUM_COMMANDS 5
int main(void) {  

char* str = "pow";
  int ret;
  mpfr_prec_t prec = 200;
  mpfr_t a,b,result;
  mpfr_init2(a, prec);               // 256-bit precision (~77 decimal digits)
  mpfr_init2(b, prec); 
  mpfr_init2(result, prec); 
  mpfr_set_d (a, 5, MPFR_RNDN);
  mpfr_set_d (b, 6, MPFR_RNDN); 

  struct {
    char *sym;    
    int (*selected)(mpfr_ptr, mpfr_srcptr, mpfr_srcptr, mpfr_rnd_t);
} requested[NUM_COMMANDS] = 
            {{"add", mpfr_add},
             {"sub", mpfr_sub},
             {"mul", mpfr_mul},
             {"div", mpfr_div},
             {"pow", mpfr_pow},             
             };
  int i = 0;
  while (i < NUM_COMMANDS) {
    if (!strcmp(requested[i].sym, str)) {
      requested[i].selected(result, a, b, MPFR_RNDN);
      break;
    }
        i = i + 1;
    }
    if(mpfr_nan_p(result)){
      printf("error\n"); 
    }
    else
    {
      mpfr_printf("%.10Rg\n", result);   
    }

// int ret = mpfr_asprintf (out, "%.10Rg", result);   

//mpfr_printf("%.10Rg\n", result);

 mpfr_clears (a,b,result,VPNULL); // mandatory cleanup    return 0;
            
}
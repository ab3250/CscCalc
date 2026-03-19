
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


// int get_switch_value_one_operand(char* func) {
//     const char *func_array[] = {        
//         "square"
//     };

//     int i, j=sizeof(func_array);
//     for (i = 0;i<j;++i)   
//         {       
//             if(strcmp(func_array[i],func)==0)
//                 break;       
//         }   
//    return (i);
// }

// int get_switch_value_two_operand(char* func) {
//     const char *func_array[] = {
//         "add",
//         "subtract",
//         "multiply",
//         "divide",
//         "power"        
//     };

//     int i, j=sizeof(func_array);
//     for (i = 0;i<j;++i)   
//         {       
//             if(strcmp(func_array[i],func)==0)
//                 break;       
//         }   
//    return (i);
// }

int calc_two_operand(C_word func,double in1, double in2, char **out) {
        
    int ret;

    char* str = C_c_string(C_symbol_name(func));
    
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
            if(strcmp(func_array[i],str)==0)
                break;       
        }   
        printf("%s",func_array[i]);

        mpfr_t a,b,result;
        mpfr_init2(a, 200);               // 256-bit precision (~77 decimal digits)
        mpfr_init2(b, 200); 
        mpfr_init2(result, 200); 
        mpfr_set_d (a, in1, MPFR_RNDN);
        mpfr_set_d (b, in2, MPFR_RNDN);     
        switch (1) {
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
      
        ret = mpfr_asprintf (out, "%.17Rg", result);
        mpfr_clears(a,b,result, NULL);     
                // mandatory cleanup
        return 0;
    }


    // int calc_one_operand(C_word func, double in1, char **out) {
        
    // int ret;

    // char* str = C_c_string(C_symbol_name(func));
    

    

    //     mpfr_t a,result;
    //     mpfr_init2(a, 200);               // 256-bit precision (~77 decimal digits)        
    //     mpfr_init2(result, 200); 
    //     mpfr_set_d (a, in1, MPFR_RNDN);
          
    //     switch (get_switch_value_one_operand(str)) {
    //     case 0:
    //         mpfr_exp2 (result, a, MPFR_RNDN);
    //     case 1:
    //         //int mpfr_setsign (mpfr t rop, mpfr t op, int s, mpfr rnd t rnd);
    //         break; 
    //     case 2:
    //         //int mpfr_sgn (mpfr t op);
    //         break;
    //     default:
    //         // code to be executed if none of the cases match
    //     }
      
    //     ret = mpfr_asprintf (out, "%.17Rg", result);
    //     mpfr_clears(a,result, NULL);                    // mandatory cleanup
    //     free(str);
    //     str = NULL;
    //     return 0;
    // }


/* Generated from CscCalc.scm by the CHICKEN compiler
   http://www.call-cc.org
   Version 5.4.0
   linux-unix-gnu-x86-64 [ 64bit dload ptables ]
   command line: CscCalc.scm -output-file test3.c
   uses: eval library
*/
#include "chicken.h"


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


static C_PTABLE_ENTRY *create_ptable(void);
C_noret_decl(C_eval_toplevel)
C_externimport void C_ccall C_eval_toplevel(C_word c,C_word *av) C_noret;
C_noret_decl(C_library_toplevel)
C_externimport void C_ccall C_library_toplevel(C_word c,C_word *av) C_noret;

static C_TLS C_word lf[18];
static double C_possibly_force_alignment;
static C_char C_TLS li0[] C_aligned={C_lihdr(0,0,31),40,99,97,108,99,32,102,117,110,99,51,56,32,105,110,49,51,57,32,105,110,50,52,48,32,111,117,116,52,49,41,0};
static C_char C_TLS li1[] C_aligned={C_lihdr(0,0,10),40,116,111,112,108,101,118,101,108,41,0,0,0,0,0,0};


#define return(x) C_cblock C_r = (C_fix((C_word)(x))); goto C_ret; C_cblockend
C_regparm static C_word C_fcall stub42(C_word C_buf,C_word C_a0,C_word C_a1,C_word C_a2,C_word C_a3){
C_word C_r=C_SCHEME_UNDEFINED,*C_a=(C_word*)C_buf;
C_word func=(C_word )(C_a0);
double in1=(double )C_c_double(C_a1);
double in2=(double )C_c_double(C_a2);
char * *out=(char * *)C_c_pointer_or_null(C_a3);


  //char* str=C_c_string(C_symbol_name(func));
  char* sym=strdup(C_c_string(C_symbol_name(func))); 
  int sw = get_switch_number(sym);
  free(sym);
  sym = NULL; 
 
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
  ret = mpfr_asprintf (out, "%.10Rg", result);   
  mpfr_clears(a,b,result,NULL);                    // mandatory cleanup    return 0;
  C_return(0);
  
C_ret:
#undef return

return C_r;}

C_noret_decl(f_173)
static void C_ccall f_173(C_word c,C_word *av) C_noret;
C_noret_decl(f_176)
static void C_ccall f_176(C_word c,C_word *av) C_noret;
C_noret_decl(f_179)
static void C_ccall f_179(C_word c,C_word *av) C_noret;
C_noret_decl(f_182)
static void C_ccall f_182(C_word c,C_word *av) C_noret;
C_noret_decl(f_185)
static void C_ccall f_185(C_word c,C_word *av) C_noret;
C_noret_decl(f_188)
static void C_ccall f_188(C_word c,C_word *av) C_noret;
C_noret_decl(f_191)
static void C_ccall f_191(C_word c,C_word *av) C_noret;
C_noret_decl(f_194)
static void C_ccall f_194(C_word c,C_word *av) C_noret;
C_noret_decl(f_197)
static void C_ccall f_197(C_word c,C_word *av) C_noret;
C_noret_decl(f_200)
static void C_ccall f_200(C_word c,C_word *av) C_noret;
C_noret_decl(f_202)
static void C_ccall f_202(C_word c,C_word *av) C_noret;
C_noret_decl(f_221)
static void C_ccall f_221(C_word c,C_word *av) C_noret;
C_noret_decl(f_224)
static void C_ccall f_224(C_word c,C_word *av) C_noret;
C_noret_decl(f_227)
static void C_ccall f_227(C_word c,C_word *av) C_noret;
C_noret_decl(f_230)
static void C_ccall f_230(C_word c,C_word *av) C_noret;
C_noret_decl(f_236)
static void C_ccall f_236(C_word c,C_word *av) C_noret;
C_noret_decl(f_246)
static void C_ccall f_246(C_word c,C_word *av) C_noret;
C_noret_decl(f_253)
static void C_ccall f_253(C_word c,C_word *av) C_noret;
C_noret_decl(C_toplevel)
C_externexport void C_ccall C_toplevel(C_word c,C_word *av) C_noret;

/* k171 */
static void C_ccall f_173(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_173,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_176,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_eval_toplevel(2,av2);}}

/* k174 in k171 */
static void C_ccall f_176(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_176,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_179,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("CscCalc.scm:37: chicken.load#load-extension"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[10]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t2;
av2[2]=lf[16];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* k177 in k174 in k171 */
static void C_ccall f_179(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_179,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_182,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("CscCalc.scm:37: chicken.load#load-extension"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[10]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t2;
av2[2]=lf[17];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* k180 in k177 in k174 in k171 */
static void C_ccall f_182(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_182,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_185,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("CscCalc.scm:37: chicken.load#load-extension"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[10]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t2;
av2[2]=lf[16];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* k183 in k180 in k177 in k174 in k171 */
static void C_ccall f_185(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_185,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_188,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("CscCalc.scm:37: chicken.load#load-extension"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[10]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t2;
av2[2]=lf[15];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* k186 in k183 in k180 in k177 in k174 in k171 */
static void C_ccall f_188(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_188,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_191,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("CscCalc.scm:37: chicken.load#load-extension"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[10]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t2;
av2[2]=lf[14];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* k189 in k186 in k183 in k180 in k177 in k174 in k171 */
static void C_ccall f_191(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_191,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_194,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("CscCalc.scm:37: chicken.load#load-extension"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[10]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t2;
av2[2]=lf[13];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* k192 in k189 in k186 in k183 in k180 in k177 in k174 in k171 */
static void C_ccall f_194(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_194,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_197,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("CscCalc.scm:37: chicken.load#load-extension"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[10]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t2;
av2[2]=lf[12];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* k195 in k192 in k189 in k186 in k183 in k180 in k177 in k174 in k171 */
static void C_ccall f_197(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,4)))){
C_save_and_reclaim((void *)f_197,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_200,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("CscCalc.scm:37: chicken.load#load-extension"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[10]);
C_word *av2;
if(c >= 5) {
  av2=av;
} else {
  av2=C_alloc(5);
}
av2[0]=*((C_word*)lf[10]+1);
av2[1]=t2;
av2[2]=lf[11];
av2[3]=C_SCHEME_TRUE;
av2[4]=C_SCHEME_FALSE;
tp(5,av2);}}

/* k198 in k195 in k192 in k189 in k186 in k183 in k180 in k177 in k174 in k171 */
static void C_ccall f_200(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(6,c,6)))){
C_save_and_reclaim((void *)f_200,c,av);}
a=C_alloc(6);
t2=C_mutate((C_word*)lf[0]+1 /* (set! calc ...) */,(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_202,a[2]=((C_word)li0),tmp=(C_word)a,a+=3,tmp));
t3=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_221,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("CscCalc.scm:105: scheme#newline"));
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[2]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[2]+1);
av2[1]=t3;
tp(2,av2);}}

/* calc in k198 in k195 in k192 in k189 in k186 in k183 in k180 in k177 in k174 in k171 */
static void C_ccall f_202(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2=av[2];
C_word t3=av[3];
C_word t4=av[4];
C_word t5=av[5];
C_word t6;
C_word t7;
C_word t8;
C_word t9;
C_word *a;
if(c!=6) C_bad_argc_2(c,6,t0);
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_202,c,av);}
t6=C_i_foreign_flonum_argumentp(t3);
t7=C_i_foreign_flonum_argumentp(t4);
t8=(C_truep(t5)?C_i_foreign_pointer_argumentp(t5):C_SCHEME_FALSE);
t9=t1;{
C_word *av2=av;
av2[0]=t9;
av2[1]=stub42(C_SCHEME_UNDEFINED,t2,t6,t7,t8);
((C_proc)(void*)(*((C_word*)t9+1)))(2,av2);}}

/* k219 in k198 in k195 in k192 in k189 in k186 in k183 in k180 in k177 in k174 in k171 */
static void C_ccall f_221(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(10,c,5)))){
C_save_and_reclaim((void *)f_221,c,av);}
a=C_alloc(10);
t2=C_a_i_bytevector(&a,1,C_fix(1));
t3=(*a=C_CLOSURE_TYPE|3,a[1]=(C_word)f_224,a[2]=((C_word*)t0)[2],a[3]=t2,tmp=(C_word)a,a+=4,tmp);
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_253,a[2]=t3,tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("CscCalc.scm:107: ##sys#make-locative"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[8]);
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[8]+1);
av2[1]=t4;
av2[2]=t2;
av2[3]=C_fix(0);
av2[4]=C_SCHEME_FALSE;
av2[5]=lf[9];
tp(6,av2);}}

/* k222 in k219 in k198 in k195 in k192 in k189 in k186 in k183 in k180 in k177 in k174 in k171 */
static void C_ccall f_224(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word t4;
C_word t5;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(9,c,3)))){
C_save_and_reclaim((void *)f_224,c,av);}
a=C_alloc(9);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_227,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
t3=C_eqp(t1,C_fix(0));
if(C_truep(t3)){
t4=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_246,a[2]=t2,tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("##sys#peek-and-free-c-string"));
t5=*((C_word*)lf[4]+1);{
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=t5;
av2[1]=t4;
av2[2]=C_mpointer(&a,(void*)*((char * *)C_data_pointer(((C_word*)t0)[3])));
av2[3]=C_fix(0);
((C_proc)(void*)(*((C_word*)t5+1)))(4,av2);}}
else{
C_trace(C_text("CscCalc.scm:110: chicken.base#error"));
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[5]+1));
C_word *av2;
if(c >= 4) {
  av2=av;
} else {
  av2=C_alloc(4);
}
av2[0]=*((C_word*)lf[5]+1);
av2[1]=t2;
av2[2]=lf[6];
av2[3]=t1;
tp(4,av2);}}}

/* k225 in k222 in k219 in k198 in k195 in k192 in k189 in k186 in k183 in k180 in k177 in k174 in k171 */
static void C_ccall f_227(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_227,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_230,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("CscCalc.scm:111: scheme#newline"));
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[2]+1));
C_word *av2=av;
av2[0]=*((C_word*)lf[2]+1);
av2[1]=t2;
tp(2,av2);}}

/* k228 in k225 in k222 in k219 in k198 in k195 in k192 in k189 in k186 in k183 in k180 in k177 in k174 in k171 */
static void C_ccall f_230(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void *)f_230,c,av);}
a=C_alloc(3);
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_236,a[2]=((C_word*)t0)[2],tmp=(C_word)a,a+=3,tmp);
C_trace(C_text("chicken.base#implicit-exit-handler"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[1]);
C_word *av2=av;
av2[0]=*((C_word*)lf[1]+1);
av2[1]=t2;
tp(2,av2);}}

/* k234 in k228 in k225 in k222 in k219 in k198 in k195 in k192 in k189 in k186 in k183 in k180 in k177 in k174 in k171 */
static void C_ccall f_236(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,1)))){
C_save_and_reclaim((void *)f_236,c,av);}
t2=t1;{
C_word *av2=av;
av2[0]=t2;
av2[1]=((C_word*)t0)[2];
((C_proc)C_fast_retrieve_proc(t2))(2,av2);}}

/* k244 in k222 in k219 in k198 in k195 in k192 in k189 in k186 in k183 in k180 in k177 in k174 in k171 */
static void C_ccall f_246(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,2)))){
C_save_and_reclaim((void *)f_246,c,av);}
C_trace(C_text("CscCalc.scm:109: scheme#display"));
{C_proc tp=(C_proc)C_fast_retrieve_proc(*((C_word*)lf[3]+1));
C_word *av2;
if(c >= 3) {
  av2=av;
} else {
  av2=C_alloc(3);
}
av2[0]=*((C_word*)lf[3]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=t1;
tp(3,av2);}}

/* k251 in k219 in k198 in k195 in k192 in k189 in k186 in k183 in k180 in k177 in k174 in k171 */
static void C_ccall f_253(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word *a;
C_check_for_interrupt;
if(C_unlikely(!C_demand(C_calculate_demand(0,c,5)))){
C_save_and_reclaim((void *)f_253,c,av);}
C_trace(C_text("CscCalc.scm:107: calc"));
{C_proc tp=(C_proc)C_fast_retrieve_symbol_proc(lf[0]);
C_word *av2;
if(c >= 6) {
  av2=av;
} else {
  av2=C_alloc(6);
}
av2[0]=*((C_word*)lf[0]+1);
av2[1]=((C_word*)t0)[2];
av2[2]=lf[7];
av2[3]=C_fix(2);
av2[4]=C_fix(3);
av2[5]=t1;
tp(6,av2);}}

/* toplevel */
static C_TLS int toplevel_initialized=0;
C_main_entry_point

void C_ccall C_toplevel(C_word c,C_word *av){
C_word tmp;
C_word t0=av[0];
C_word t1=av[1];
C_word t2;
C_word t3;
C_word *a;
if(toplevel_initialized) {C_kontinue(t1,C_SCHEME_UNDEFINED);}
else C_toplevel_entry(C_text("toplevel"));
C_check_nursery_minimum(C_calculate_demand(3,c,2));
if(C_unlikely(!C_demand(C_calculate_demand(3,c,2)))){
C_save_and_reclaim((void*)C_toplevel,c,av);}
toplevel_initialized=1;
if(C_unlikely(!C_demand_2(119))){
C_save(t1);
C_rereclaim2(119*sizeof(C_word),1);
t1=C_restore;}
a=C_alloc(3);
C_initialize_lf(lf,18);
lf[0]=C_h_intern(&lf[0],4, C_text("calc"));
lf[1]=C_h_intern(&lf[1],34, C_text("chicken.base#implicit-exit-handler"));
lf[2]=C_h_intern(&lf[2],14, C_text("scheme#newline"));
lf[3]=C_h_intern(&lf[3],14, C_text("scheme#display"));
lf[4]=C_h_intern(&lf[4],28, C_text("##sys#peek-and-free-c-string"));
lf[5]=C_h_intern(&lf[5],18, C_text("chicken.base#error"));
lf[6]=C_decode_literal(C_heaptop,C_text("\376B\000\000\015profile error"));
lf[7]=C_h_intern(&lf[7],6, C_text("divide"));
lf[8]=C_h_intern(&lf[8],19, C_text("##sys#make-locative"));
lf[9]=C_h_intern(&lf[9],8, C_text("location"));
lf[10]=C_h_intern(&lf[10],27, C_text("chicken.load#load-extension"));
lf[11]=C_h_intern(&lf[11],7, C_text("srfi-18"));
lf[12]=C_h_intern(&lf[12],5, C_text("medea"));
lf[13]=C_h_intern(&lf[13],7, C_text("srfi-13"));
lf[14]=C_h_intern(&lf[14],7, C_text("srfi-69"));
lf[15]=C_h_intern(&lf[15],8, C_text("srfi-158"));
lf[16]=C_h_intern(&lf[16],8, C_text("srfi-196"));
lf[17]=C_h_intern(&lf[17],8, C_text("srfi-130"));
C_register_lf2(lf,18,create_ptable());{}
t2=(*a=C_CLOSURE_TYPE|2,a[1]=(C_word)f_173,a[2]=t1,tmp=(C_word)a,a+=3,tmp);{
C_word *av2=av;
av2[0]=C_SCHEME_UNDEFINED;
av2[1]=t2;
C_library_toplevel(2,av2);}}

#ifdef C_ENABLE_PTABLES
static C_PTABLE_ENTRY ptable[20] = {
{C_text("f_173:CscCalc_2escm"),(void*)f_173},
{C_text("f_176:CscCalc_2escm"),(void*)f_176},
{C_text("f_179:CscCalc_2escm"),(void*)f_179},
{C_text("f_182:CscCalc_2escm"),(void*)f_182},
{C_text("f_185:CscCalc_2escm"),(void*)f_185},
{C_text("f_188:CscCalc_2escm"),(void*)f_188},
{C_text("f_191:CscCalc_2escm"),(void*)f_191},
{C_text("f_194:CscCalc_2escm"),(void*)f_194},
{C_text("f_197:CscCalc_2escm"),(void*)f_197},
{C_text("f_200:CscCalc_2escm"),(void*)f_200},
{C_text("f_202:CscCalc_2escm"),(void*)f_202},
{C_text("f_221:CscCalc_2escm"),(void*)f_221},
{C_text("f_224:CscCalc_2escm"),(void*)f_224},
{C_text("f_227:CscCalc_2escm"),(void*)f_227},
{C_text("f_230:CscCalc_2escm"),(void*)f_230},
{C_text("f_236:CscCalc_2escm"),(void*)f_236},
{C_text("f_246:CscCalc_2escm"),(void*)f_246},
{C_text("f_253:CscCalc_2escm"),(void*)f_253},
{C_text("toplevel:CscCalc_2escm"),(void*)C_toplevel},
{NULL,NULL}};
#endif

static C_PTABLE_ENTRY *create_ptable(void){
#ifdef C_ENABLE_PTABLES
return ptable;
#else
return NULL;
#endif
}

/*
o|eliminated procedure checks: 4 
o|replaced variables: 13 
o|removed binding forms: 18 
o|removed binding forms: 11 
o|simplifications: ((if . 1) (##core#call . 4)) 
o|  call simplifications:
o|    scheme#eqv?
o|    ##sys#foreign-flonum-argument	2
o|    ##sys#foreign-pointer-argument
o|contracted procedure: k205 
o|contracted procedure: k209 
o|contracted procedure: k213 
o|contracted procedure: k237 
o|removed binding forms: 4 
*/
/* end of file */

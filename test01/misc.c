#include <string.h>

int get_switch_value(char* func) {
    const char *func_array[] = {
        "add",
        "subtract",
        "multiply",
        "divide",
        "power",
        "square"
    };
    int i, j=sizeof(func_array);
    for (i = 0;i<j;++i)   
        {       
            if(strcmp(func_array[i],func)==0)
                break;       
        }   
   return i;
}
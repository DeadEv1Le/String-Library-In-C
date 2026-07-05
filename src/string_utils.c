#include "../include/string_utils.h"
#include <stdlib.h>




// 1. Str len funkcian rekursiv

int my_strlen (const char *str){

    if (str == NULL) return 0;

    if(*str == '\0') {
        return 0;
    }

    return 1 + my_strlen(str + 1);
}


// 2. Str cpy funckian
// char* my_strcpy(char *dest, const char* src) {
//     static char *start = NULL; 
//     if (start == NULL) start = dest;

//     *dest = *src;
    
//     if (*src == '\0') {
//         char *temp = start;
//         start = NULL;
//         return temp;
//     }
    
//     return my_strcpy(dest + 1, src + 1);
// }

char* my_strcpy(char* dest, const char* src) {
    int i = 0;

    while (*(src + i) != '\0') {
        *(dest + i) = *(src + i); 
        i++;
    }
    
    *(dest + i) = '\0';

    return dest;
}






//3. Strn copy
// char* my_strncpy(char *dest, const char *src, int n) {
//     static char *start = NULL;
//     if (start == NULL) start = dest;

//     if (n <= 0) {
//         char *temp = start;
//         start = NULL;
//         return temp;
//     }

//     if (*src == '\0') {
//         *dest = '\0';
//         return my_strncpy(dest + 1, src, n - 1);
//     } else {
//          *dest = *src;
//         return my_strncpy(dest + 1, src + 1, n - 1);
//     }
// }

char* my_strncpy(char *dest, const char* src, int n){

    int i = 0; 

    while(i != n){ 
        *(dest + i) = *(src + i);
        i++;
    }
    *(dest+ i) = '\0';
    
    return dest;
}


//4 str cat
char* my_strcat(char* dest, const char* src) { 
    int i = my_strlen(dest);
    
    int k = 0;
    
    while( *(src + k) != '\0'){
        *(dest + i) = *(src + k); 
        i++;
        k++;
    }
    *(dest + i ) = '\0';
    
    return dest;
}

// //5 strncat
// char* my_strncat(char* dest, const char* src, int n){ 
//     int i = my_strlen(dest);
//     int k = 0;
//      while( *(src + k) != '\0' && k < n){
//         *(dest + i) = *(src + k); 
//         i++;
//         k++;
//     }
//     *(dest + i ) = '\0';
//     return dest;

// }

//5 strcmp equal -> 0, -tiv -> str1 < str2; +tiv -> str1 > str2
int my_strcmp(const char *str1, const char *str2) {
    int i = 0;

   
    while (*(str1 + i) == *(str2 + i)) {
        if (*(str1 + i) == '\0') {
            return 0;
        }
        i++;
    }
    return *(str1 + i) - *(str2 + i);
}
//6.  strncmp
int my_strncmp(const char *str1, const char *str2, int n){
     int i = 0;

    while (*(str1 + i) == *(str2 + i)) {
        if (*(str1 + i) == '\0' || i == n - 1) {
            return 0;
        }
        i++;
    }
    return *(str1 + i) - *(str2 + i);
}
//7.strchr
char* my_strchr(const char *str, int ch) {
    int i = 0;
    
    while(*(str + i) != '\0') {
        if (*(str + i ) == ch){
            
            return (char*)(str + i);
        }
        i++;
    }
    if (ch == '\0') {
        return (char *)(str + i);
    }
    return NULL;

}

//7 strrchr 
char* my_strrchr(const char *str, int ch){
    int i = my_strlen(str);
    
    while(i != 0){ 
        if( *(str + i ) == ch ){
            return (char*)(str + i);  
        }
        i--;

    }

    return NULL;
}

//8 strstr 
char* my_strstr(const char *haystack, const char *needle){
    if (*needle == '\0') return (char*)haystack;
    for (const char *h = haystack; *h != '\0'; h++) {
        const char *h_ptr = h;
        const char *n_ptr = needle;
    
        while (*h_ptr != '\0' && *n_ptr != '\0' && *h_ptr == *n_ptr) {
            h_ptr++;
            n_ptr++;
        }
        if (*n_ptr == '\0') return (char*)h;
    }
    return NULL;
}


















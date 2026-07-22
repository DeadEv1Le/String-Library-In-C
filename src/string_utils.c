#include "../include/string_utils.h"
#include <stdlib.h>

int my_strlen(const char *str) {
    if (str == NULL) return 0;
    if (*str == '\0') return 0;

    return 1 + my_strlen(str + 1);
}

char* my_strcpy(char* dest, const char* src) {
    if (dest == NULL || src == NULL) return NULL;

    int i = 0;
    while (*(src + i) != '\0') {
        *(dest + i) = *(src + i); 
        i++;
    }
    *(dest + i) = '\0';

    return dest;
}

char* my_strncpy(char *dest, const char* src, int n) {
    if (dest == NULL || src == NULL || n <= 0) return dest;

    int i = 0; 
    while (i < n && *(src + i) != '\0') { 
        *(dest + i) = *(src + i);
        i++;
    }
    while (i < n) {
        *(dest + i) = '\0';
        i++;
    }

    return dest;
}

char* my_strcat(char* dest, const char* src) { 
    if (dest == NULL || src == NULL) return NULL;

    int i = my_strlen(dest);
    int k = 0;
    
    while (*(src + k) != '\0') {
        *(dest + i) = *(src + k); 
        i++;
        k++;
    }
    *(dest + i) = '\0';
    
    return dest;
}

int my_strcmp(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) return 0;

    int i = 0;
    while (*(str1 + i) == *(str2 + i)) {
        if (*(str1 + i) == '\0') {
            return 0;
        }
        i++;
    }
    return (unsigned char)*(str1 + i) - (unsigned char)*(str2 + i);
}

int my_strncmp(const char *str1, const char *str2, int n) {
    if (str1 == NULL || str2 == NULL || n <= 0) return 0;

    int i = 0;
    while (i < n && *(str1 + i) == *(str2 + i)) {
        if (*(str1 + i) == '\0' || i == n - 1) {
            return 0;
        }
        i++;
    }
    if (i == n) return 0;
    return (unsigned char)*(str1 + i) - (unsigned char)*(str2 + i);
}

char* my_strchr(const char *str, int ch) {
    if (str == NULL) return NULL;

    int i = 0;
    while (*(str + i) != '\0') {
        if (*(str + i) == (char)ch) {
            return (char*)(str + i);
        }
        i++;
    }
    if ((char)ch == '\0') {
        return (char *)(str + i);
    }
    return NULL;
}

char* my_strrchr(const char *str, int ch) {
    if (str == NULL) return NULL;

    int i = my_strlen(str);
    while (i >= 0) { 
        if (*(str + i) == (char)ch) {
            return (char*)(str + i);  
        }
        i--;
    }

    return NULL;
}

char* my_strstr(const char *haystack, const char *needle) {
    if (haystack == NULL || needle == NULL) return NULL;
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

int my_strspn(const char *str, const char *accept) {
    if (str == NULL || accept == NULL || *accept == '\0') return 0;
    
    int i = 0;
    while (*(str + i) != '\0') { 
        int count = 0;
        int k = 0; 
        while (*(accept + k) != '\0') { 
            if (*(str + i) == *(accept + k)) {
                count = 1; 
                break;
            }
            k++;
        }
        if (!count) { 
            return i;
        }
        i++;
    }
    return i;
}

int my_strcspn(const char *str, const char *reject) {
    if (str == NULL || reject == NULL) return 0;

    int i = 0;
    while (*(str + i) != '\0') { 
        int count = 0;
        int k = 0; 
        while (*(reject + k) != '\0') { 
            if (*(str + i) == *(reject + k)) {
                count = 1; 
                break;
            }
            k++;
        }
        if (count) { 
            return i;
        }
        i++;
    }
    return i;
}

char* my_strpbrk(const char *str, const char *accept) { 
    if (str == NULL || accept == NULL || *accept == '\0') return NULL;
    
    int i = 0;
    while (*(str + i) != '\0') { 
        int k = 0; 
        while (*(accept + k) != '\0') { 
            if (*(str + i) == *(accept + k)) {
                return (char*)(str + i);
            }
            k++;
        }
        i++;
    }
    return NULL;
}

char* my_strtok(char *str, const char *delim) {
    if (delim == NULL) return NULL;

    static char* tok = NULL;
    if (str != NULL) tok = str;

    if (tok == NULL) return NULL;

    while (*tok != '\0') {
        int is_delim = 0;
        for (const char *d = delim; *d != '\0'; d++) {
            if (*tok == *d) {
                is_delim = 1;
                break;
            }
        }
        if (!is_delim) break;
        tok++;
    }

    if (*tok == '\0') {
        tok = NULL;
        return NULL;
    }

    char *start = tok;

    while (*tok != '\0') {
        int is_delim = 0;
        for (const char *d = delim; *d != '\0'; d++) {
            if (*tok == *d) {
                is_delim = 1;
                break;
            }
        }
        if (is_delim) {
            *tok = '\0';
            tok++;
            return start;
        }
        tok++;
    }

    return start;
}

int my_count_char(const char *str, char ch) { 
    if (str == NULL || *str == '\0' || ch == '\0') {
        return 0;
    }
    
    int count = 0;
    while (*str != '\0') {
        if (*str == ch) {
            count++;
        }
        str++;
    }

    return count;
}

int my_strequal(const char *str1, const char *str2) {
    if (str1 == NULL || str2 == NULL) {
        return 0; 
    }

    while (*str1 != '\0' && *str2 != '\0') { 
        if (*str1 != *str2) { 
            return 0;
        }
        str1++;
        str2++;
    }

    return (*str1 == *str2);
}

void my_fill_string(char *str, char ch) {
    if (str == NULL) {
        return; 
    }
    
    while (*str != '\0') {
        *str = ch;
        str++;
    }
}

int my_strlastindex(const char* str, char ch) {
    if (str == NULL) {
        return -1;
    }

    int last_idx = -1;
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] == ch) {
            last_idx = i; 
        }
        i++;
    }

    return last_idx;
}

int my_strpalindrome(const char *str) {
    if (str == NULL) {
        return 0; 
    }
    if (*str == '\0') {
        return 1;
    }

    const char *left = str;       
    const char *right = str;      
   
    while (*right != '\0') {
        right++;
    }
    right--; 

    while (left < right) {
        if (*left != *right) {
            return 0;
        }
        left++;  
        right--; 
    }

    return 1;
}

char* my_strreverse(char *str) {
    if (str == NULL) return NULL;

    int left = 0;
    int right = my_strlen(str) - 1;

    while (left < right) {
        char temp = *(str + left);
        *(str + left) = *(str + right);
        *(str + right) = temp;
        left++;
        right--;
    }

    return str;
}
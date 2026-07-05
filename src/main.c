#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/string_utils.h"

int main() {
    printf("--- Testing String Library Functions ---\n\n");

    // Allocate memory for tests
    //======= s1 =======
    char *s1 = NULL;
    size_t size_s1 = 0;
    ssize_t chars_read_s1; 

    printf("Please Enter s1: \n ");
    
    chars_read_s1 = getline(&s1, &size_s1, stdin);



    if (chars_read_s1 > 0 && s1[chars_read_s1 - 1] == '\n') {
        s1[chars_read_s1 - 1] = '\0'; 
    }

    
    //===== s2 =========
    char *s2 = NULL;
    size_t size_s2 = 0;
    ssize_t chars_read_s2; 

    printf("Please Enter s2: \n ");
    
    chars_read_s2 = getline(&s2, &size_s1, stdin);
    if (chars_read_s2 > 0 && s2[chars_read_s2 - 1] == '\n') {
        s2[chars_read_s2 - 1] = '\0'; 
    }

    // Testing
    char *dest = (char *)malloc(50 * sizeof(char)); 

    printf("1. strlen(%s): %d \n", s1, my_strlen(s1));
    
    


    // my_strcpy(dest, s1);
    // printf("2. strcpy: %s\n", dest);
    // printf("%p %p", dest, s1);
    
    // my_strncpy(dest, s1, 2);
    // printf("3. strncpy (first 2 chars): %s\n", dest);
   
    
    

    
    // my_strcat(s2, s1);
    // printf("4. strcat (): %s\n", s2);
    // printf("%p %p", dest, s1);
    
    // printf("5. strcmp: %d\n", my_strcmp(s1, s2));

    // printf("6. strncmp: %d\n", my_strncmp(s1, s2, 5));
    
    // printf("7. strchr ('o' in Hello): %p\n", my_strchr(s1, 'o'));
    
    
    // printf("8. strrchr ('o' in Hello): %p\n", my_strrchr(s1, 'o'));

    

    printf("9. strstr ('World' in Hello World): %s\n", my_strstr(s1, "World"));
    
    

    // printf("10. strspn: %d\n", my_strspn(s1, "Hel"));
    // printf("11. strcspn: %d\n", my_strcspn(s1, " "));
    
    // printf("12. strpbrk: %s\n", my_strpbrk(s1, "W"));
    
    // // strtok usage needs a copy because it modifies the string
    // char *tok_str = strdup("One,Two,Three");
    // printf("13. strtok: %s\n", my_strtok(tok_str, ","));
    // free(tok_str);
    
    // printf("14. count_char ('l' in Hello): %d\n", my_count_char(s1, 'l'));
    // printf("15. strequal ('Hello' == 'Hello'): %d\n", my_strequal(s2, "Hello"));
    
    // my_fill_string(dest, 'A');
    // printf("16. fill_string (with 'A'): %s\n", dest);
    
    // printf("17. strlastindex ('l' in Hello): %d\n", my_strlastindex(s1, 'l'));
    
    // my_strreverse(s2);
    // printf("18. strreverse ('Hello'): %s\n", s2);
    
    // printf("19. strpalindrome ('radar'): %d\n", my_strpalindrome("radar"));

    // Cleanup
    free(s1);
    free(s2);
    free(dest);

    printf("\nAll tests completed successfully!\n");
    return 0;
}
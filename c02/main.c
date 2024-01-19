#include <ctype.h>

char *ft_strcpy(char *dest, char *src);

int ft_str_is_numeric(char *str);
int ft_str_is_lowercase(char *str);
int ft_str_is_uppercase(char *str);
int ft_str_is_printable(char *str);
char *ft_strupcase(char *str);

int main() {
    return 0;
}

char *ft_strcpy(char *dest, char *src) {
    for(;*src != '\0'; src++, dest++) *dest = *src;
    *dest = '\0';
    return dest;
}

int ft_str_is_numeric(char *str) {
    for(;*str != '\0'; str++)
        if(*str < '0' || *str > '9')
            return 0;
    return 1;
}

int ft_str_is_lowercase(char *str) {
    for(;*str != '\0'; str++)
        if(*str < 'a' || *str > 'z')
            return 0;
    return 1;
}

int ft_str_is_uppercase(char *str) {
    for(;*str != '\0'; str++)
        if(*str < 'A' || *str > 'Z')
            return 0;
    return 1;
}

int ft_str_is_printable(char *str) {
    for(;*str != '\0'; str++)
        if(!isprint(*str))
            return 0;
    return 1;
}

char *ft_strupcase(char *str) {
    while (*str != '\0') {
        if (*str >= 'a' && *str <= 'z') {
            *str =(char)(*str - 'a' + 'A');
        }
        str++;
    }
    return str;
}

#include <unistd.h>

void ft_ft(int *nbr);
void ft_ultimate_ft(int *********nbr);
void ft_swap(int *a, int *b);
void ft_div_mod(int a, int b, int *div, int *mod);
void ft_ultimate_div_mod(int *a, int *b);
void ft_putstr(char *str);
int ft_strlen(char *str);
void ft_rev_int_tab(int *tab, int size);
void ft_sort_int_tab(int *tab, int size);

int main() {
    return 0;
}

void ft_ft(int *nbr) {
    *nbr = 42;
}

void ft_ultimate_ft(int *********nbr) {
    *********nbr = 42;
}

void ft_swap(int *a, int *b) {
    int temp = *b;
    *b = *a;
    *a = temp;
}

void ft_div_mod(int a, int b, int *div, int *mod) {
    *div = a / b;
    *mod = a % b;
}

void ft_ultimate_div_mod(int *a, int *b) {
    int temp_a = *a;
    *a = temp_a / (*b);
    *b = temp_a % (*b);
}

void ft_putstr(char *str) {
    while (*str != '\0') {
        write(1, str, 1);
        str++;
    }
}

int ft_strlen(char *str) {
    int len;
    for (len = 0; *str != '\0'; len++, str++);
    return len;
}

void ft_rev_int_tab(int *tab, int size) {
    int i, j, temp;
    for(i = 0, j = size - 1; i < j; i++, j--){
        temp = tab[i];
        tab[i] = tab[j];
        tab[j] = temp;
    }
}

void ft_sort_int_tab(int *tab, int size) {
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if (tab[j] > tab[j + 1]) {
                int temp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = temp;
            }
        }
    }
}




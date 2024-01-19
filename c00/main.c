#include <unistd.h>

void	ft_putchar(char c);
void	ft_print_alphabet(void);
void	ft_print_reverse_alphabet(void);
void	ft_print_numbers(void);
void	ft_is_negative(int n);
void	ft_print_comb(void);

int main(void) {
    ft_print_comb();
    return 0;
}

void ft_putchar(char c) {
    write(1, &c, 1);
}

void ft_print_alphabet(void) {
    for(char c = 'a'; c <= 'z'; c++) {
        write(1, &c, 1);
    }
}

void ft_print_reverse_alphabet(void) {
    for(char c = 'z'; c >= 'a'; c--) {
        write(1, &c, 1);
    }
}

void ft_print_numbers(void) {
    for (int i = '0'; i <= '9'; i++) {
        write(1, &i, 1);
    }
}

void ft_is_negative(int n) {
    char positive = 'P';
    char negative = 'N';
    if (n < 0){
        write(1, &negative, 1);
    } else {
        write(1, &positive, 1);
    }
}

void ft_print_comb(void) {
    char buffer[5];

    for (int digit1 = 0; digit1 < 10; digit1++) {
        for (int digit2 = digit1 + 1; digit2 < 10; digit2++) {
            for (int digit3 = digit2 + 1; digit3 < 10; digit3++) {
                buffer[0] = digit1 + '0';
                buffer[1] = digit2 + '0';
                buffer[2] = digit3 + '0';
                buffer[3] = ',';
                buffer[4] = ' ';
                write(STDOUT_FILENO, buffer, 5);
            }
        }
    }
}

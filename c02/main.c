/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcielesz <jcielesz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 22:49:18 by jcielesz          #+#    #+#             */
/*   Updated: 2024/01/23 02:42:03 by jcielesz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

char *ft_strcpy(char *dest, char *src);
char *ft_strncpy(char *dest, char *src, unsigned int n);
int ft_str_is_alpha(char *str);
int ft_str_is_numeric(char *str);
int ft_str_is_lowercase(char *str);
int ft_str_is_uppercase(char *str);
int ft_str_is_printable(char *str);
char *ft_strupcase(char *str);
char *ft_strlowcase(char *str);
char *ft_strcapitalize(char *str);
unsigned int ft_strlcpy(char *dest, char *src, unsigned int size);
void ft_putstr_non_printable(char *str);

#include <string.h>
int main() {
	char s[] = "salut, comment \n \n \ttu vas?";
	char d[50];

	ft_putstr_non_printable(s);
	//printf("%s", d);

    return 0;
}

char	*ft_strcpy(char *dest, char *src)
{
	int			i;

	i = 0;
    while(src[i])
    {
        dest[i] = src[i];
		i++;
    }
    return (dest);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_str_is_alpha(char *str)
{
	if (*str == '\0')
		return (1);

	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (!((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')))
			return 0;
		i++;
	}
	return 1;

}

int ft_str_is_numeric(char *str)
{
	if (*str == '\0')
		return (1);

	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (!(str[i] >= '0' && str[i] <= '9'))
			return 0;
		i++;
	}
	return 1;
}

int ft_str_is_lowercase(char *str)
{
	if (*str == '\0')
		return (1);

	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (!(str[i] >= 'a' && str[i] <= 'z'))
			return 0;
		i++;
	}
	return 1;
}

int ft_str_is_uppercase(char *str)
{
	if (*str == '\0')
		return (1);

	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (!(str[i] >= 'A' && str[i] <= 'Z'))
			return 0;
		i++;
	}
	return 1;
}

int ft_str_is_printable(char *str)
{
	if (*str == '\0')
		return (1);

	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (!(str[i] >= 32 && str[i] <= 127))
			return 0;
		i++;
	}
	return 1;
}

char *ft_strupcase(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] = (char)(str[i] - 'a' + 'A');
		i++;
	}
	return str;
}

char *ft_strlowcase(char *str)
{
	int i;

	i = 0;
	while(str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = (char)(str[i] + 'a' - 'A');
		i++;
	}
	return str;
}
// capitalize

void toUppderCaseLetter(char *c)
{
	if (*c >= 'a' && *c <= 'z')
		*c = (char)(*c - 'a' + 'A');
}

void toLowerCaseLetter(char *c)
{
	if (*c >= 'A' && *c <= 'Z')
		*c = (char)(*c + 'a' - 'A');
}

int isAlpha(char *c)
{
	if ((*c >= 'A' && *c <= 'Z') || (*c >= 'a' && *c <= 'z'))
		return (1);
	return(0);
}

char *ft_strcapitalize(char *str)
{
	int i;
	int sem;

	i = 0;
	sem = 1;
	while(str[i] != '\0')
	{
		if(!isAlpha(&str[i]))
		{
			sem = 1;
			i++;
			continue;
		}

		if(sem)
		{
			toUppderCaseLetter(&str[i]);
			sem = 0;
		}
		else
		{
			toLowerCaseLetter(&str[i]);
		}

		i++;
	}
	return str;
}

unsigned int ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	count;
	unsigned int	i;

	count = 0;
	while (src[count] != '\0')
		++count;
	i = 0;
	while (src[i] != '\0' && i < (size - 1))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = '\0';
	return (count);
}
#include <unistd.h>
void ft_putchar(char c)
{
	write(1, &c, 1);
}
void ft_putstr_non_printable(char *str)
{
	char hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};

	while(*str)
	{
		if((*str >= 0 && *str <= 31) || *str == 127)
		{
			ft_putchar('\\');
			int a;
			int b;

			a = (*str / 16);
			b = (*str % 16);

			ft_putchar(hex[a]);
			ft_putchar(hex[b]);
		}
		else
		{
			ft_putchar(*str);
		}
		str++;
	}
}

#include <stdlib.h>

int is_delim(char c, char *charset)
{
	if (c == 0)
		return (1);
	while(*charset)
	{
		if(c == *charset)
			return (1);
		charset++;
	}
	return (0);
}

char copy_word(char *dest, char *src, char *charset)
{
	int i;

	i = 0;
	while(!is_delim(src[i], charset))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
}

void get_words(char **strs, char *str, char *charset)
{
	int i;
	int j;
	int word;

	word = 0;
	i = 0;
	while(str[i])
	{
		if (is_delim(str[i], charset))
			i++;
		else
		{
			j = 0;
			while(!is_delim(str[i + j], charset))
				j++;
			strs[word] = (char *) malloc((j + 1) * sizeof(char));
			copy_word(strs[word], str + i, charset);
			i += j;
			word++;
		}
	}
}

int word_count(char *str, char *charset)
{
	int i;
	int words;

	words = 0;
	i = 0;
	while (str[i])
	{
		if (is_delim(str[i + 1], charset) && !is_delim(str[i], charset))
			words++;
		i++;
	}
	return (words);
}

char	**ft_split(char *str, char *charset)
{
	char **res;
	int words;

	words = word_count(str, charset);
	res = (char **) malloc((words + 1) * sizeof(char *));
	get_words(res, str, charset);
	res[words] = 0;
	return (res);
}

#include <stdio.h>

int	main(void)
{
	char s[] = ";;;Hello,world,m;y,own";
	char charset[] = ",;";
	char **r;
	r = ft_split(s, ";,");
	for(int i = 0; i < word_count(s, charset) + 1; i++)
	{
		printf("%s\n", r[i]);
	}
	free(r);
	return 0;
}

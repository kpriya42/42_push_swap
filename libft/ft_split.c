/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kri- <kri-@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 22:02:20 by kri-              #+#    #+#             */
/*   Updated: 2026/05/28 13:44:59 by kri-             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_freeoutput(char **output, unsigned int index)
{
	while (index > 0)
		free(output[--index]);
	free(output);
	return (NULL);
}

static char	**ft_allocateoutput(char const *s, char ch)
{
	char			**output;
	int				wordcount;
	char			*str;
	unsigned int	i;

	if (!s || s[0] == '\0')
	{
		output = malloc (1 * sizeof(char *));
		return (output);
	}
	wordcount = 0;
	i = 0;
	str = (char *)s;
	while (str[i])
	{
		if (i == 0 && str[i] != ch)
			wordcount++;
		if (str[i] == ch && str[i + 1] != ch && str[i + 1])
			wordcount++;
		i++;
	}
	output = malloc((wordcount + 1) * sizeof (char *));
	return (output);
}

static void	findstart(const char *s, char c, unsigned int *start,\
	unsigned int *index)
{
	char	*str;

	str = (char *)s;
	while (str[*index] == c && str[*index])
		(*index)++;
	*start = *index;
	while (str[*index] != c && str[*index])
		(*index)++;
}

char	**ft_split(char const *s, char c)
{
	char			**output;
	unsigned int	j;
	unsigned int	i;
	unsigned int	start;

	j = 0;
	i = 0;
	output = ft_allocateoutput(s, c);
	if (!output)
		return (NULL);
	while (s[i])
	{
		findstart(s, c, &start, &i);
		if ((i - start) > 0)
		{
			output[j] = ft_substr(s, start, i - start);
			if (!output[j])
				return (ft_freeoutput(output, j));
			j++;
		}
	}
	output[j] = NULL;
	return (output);
}

//int	main(void)
//{
//	char	**output;
//	//char	*str = {";This;is;a;String;;that;is;to;be;tested;;;;;"};
//	//char	ch = ';';
//	//char *str= "hello!";
//	//char ch = ' ';
//	char	*str = "hello!zzzzzzzz";
//	char ch = 'z';
//	// char *str = "      split       this for   me  !       ";
//	// char ch = ' ';
//	//char *str = "";
//	//char ch = 'z';
//	int		i = 0;

//	output = ft_split(str, ch);
//	while (output[i] != NULL)
//		printf("%s\n", output[i++]);
//	printf ( "output[%d] = %s\n",i, output[i]);
//	i++;
//	printf ( "output[%d] = %s",i, output[i]);
//	return (0);
//}

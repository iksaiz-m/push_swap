/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:25:33 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/22 18:30:49 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	ft_free(char **a)
{
	size_t	t;

	t = 0;
	while (a[t] != NULL)
	{
		free(a[t]);
		t++;
	}
	free(a);
}

void	error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
}

long	ft_long_atoi(const char *str, int i)
{
	long	result;
	int		b;

	result = 0;
	b = 1;
	while ((str[i] == '\f' || str[i] == '\n' || str[i] == '\r'
			|| str[i] == '\t' || str[i] == '\v' || str[i] == ' '))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			b = -1;
		i++;
	}
	while ((ft_isdigit(str[i])))
	{
		result = result * 10 +(str[i] - '0');
		if ((result * b) > MAX_INT || (result * b) < MIN_INT)
			return (ERROR_INT);
		i++;
	}
	return (result * b);
}

size_t	ft_multiple_num(char const *s, char c)
{
	size_t	num_word;
	size_t	i;

	i = 0;
	num_word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			num_word++;
		i++;
	}
	return (num_word);
}

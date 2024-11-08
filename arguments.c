/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:19:30 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/07 21:08:15 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	check_argument(char *av)
{
	t_stack	p;

	p.i = 0;
	if (av[0] == '\0')
		error();
	while(av[p.i] != '\0')
	{
		if (av[p.i] == '+' || av[p.i] == '-')
		{
			p.i++;
			if (!ft_isdigit(av[p.i]))
				error();
		}
		while(ft_isdigit(av[p.i]))
			p.i++;
		if (av[p.i] != ' ' && av[p.i] != '	' && av[p.i] != '\0')
				error();
		while(av[p.i] == ' ' || av[p.i] == '	')
			p.i++;
		if (av[p.i] == '\0')
			break;
	}
}
char	**handle_one_argument(char *av, t_stack *a)
{
	a->t = 0;
	check_argument(av);
	a->str = ft_split(av, ' ');
	while (a->str[a->t] != NULL)
	{
		ft_printf("CHECK STRING: %s\n", a->str[a->t]);
		if (ft_long_atoi(a->str[a->t], 0) == ERROR_INT)
		{
			ft_free(a->str);
			error();
		}
		a->t++;
	}
	return (a->str);
}
int	handle_repetition(char **str)
{
	t_stack	a;

	a.i = 0;
	while(str[a.i + 1] != NULL)
	{
		a.t = a.i + 1;
		a.x = str[a.i];
		a.y = str[a.t];
		while(str[a.t] != NULL)
		{
			a.y = str[a.t];
			if (ft_long_atoi(a.x, 0) == ft_long_atoi(a.y, 0))
			{
				ft_printf("number 1: %d\n", ft_long_atoi(a.x, 0));
				ft_printf("number 2: %d\n", ft_long_atoi(a.y, 0));
				ft_free(str);
				error();
			}
			a.t++;
		}
		a.i++;
	}
	return (0);
}

char	**handle_multiple_arguments(int ac, char **av, t_stack *a)
{
	a->i = 0;
	a->t = 0;
	while(++a->i < ac)
		check_argument(av[a->i]);
	a->i = 0;
	a->str = (char **)ft_calloc((ac), sizeof(char *));
	if (!a)
		return (NULL);
	while(++a->i < ac)
	{
		if (ft_multiple_num(av[a->i], ' ') > 1)
		{
			ft_free(a->str);
			error();
		}
		else
		{
			a->str[a->t] = ft_strdup(av[a->i]);
			if (ft_long_atoi(a->str[a->t], 0) == ERROR_INT)
			{
				ft_free(a->str);
				error();
			}
		}
		a->t++;
	}
	for(int x = 0; a->str[x] != NULL; x++)
			ft_printf("Check string: %s\n", a->str[x]);
	return (a->str);
}
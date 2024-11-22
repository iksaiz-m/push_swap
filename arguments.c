/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 20:19:30 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/22 18:17:19 by iksaiz-m         ###   ########.fr       */
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
	while (av[p.i] != '\0')
	{
		if (av[p.i] == '+' || av[p.i] == '-')
		{
			p.i++;
			if (!ft_isdigit(av[p.i]))
				error();
		}
		while (ft_isdigit(av[p.i]))
			p.i++;
		if (av[p.i] != ' ' && av[p.i] != '	' && av[p.i] != '\0')
			error();
		while (av[p.i] == ' ' || av[p.i] == '	')
			p.i++;
		if (av[p.i] == '\0')
			break ;
	}
}

char	**handle_one_argument(char *av)
{
	int		t;
	char	**str;

	t = 0;
	check_argument(av);
	str = ft_split(av, ' ');
	while (str[t] != NULL)
	{
		if (ft_long_atoi(str[t], 0) == ERROR_INT)
		{
			ft_free(str);
			error();
		}
		t++;
	}
	return (str);
}

int	handle_repetition(char **str)
{
	t_stack	a;

	a.i = 0;
	while (str[a.i + 1] != NULL)
	{
		a.t = a.i + 1;
		a.x = str[a.i];
		a.y = str[a.t];
		while (str[a.t] != NULL)
		{
			a.y = str[a.t];
			if (ft_long_atoi(a.x, 0) == ft_long_atoi(a.y, 0))
			{
				ft_free(str);
				error();
			}
			a.t++;
		}
		a.i++;
	}
	return (0);
}

char	**handle_multiple_arguments(int ac, char **av)
{
	t_stack	xxx;

	xxx.i = 0;
	xxx.t = 0;
	while (++xxx.i < ac)
	{
		check_argument(av[xxx.i]);
		if (ft_multiple_num(av[xxx.i], ' ') > 1)
			error();
	}
	xxx.i = 0;
	xxx.str = (char **)ft_calloc((ac + 1), sizeof(char *));
	if (!xxx.str)
		return (NULL);
	while (++xxx.i < ac)
	{
		xxx.str[xxx.t] = ft_strdup(av[xxx.i]);
		if (ft_long_atoi(xxx.str[xxx.t], 0) == ERROR_INT)
		{
			ft_free(xxx.str);
			error();
		}
		xxx.t++;
	}
	return (xxx.str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:56:22 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/10/30 22:00:46 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

// static void	initialize_stacks(t_stack *a, t_stack *b)
// {
// 	a->top = NULL;
// 	b->top = NULL;
// }

void	error(void)
{
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
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
	check_argument(av);
	a->str = ft_split(av, ' ');
	for(int x = 0; a->str[x] != NULL; x++)
		ft_printf("%s\n", a->str[x]);
	return (a->str);
}
int	handle_repetition(int ac, char **str)
{
	t_stack	a;

	a.i = 0;
	if (ac >= 2)
	{
		while(str[a.i + 1] != NULL)
		{
			a.t = a.i + 1;
			a.x = str[a.i];
			a.y = str[a.t];
			while(str[a.t] != NULL)
			{
				a.y = str[a.t];
				if (ft_atoi(a.x) == ft_atoi(a.y))
				{
					ft_printf("number 1: %d\n", ft_atoi(a.x));
					ft_printf("number 2: %d\n", ft_atoi(a.y));
					error();
				}
				a.t++;
			}
			a.i++;
		}
	}
	return (0);
}

char	**handle_multiple_arguments(int ac, char **av, t_stack *a)
{

	a->i = 1;
	a->t = 0;
	while(a->i < ac)
	{
		check_argument(av[a->i]);
		a->i++;
	}
		a->i = 1;
		a->str = (char **)ft_calloc((ac), sizeof(char *));
	while(a->i < ac)
	{
		if (ft_multiple_num(av[a->i], ' ') > 1)
			error();
		else
		{
			ft_printf("numero arg: %d\n", ft_multiple_num(av[a->i], ' '));
			a->str[a->t] = ft_strdup(av[a->i]);
		}
		a->i++;
		a->t++;
	}
	for(int x = 0; a->str[x] != NULL; x++)
			ft_printf("Check string: %s\n", a->str[x]);
	return(a->str);
}


int	main(int ac, char **av)
{
	t_stack		a;
	//t_stack		b;

	if (ac == 1)
		error();
	//initialize_stacks(&a, &b);
	if (ac == 2)
	{
		a.str = handle_one_argument(av[1], &a);
	}
	if (ac > 2)
		handle_multiple_arguments(ac, av, &a);
	handle_repetition(ac, a.str);
	return (0);
}

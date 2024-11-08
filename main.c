/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:56:22 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/08 21:41:33 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

static void	initialize_stacks(t_stack *a, t_stack *b)
{
	a = NULL;
	b = NULL;
}
static void	ft_free(char **a)
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
	{
		check_argument(av[a->i]);
		if (ft_multiple_num(av[a->i], ' ') > 1)
			error();
	}
	a->i = 0;
	a->str = (char **)ft_calloc((ac), sizeof(char *));
	while(++a->i < ac)
	{
		a->str[a->t] = ft_strdup(av[a->i]);
		if (ft_long_atoi(a->str[a->t], 0) == ERROR_INT)
		{
			ft_free(a->str);
			error();
		}
	a->t++;
	}
	return (a->str);
}
long	*create_long(char **str, int i)
{
	long ii;
	long *nlist;
	
	ii = 0;
	nlist = (long *)ft_calloc(i, sizeof(long));
	if (!nlist)
		return (NULL);
	while (ii < i)
	{
		nlist[ii] = ft_long_atoi(str[ii], 0);
		ii++;
	}
	ft_free(str);
	return (nlist);
}
void	charge_nlist(t_stack *a, long *nlist, int i)
{
	t_stack	*last;
	t_stack	*new;

	last = (void *)0;
	a->i = 0;
	while (a->i < i)
	{
		new = malloc(sizeof (struct s_list));
		if (!new)
			return ;
		new->num = nlist[a->i];
		new->index = 0;
		new->next = (void *)0;
		if (last == (void *)0)
			a = new;
		else
			last->next = new;
		last = new;
		a->i++;
	}
	free(nlist);
	free(new);
}

int	main(int ac, char **av)
{
	t_stack		a;
	t_stack		b;
	long		*nlist;
	
	a.i = 0;
	initialize_stacks(&a, &b);
	if (ac == 1)
		return (1);
	if (ac == 2)
		handle_one_argument(av[1], &a);
	if (ac > 2)
		handle_multiple_arguments(ac, av, &a);
	handle_repetition(a.str);
	while (a.str[a.i] != NULL)
		a.i++;
	nlist = create_long(a.str, a.i);
	charge_nlist(&a, nlist, a.i);
	// ft_free(a.str);
	//free(nlist);
	return (0);
}

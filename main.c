/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 21:56:22 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/22 19:07:56 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void checkpa(t_stack **a)
{
	t_stack	*temporal;
	t_stack	**j;
	j = a;
	ft_printf("Valor stack a:\n");
	while(*j)
	{
		temporal = ((*j))->next;
		ft_printf(" %d ", (*j)->num);
		*j = temporal;
		//free (*a);
	}
}

void checkpb(t_stack **b)
{
	t_stack	*temporal;
	t_stack	**j;
	j = b;
	ft_printf("\nValor stack b:\n");
	while(*j)
	{
		temporal = ((*j))->next;
		ft_printf(" %d ", (*j)->num);
		*j = temporal;
		//free (*a);
	}
}

int	main(int ac, char **av)
{
	t_stack		*a;
	t_stack		*b;
	char		**str;
	int			i;

	i = 0;
	a = NULL;
	str = NULL;
	b = NULL;
	if (ac == 1)
		return (1);
	if (ac == 2)
		str = handle_one_argument(av[1]);
	if (ac > 2)
		str = handle_multiple_arguments(ac, av);
	handle_repetition(str);
	while (str[i])
		i++;
	create_long(&a, str, i);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	ft_pb(&a, &b);
	//ft_ss(&a, &b);
	ft_rr(&a, &b);
	checkpa(&a);
	checkpb(&b);
	return (0);
}

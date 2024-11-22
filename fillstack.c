/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillstack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 18:23:38 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/22 18:30:53 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

void	charge_nlist(t_stack **a, long *nlist, int size)
{
	t_stack	*last;
	t_stack	*new;
	long	i;

	last = NULL;
	i = 0;
	new = NULL;
	while (i < size)
	{
		new = malloc(sizeof (struct s_stack));
		if (!new)
			return ;
		new->num = nlist[i];
		new->index = 0;
		new->next = (void *)0;
		if (last == (void *)0)
			*a = new;
		else
			last->next = new;
		last = new;
		i++;
	}
	free(nlist);
}

long	*create_long(t_stack **a, char **str, int size)
{
	long	i;
	long	*nlist;

	i = 0;
	nlist = (long *)malloc(size * sizeof(long));
	if (!nlist)
		return (NULL);
	while (i < size)
	{
		nlist[i] = ft_long_atoi(str[i], 0);
		i++;
	}
	ft_free(str);
	charge_nlist(a, nlist, size);
	return (nlist);
}

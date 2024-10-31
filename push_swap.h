/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 20:39:16 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/10/30 20:00:16 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#if !defined(PUSH_SWAP_H)
# define PUSH_SWAP_H

# include "libft/libft.h"

typedef struct s_node
{
	int	x;
	struct s_node	*next;
}	t_node;

typedef struct s_stack
{
	int			t;
	int			i;
	size_t		len;
	char	**str;
	char		*x;
	char		*y;
	t_node	*top;
}	t_stack;


#endif // PUSH_SWAP_H

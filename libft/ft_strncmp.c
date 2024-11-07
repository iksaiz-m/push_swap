/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iksaiz-m <iksaiz-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 17:53:49 by iksaiz-m          #+#    #+#             */
/*   Updated: 2024/11/06 21:44:37 by iksaiz-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0' || s2[i] != '\0') && i < n)
	{
		if (s1[i] != s2[i])
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
		i++;
	}
	return (0);
}
// int main ()
// {
// 	int	n = 6;

//     char s1[] = "232";
//     char s2[] = "232";

// 	if (ft_strncmp(s1, s2, n))
// 		ft_printf ("ft:       %d\n", ft_strncmp(s1, s2, n));
// 	// char s3[] = "tes";
//     // char s4[] = "tesst";
// 	// ft_printf ("original: %d", strncmp(s3, s4, n));
// 	return (0);
// }
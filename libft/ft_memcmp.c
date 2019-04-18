/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 11:22:36 by mirivera          #+#    #+#             */
/*   Updated: 2019/02/28 09:36:06 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compares two pieces of memory.
** The two strings are being typecast inside the while loop and return line
** and then compared with an integer as the return value
*/

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	if (n == 0)
		return (0);
	while (*((unsigned char*)s1) == *((unsigned char*)s2) && --n)
		s1++ && s2++;
	return (*((unsigned char*)s1) - *((unsigned char*)s2));
}

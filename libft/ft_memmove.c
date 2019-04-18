/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 10:44:16 by mirivera          #+#    #+#             */
/*   Updated: 2019/02/28 09:36:38 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The memmove() function copies len bytes from string src to string dst.
** The two strings may overlap; the copy is always done
** in a non-destructive manner.
*/

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t	i;

	if (dest == src)
		return (dest);
	if (dest > src)
	{
		i = len;
		while (i-- > 0)
			((char *)dest)[i] = ((char *)src)[i];
	}
	else
	{
		i = 0;
		while (i < len)
		{
			((char *)dest)[i] = ((char *)src)[i];
			i++;
		}
	}
	return (dest);
}

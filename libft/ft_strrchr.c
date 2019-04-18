/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 18:20:09 by mirivera          #+#    #+#             */
/*   Updated: 2019/02/28 09:43:47 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strrchr() function is identical to strchr(), except it locates
** the last occurrence of c. Starts searching from the left.
*/

char	*ft_strrchr(const char *s, int c)
{
	char	*lastoccur;

	lastoccur = (0);
	while (*s)
	{
		if (*s == c)
			lastoccur = (char *)s;
		++s;
	}
	if (lastoccur)
		return (lastoccur);
	if (c == '\0')
		return ((char *)s);
	return (NULL);
}

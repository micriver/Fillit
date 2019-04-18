/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 14:38:27 by mirivera          #+#    #+#             */
/*   Updated: 2019/02/28 09:43:27 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	int				x;

	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i])
	{
		x = 0;
		while (haystack[i] == needle[x] && haystack[i] && i < len)
		{
			i++;
			x++;
		}
		if (!needle[x])
			return ((char *)&haystack[i - x]);
		i = (i - x) + 1;
	}
	return (NULL);
}

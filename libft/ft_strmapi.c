/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 09:50:34 by mirivera          #+#    #+#             */
/*   Updated: 2019/03/03 19:53:41 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** In protected functions, order matters, so you need to check if
** theres even strings and then return NULL if malloc doesnt return
** a string. Check your mallocs, check your frees.
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*fresh;

	if (!s || !f)
		return (NULL);
	if (!(fresh = ft_memalloc((size_t)ft_strlen((char *)s) + 1)))
		return (NULL);
	i = 0;
	if (fresh)
	{
		while (s[i])
		{
			fresh[i] = (f)(i, s[i]);
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	return (NULL);
}

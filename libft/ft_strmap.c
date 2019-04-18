/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 11:05:48 by mirivera          #+#    #+#             */
/*   Updated: 2019/03/02 14:08:13 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate memory for the new string and then
** copy the data from string s index by index
** while running the function at &f
*/

char	*ft_strmap(char const *s, char (*f)(char))
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
			fresh[i] = (f)(s[i]);
			i++;
		}
		fresh[i] = '\0';
		return (fresh);
	}
	return (NULL);
}

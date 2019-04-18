/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 12:25:23 by mirivera          #+#    #+#             */
/*   Updated: 2019/02/28 14:46:09 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a new substring from the string passed
** and print starting from the start index of the string passed
** Don't use ft_strlen for the new string, just use the len given
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substring;

	if (!(substring = ft_memalloc(len + 1)))
		return (NULL);
	i = 0;
	if (substring && s)
	{
		while (i < len)
		{
			substring[i] = s[start];
			i++;
			start++;
		}
		return (substring);
	}
	else
		return (NULL);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 16:10:58 by mirivera          #+#    #+#             */
/*   Updated: 2019/02/28 21:01:38 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** First, account for strings that are ALL spaces
** To count backwards, count to the end and subtract one
** then while there are any whitespaces, keep counting
** backwards until there isn't a space and call ft_strsub
** using the difference between index[i] and index[i] as
** the length for the new substring of s!
*/

char	*ft_strtrim(char const *s)
{
	char			*dest;
	unsigned int	i;
	int				start;

	if (!s)
		return (NULL);
	i = 0;
	while (ft_isspace(s[i]))
		i++;
	start = i;
	if (s[start] == '\0')
	{
		dest = ft_strnew(0);
		dest[0] = '\0';
		return (dest);
	}
	while (s[i])
		i++;
	i--;
	while (ft_isspace(s[i]))
		i--;
	if (!(dest = (ft_strsub(s, start, i - start + 1))))
		return (NULL);
	return (dest);
}

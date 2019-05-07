/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 12:41:46 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/06 17:44:46 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	char	*s1;
	char	*s2;

	i = 0;
	s1 = dest;
	s2 = (char*)src;
	if (ft_strlen(s2) < n)
	{
		while (i++ < ft_strlen(s2))
			*dest++ = *src++;
		while (i++ <= n)
			*dest++ = '\0';
	}
	else
	{
		while (i++ < n && src)
			*dest++ = *src++;
	}
	return (s1);
}

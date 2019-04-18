/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/26 17:11:52 by mirivera          #+#    #+#             */
/*   Updated: 2019/04/08 21:09:12 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Allocate memory for result using both or one string(s),
** since you'll be joining them in that string.
** Copy string1 into the new string if there's only one,
** same with the second string
** and then strcat the two or one strings together
** to fill in the rest of result's array, then return result.
*/

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *ret;

	if (!s1 || !s2)
		return (NULL);
	if (!(ret = (char*)malloc((ft_strlen((char*)s1) +
						ft_strlen((char*)s2)) + 1)))
		return (NULL);
	ret = ft_strcpy(ret, s1);
	ret = ft_strcat(ret, s2);
	return (ret);
}

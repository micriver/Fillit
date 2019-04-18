/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 21:17:42 by mirivera          #+#    #+#             */
/*   Updated: 2019/02/28 21:41:11 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** If the first expression returns TRUE then the expression
** on the left is executed. If FALSE, the expression on the
** right is returned.
**
** Line 30 determines # of places in the string
*/

char	*ft_itoa(int n)
{
	int		length;
	int		sign;
	char	*str;

	sign = n;
	length = 1;
	while (sign /= 10)
		length++;
	sign = n < 0 ? 1 : 0;
	length = n < 0 ? length += 1 : length;
	if (n == -2147483648)
		return (str = ft_strdup("-2147483648"));
	str = ft_strnew(length);
	if (!str)
		return (NULL);
	if (sign)
		str[0] = '-';
	n = n < 0 ? n *= -1 : n;
	while (--length >= sign)
	{
		str[length] = (n >= 10) ? (n % 10) + 48 : n + 48;
		n /= 10;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 10:19:53 by mirivera          #+#    #+#             */
/*   Updated: 2019/02/27 19:59:21 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Make sure there are strings and that those strings have characters in them
** also check to make sure there is a function at f's address
** then iterate with an unsigned int because that's what this function uses
** as it's first argument
*/

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int i;

	if (!s || !(*s) || !(f))
		return ;
	i = 0;
	while (s[i])
	{
		(f)(i, &s[i]);
		i++;
	}
}

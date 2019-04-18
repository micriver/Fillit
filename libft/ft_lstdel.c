/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:12:13 by mirivera          #+#    #+#             */
/*   Updated: 2019/03/04 18:39:21 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Takes as a parameter the address of a pointer to a link and
** frees the memory of this link and every successors of that link
** using the functions del and free(3).
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*new;

	if (!*alst)
		return ;
	while (*alst)
	{
		new = (*alst)->next;
		ft_lstdelone(&*alst, del);
		*alst = new;
	}
	alst = NULL;
}

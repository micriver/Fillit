/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tet_charcheck.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 10:17:22 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/01 10:28:45 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int     tet_charcheck(int i)
{
    if (i == '.' || i == '#' || i == '\n')
        return (1);
    return (0);
}

int     sharpcount(int i)
{
    int sharpcount;

    sharpcount = 0;
    if (i == '#')
    {
        sharpcount++;
        if (sharpcount > 4)
            return (0);
    }
    return (1);
}
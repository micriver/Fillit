/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_case.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 18:46:23 by mirivera          #+#    #+#             */
/*   Updated: 2019/05/07 19:28:26 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "fillit.h"

int     tests()
{
    int ac = 2;
    char *input[] = "./samples/valid_samples/valid_sample_1block.fillit";
    printf("\n- - - - - - - - - - - - - - - - - - - - - - - - - - - - - -\n");
    printf("- - - - - - - - - Validate 1 Tetrimino  - - - - - - - - - -\n");
    printf("\nFully validate 1 tetrimino\n");
    printf("\n");
    main(input);    



}

int     main()
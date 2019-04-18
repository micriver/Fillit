/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 19:25:53 by mirivera          #+#    #+#             */
/*   Updated: 2019/04/17 13:25:17 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
** ft_strsub is to create a new substring from the string passed
** into it from the static array. The array starts at 0
** and the length stops before the null terminator or the newline chars
**
** We are returning a line to the 2D array that will be printed
*/

static char		*line_to_print(char *str)
{
	int		i;
	char	*line_to_print;

	i = 0;
	while (str && str[i] != '\0' && str[i] != '\n')
	{
		if (str[i] == '\n')
			break ;
		i++;
	}
	line_to_print = ft_strsub(str, 0, i);
	return (line_to_print);
}

/*
** using ft_strchr, I find the first occurence of newline chars
** + 1 (going to the next char in the new line) to return the next
** string to read through for more lines
**
** I'm eliminating new line chars and terminating strings.
*/

char			*new_str(char *str, char *new_str)
{
	if (str && (ft_strchr(str, '\n')))
	{
		new_str = ft_strchr(str, '\n') + 1;
		new_str = ft_strdup(new_str);
		free(str);
		str = new_str;
	}
	else if (str && (ft_strchr(str, '\0')))
	{
		new_str = ft_strchr(str, '\0');
		new_str = ft_strdup(new_str);
		free(str);
		str = new_str;
	}
	return (new_str);
}

int				get_next_line(const int fd, char **line)
{
	static char		*temp[4864];
	char			buffer[BUFF_SIZE + 1];
	char			*tempmem;
	int				readresult;

	if (fd < 0 || line == NULL || fd >= 4864 || read(fd, buffer, 0) < 0)
		return (-1);
	while ((readresult = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		if (!temp[fd])
			temp[fd] = ft_strnew(BUFF_SIZE);
		buffer[readresult] = '\0';
		tempmem = ft_strjoin(temp[fd], buffer);
		free(temp[fd]);
		temp[fd] = tempmem;
		ft_bzero(buffer, BUFF_SIZE);
	}
	if (temp[fd] && *temp[fd] == '\0')
		return (readresult);
	*line = line_to_print(temp[fd]);
	temp[fd] = new_str(temp[fd], tempmem);
	return (1);
}

# include "fillit.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <strings.h>
/*
char	ft_strread(int fd, char **pieces)
{
	char	*temp;
	char	*leak;
	int		result;

	temp = ft_strnew(22);
	while ((result = read(fd, temp, 1)) > 0)
	{
		leak = buffer[fd];
		buffer[fd] = ft_strjoin(buffer[fd], temp);
		if (!buffer[fd])
			buffer[fd] = ft_strdup(temp);
		printf("%s\n", *buffer);
		free(leak);
		ft_bzero(temp, 1);
	}
	free(temp);
	return (result); // MODIFY THIS TO RETURN A STRING!!
}
*/
int main()
{
    int fd;
	int result;
    static char temp[546]; // holds at most the amount of tets
	char **pieces; // 2d array that hold all of our tets
	int i;

	i = 0;
	pieces = (char**)malloc(sizeof(char*) * 27); // allocate size in the 2d array to hold tets but also every letter in the alphabet
	fd = open("file.txt", O_RDONLY);

	while (i < 26 && (result = read(fd, temp, 21)) > 0) // instead we should read one byte at a time using gnl read that returns us the whole string
	{
		pieces[i] = ft_strdup(temp); // duplicate every 21 chars into seperate index's of the 2d array
		i++; // itirate to the next index and repeat process
	}
	pieces[i] = NULL; // make it null term to not seg fault, looks for null to finish
	for (int i = 0; pieces[i]; i++) { // Just for printing out the elements in the 2d array
		printf("%s\n", pieces[i]);
	}
    return (0);
}
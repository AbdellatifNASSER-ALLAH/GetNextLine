#include "../Project/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

void	prints(char *s)
{
	if (!s)
		return ;
	int i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			write(1, "\\n", 2);
		else 
			write(1, &s[i], 1);
		i++;
	}
	write(1, "\\0\n", 3);
}
int main(int ac, char **av)
{
	if (ac > 1)
	{
	int fd = open(av[1], O_RDONLY);
	char *p;

	while ((p = get_next_line(fd)))
	{
		prints(p);
		free(p);
	}
	printf("\nthe last should be null : %p\n",p);
	prints("done\n");	
	}
	return (0);
}

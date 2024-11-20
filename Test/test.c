#include "../Project/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

void	ft_putstr_fd(char *s, int fd)
{
	if (!s || fd < 0)
		return ;
	write(fd, s, strlen(s));
}
int main()
{
	int fd = open("a", O_RDONLY);
	char *p;

	p = get_next_line(fd);
	ft_putstr_fd(p, 1);
	free(p);
	ft_putstr_fd("\nruning...", 1);
	while(1){}
}

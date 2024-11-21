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
	write(1, s, strlen(s));
}
int main()
{
	int fd = open("a", O_RDONLY);
	char *p;

	while ((p = get_next_line(fd)))
	{
		prints(p);
		free(p);
	}
	printf("%p\n",p);
	prints("done\n");	
}

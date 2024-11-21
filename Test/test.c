#include "../Project/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

void	prints(char *s)
{
	int i = 0;
	write(1, "\"", 1);
	while (s[i])
	{
		if (s[i] == '\n')
			write(1, "\\n", 2);
		else 
			write(1, &s[i], 1);
		i++;
	}
	write(1, "\\0\"\n", 4);
}
int main()
{
		int fd = open("read_error.txt", O_RDONLY);
		char *p;

		while ((p = get_next_line(fd)))
		{
			prints(p);
			free(p);
		//	getchar();
		}
	return (0);
}

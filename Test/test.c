#include "../Project/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

void print(char *str)
{
	if (!str)
		return ;
	int i = 0;
	while(str[i])
	{
		if(str[i] == '\n')
			write(1,"0",1);
		else if (str[i + 1] == '\0')
			write(1, "$", 1);
		else
			write(1, str + i, 1);
		i++;
	}
	free(str);
	printf("\n");
}

int main()
{
	int fd = open("a", O_RDONLY);
	//int fd = open("b", O_RDONLY);

	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
	printf("%s",get_next_line(fd));
}

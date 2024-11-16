#include "../Project/get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
	int fd = open("a", O_RDONLY);

	char *s = get_next_line(fd);

	printf("%s", s);
}

#include "../Project/get_next_line_bonus.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main() {
	int fd1 = open("file1", O_RDONLY);
	int fd2 = open("file2", O_RDONLY);
	int fd3 = open("file3", O_RDONLY);
	char *line1, *line2, *line3;

	line1 = get_next_line(fd1);
	line2 = get_next_line(fd2);
	line3 = get_next_line(fd3);

	while (line1 || line2 || line3) {
		if (line1) {
			printf("%s", line1);
			free(line1);
			line1 = get_next_line(fd1);
		}
		if (line3)
		{
			printf("%s", line3);
			free(line3);
			line3 = get_next_line(fd3);
		}
		if (line2) {
			printf("%s", line2);
			free(line2);
			line2 = get_next_line(fd2);
		}
	}

	close(fd1);
	close(fd2);
	return 0;
}

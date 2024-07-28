#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main()
{
	int fd;
	char buff[256];
	int char_read;

	fd = open("test.txt", O_RDONLY);
	printf("fd value: %d\n", fd);
	while ((char_read = read(fd, buff, 5)))
	{
		buff[char_read] = '\0';
		printf("buff-> %s\n", buff);
	}
}
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

void	testft(void)
{
	static int	c;

	c += 1;
	printf("Fulnction for %i times\n", c);
}

void	test_read(void)
{
	int	fd;
	char	buf[1000];
	int	i;
	int	y;
	char	buf1[1000];

	fd = open("test.txt", O_RDONLY);
	i = read(fd, buf, 12);
	printf("Read %i bytes: %s\n", i, buf);
	y = read(fd, buf1, 12);
	printf("Read %i bytes: %s\n", y, buf1);
}

void	test_read1(void)
{
	int	fd;
	char	buf[12];
	int	i;

	fd = open("test.txt", O_RDONLY);
	i = read(fd, buf, 12);
	printf("Read %i bytes: %s\n", i, buf);
	buf[i] = '\0';
	printf("Read %i bytes\n", i);
}

int	main(void)
{
	test_read1();
}

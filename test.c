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
	char	buf[10];

	fd = open("test.txt", O_RDONLY);
	int i = read(fd, buf, sizeof(buf) - 1);

	buf[i] = '\0';
	printf("Read %i bytes: %s\n", i, buf);
}

int	main(void)
{
	testft();
	testft();
	testft();
	test_read();
}

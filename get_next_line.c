#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*saved_line;
	char	*line_result;


}

int	main()
{
	int fd;
	char *c;

	fd = open("test.txt", O_RDONLY);
	c = get_next_line(fd);
	printf("Get_NEXT_LINE:\n%s", c);
}
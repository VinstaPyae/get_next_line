/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pzaw <pzaw@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 15:23:29 by prafael-          #+#    #+#             */
/*   Updated: 2024/08/05 18:46:36 by pzaw             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

// int	main(void)
// {
// 	int fd;
// 	char *s1;
// 	char *s2;

// 	fd = open("test.txt", O_RDONLY);
// 	s1 = get_next_line(fd);
// 	printf("s1 start: %s", s1);
// 	s2 = get_next_line(fd);
// 	printf("s2 start: %s", s2);
// }

// int    main(void)
// {
//     int     fpointer;
//     char    *singleLine = malloc(1 * sizeof(char));

//     fpointer = open("test.txt", 256);
//     while(singleLine != NULL)
//     {
//         free(singleLine);
//         singleLine = get_next_line(fpointer);
//         printf("%s", singleLine);
//     }
//     return (0);
// }

// int	main(void)
// {
// 	int fd;
// 	char *c;

// 	fd = open("test.txt", O_RDONLY);
// 	if (fd < 0)
// 		perror("Error");
// 	c = get_next_line(fd);
// 	while (c)
// 	{
// 		printf("%s", c);
// 		free(c);
// 		c = get_next_line(fd);
// 	}
// 	close(fd);
// }

int main(void)
{
    char *files[] = {"test.txt", "test1.txt", "test2.txt"};
    int num_files = sizeof(files) / sizeof(files[0]);
    int fd;
    char *singleLine;
    for (int i = 0; i < num_files; i++)
    {
        fd = open(files[i], O_RDONLY);
        if (fd < 0)
        {
            perror("Error opening file");
            continue;
        }
        printf("Reading from %s:\n", files[i]);
        singleLine = get_next_line(fd);
        while (singleLine)
        {
            printf("%s", singleLine);
            free(singleLine);
            singleLine = get_next_line(fd);
        }
        close(fd);
        printf("\n");
    }
    
    return 0;
}
// int main()
// {
// 	int fd;
// 	int fd2;

// 	fd = open("test.txt", O_RDONLY);
// 	fd2 = open("test1.txt", O_RDONLY);
// 	char	*c;
// 	c = get_next_line(fd);
// 	while(c != NULL)
// 	{
// 		free(c);
// 		c = get_next_line(fd);
// 		printf("%s", c);
// 	}

//     return 0;
// }
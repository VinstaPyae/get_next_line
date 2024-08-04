/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/25 15:23:29 by prafael-          #+#    #+#             */
/*   Updated: 2024/08/04 23:41:55 by marvin           ###   ########.fr       */
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

int    main(void)
{
    int     fpointer;
    char    *singleLine = malloc(1 * sizeof(char));

    fpointer = open("test.txt", 256);
    while(singleLine != NULL)
    {
        free(singleLine);
        singleLine = get_next_line(fpointer);
        printf("%s", singleLine);
    }
    return (0);
}

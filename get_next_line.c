/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:32:55 by gmacedo-          #+#    #+#             */
/*   Updated: 2023/01/18 16:32:57 by gmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_remove(char *backup)
{
	int		i;
	int		j;
	char	*temp;

	i = 0;
	j = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	if (backup[i] == '\0')
	{
		free(backup);
		return (NULL);
	}
	temp = (char *)malloc(sizeof(char) * (ft_strlen(backup) - i + 1));
	if (!temp)
		return (NULL);
	i++;
	while (backup[i] != '\0')
		temp[j++] = backup[i++];
	temp[j] = '\0';
	free(backup);
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*backup;
	char		*line;

	backup = ft_read(fd, backup);
	if (backup == NULL)
		return (NULL);
	line = ft_getline(backup);
	backup = ft_remove(backup);
	return (line);
}
/*
int	main(void)
{
    int fd;
    int i;

    char* next;
    i = 0;
    fd = open("text.txt", O_RDONLY);
    //printf("fd = %d\n", fd);
    //if return -1 = error, if return 3 it read.
    while (i < 1)
    {
        next = get_next_line(fd);
        printf("%s", next);
        free (next);
        i++;
    }
}
*/
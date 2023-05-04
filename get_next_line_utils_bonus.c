/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:33:15 by gmacedo-          #+#    #+#             */
/*   Updated: 2023/01/18 16:33:16 by gmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *c)
{
	int	i;

	i = 0;
	if (c == NULL)
		return (0);
	while (c[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_join(char *backup, char *temp)
{
	char	*completed;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (backup == NULL)
	{
		backup = (char *)malloc(sizeof(char));
		backup[0] = '\0';
	}
	completed = (char *)malloc((sizeof(char) * (ft_strlen(backup)
					+ ft_strlen(temp))) + 1);
	if (!completed)
		return (NULL);
	while (backup[i] != '\0')
	{
		completed[i] = backup[i];
		i++;
	}
	while (temp[j] != '\0')
		completed[i++] = temp[j++];
	completed[i] = '\0';
	free(backup);
	return (completed);
}

int	ft_look(char *temp, char look)
{
	int	i;

	i = 0;
	if (temp == NULL)
		return (0);
	while (temp != NULL && temp[i] != '\0')
	{
		if (temp[i] == look)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

char	*ft_read(int fd, char *backup)
{
	int		sz;
	char	*temp;

	temp = (char *)malloc((sizeof(char) * BUFFER_SIZE) + 1);
	if (!temp)
		return (NULL);
	sz = 2;
	while (sz > 0 && !ft_look(temp, '\n'))
	{
		sz = read(fd, temp, BUFFER_SIZE);
		if (sz < 0)
		{
			free(backup);
			free(temp);
			return (NULL);
		}
		temp[sz] = '\0';
		backup = ft_join(backup, temp);
	}
	free(temp);
	return (backup);
}

char	*ft_getline(char *backup)
{
	int		i;
	char	*temp;

	i = 0;
	if (backup[0] == '\0')
		return (NULL);
	while (backup[i] != '\n' && backup[i] != '\0')
		i++;
	temp = (char *)malloc(sizeof(char) * (i + 2));
	if (!temp)
		return (NULL);
	i = 0;
	while (backup[i] != '\n' && backup[i] != '\0')
	{
		temp[i] = backup[i];
		i++;
	}
	if (backup[i] == '\n')
		temp[i] = '\n';
	temp[++i] = '\0';
	return (temp);
}

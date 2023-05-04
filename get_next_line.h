/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmacedo- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:33:03 by gmacedo-          #+#    #+#             */
/*   Updated: 2023/01/18 16:33:04 by gmacedo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen(char *c);
char	*ft_join(char *backup, char *temp);
int		ft_look(char *temp, char look);
char	*ft_read(int fd, char *backup);
char	*ft_getline(char *backup);
char	*ft_remove(char *backup);
char	*get_next_line(int fd);

#endif

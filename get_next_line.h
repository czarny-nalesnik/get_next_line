/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smalinow <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 19:49:23 by smalinow          #+#    #+#             */
/*   Updated: 2024/12/27 19:49:24 by smalinow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

char		*get_next_line(int fd);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strdup(char *s);
size_t		ft_strlen(const char *s);
char		*ft_strchr(char *s, int c);
char		*ft_substr(char *s, unsigned int start, size_t len);
char		*fill_line(int fd, char *chars_left, char *buff);
char		*set_line(char *line_buff);

#endif
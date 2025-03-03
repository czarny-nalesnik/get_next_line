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
#include "get_next_line.h"

char	*ft_strchr(char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

char	*set_line(char *line_buff)
{
	char	*chars_left;
	ssize_t	i;

	i = 0;
	while (line_buff[i] != '\n' && line_buff[i] != '\0')
		i++;
	if (line_buff[i] == 0 || line_buff[i + 1] == 0)
		return (NULL);
	chars_left = ft_substr(line_buff, i + 1, ft_strlen(line_buff) - i);
	if (*chars_left == 0)
	{
		free(chars_left);
		chars_left = NULL;
	}
	line_buff[i + 1] = 0;
	return (chars_left);
}

char	*fill_line_buff(int fd, char *chars_left, char *buff)
{
	ssize_t	bytes_read;
	char	*temp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(chars_left);
			return (NULL);
		}
		else if (bytes_read == 0)
			break ;
		buff[bytes_read] = '\0';
		if (!chars_left)
			chars_left = ft_strdup("");
		temp = chars_left;
		chars_left = ft_strjoin(temp, buff);
		free(temp);
		temp = NULL;
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (chars_left);
}

char	*get_next_line(int fd)
{
	static char	*chars_left;
	char		*line;
	char		*buff;

	buff = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(chars_left);
		free(buff);
		chars_left = NULL;
		buff = NULL;
		return (NULL);
	}
	if (!buff)
		return (NULL);
	line = fill_line_buff(fd, chars_left, buff);
	free(buff);
	buff = NULL;
	if (!line)
		return (NULL);
	chars_left = set_line(line);
	return (line);
}

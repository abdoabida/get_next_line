/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabouibr <aabouibr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/17 12:29:35 by aabouibr          #+#    #+#             */
/*   Updated: 2019/11/26 18:43:02 by aabouibr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_error(int fd, char *str, char **line)
{
	if (fd <= -1 || line == NULL)
		return (-1);
	if (!str)
	{
		if (!(str = ft_strnew(BUFF_SIZE)))
			return (-1);
	}
	return (0);
}

char	*fileread(char *str, int fd, int *j)
{
	char		buff[BUFF_SIZE + 1];

	while ((*j = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[*j] = '\0';
		str = ft_strjoin(str, buff);
		if (fd == 0)
			break ;
	}
	return (str);
}

char	*ft_line(char **str, char **line)
{
	char		*tmp;

	tmp = ft_strchr(*str, '\n');
	if (tmp == NULL)
	{
		(*line) = ft_strdup(*str);
		*str = NULL;
	}
	else
	{
		if (tmp == *str)
		{
			*line = ft_strdup("");
			(*str)++;
		}
		else
		{
			(*line) = ft_strsub(*str, 0, tmp - *str);
			*str = tmp + 1;
		}
	}
	return ((*line));
}

int		get_next_line(int fd, char **line)
{
	static char *str;
	int			j;

	if (ft_error(fd, str, line) == -1)
		return (-1);
	j = 0;
	str = fileread(str, fd, &j);
	if (j == -1)
		return (-1);
	if (str != NULL && *str)
	{
		(*line) = ft_line(&str, line);
		return (1);
	}
	else
		(*line) = NULL;
	return (0);
}

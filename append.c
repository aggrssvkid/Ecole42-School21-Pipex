/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_ways.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enoye <enoye@42.fr>                       +#+  +:+       +#+         */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 10:23:14 by enoye             #+#    #+#             */
/*   Updated: 2022/01/14 10:23:19 by enoye            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libpipex.h"

void	append(char **argv, t_wtf *v)
{
	char	*line;

	v -> in = open("!OUT!", O_RDWR);
	v -> out = open(argv[(v -> size) - 1], O_CREAT + O_RDWR + O_APPEND, 0644);
	line = get_next_line(v -> in);
	if (line == 0)
	{
		close(v -> in);
		close(v -> out);
		return ;
	}
	while (line != 0)
	{
		write(v -> out, line, ft_strlen(line));
		free(line);
		line = get_next_line(v -> in);
	}
}

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

static void	cat_doc(char **envp, t_wtf *v)
{
	v -> ways = find_ways(envp, "cat");
	v -> split = ft_split("cat", ' ');
	v -> pid = fork();
	if (v -> pid == 0)
	{
		v -> in = open("!OUT!", O_CREAT + O_RDWR, 0644);
		v -> out = open("!BUF!", O_CREAT + O_RDWR + O_TRUNC, 0644);
		dup2(v -> in, 0);
		dup2(v -> out, 1);
		while (*(v -> ways) != 0 && execve(*(v -> ways), \
		v -> split, envp) == -1)
			(v -> ways)++;
	}
	else
		wait(0);
	del_matrix(v -> ways);
	del_matrix(v -> split);
}

void	multiply_doc(char **envp, t_wtf *v)
{
	cat_doc(envp, v);
	v -> ways = find_ways(envp, *(v -> kek));
	v -> split = ft_split(*(v -> kek), ' ');
	v -> pid = fork();
	if (v -> pid == 0)
	{
		v -> in = open("!BUF!", O_CREAT + O_RDONLY, 0644);
		v -> out = open("!OUT!", O_CREAT + O_RDWR + O_TRUNC, 0644);
		dup2(v -> in, 0);
		dup2(v -> out, 1);
		while (*(v -> ways) != 0 && execve(*(v -> ways), \
		v -> split, envp) == -1)
			(v -> ways)++;
		if (*(v -> ways) == 0)
		{
			write(2, "netu takoy komandi, durik: ", 27);
			write(2, *(v -> kek), ft_strlen(*(v -> kek)));
			write(2, "\n", 1);
			exit(EXIT_SUCCESS);
		}
	}
	else
		wait(0);
	del_matrix(v -> ways);
	del_matrix(v -> split);
}

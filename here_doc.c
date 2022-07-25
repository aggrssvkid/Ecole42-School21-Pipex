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

static int	check(int argc)
{
	if (argc < 6)
	{
		perror("ti durachek wto li?! MALO ARGUMENTOV\n");
		return (0);
	}
	return (1);
}

static void	out_init(char **envp, t_wtf *v)
{
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
	unlink("!BUF!");
}

void	get_buf(t_wtf *v, char **argv)
{
	char	*line;

	v -> in = open("!BUF!", O_CREAT + O_RDWR, 0644);
	write(1, "dolbi po klave>", 15);
	line = get_next_line(0);
	if (ft_strncmp(line, argv[2], ft_strlen(argv[2])) == 0 \
	&& ft_strlen(line) == (ft_strlen(argv[2]) + 1))
	{
		free(line);
		close(v -> in);
		return ;
	}
	while (ft_strncmp(line, argv[2], ft_strlen(argv[2])) != 0 \
	|| ft_strlen(line) != (ft_strlen(argv[2]) + 1))
	{
		write(v -> in, line, ft_strlen(line));
		write(1, "dolbi po klave>", 15);
		free(line);
		line = get_next_line(0);
	}
	close(v -> in);
}

void	here_doc(int argc, char **argv, char **envp, t_wtf *v)
{
	if (check(argc) == 0)
		return ;
	if (access("!BUF!", 0) == 0)
		unlink("!BUF!");
	get_buf(v, argv);
	v -> kek = &argv[3];
	out_init(envp, v);
	v -> kek++;
	while (*(v -> kek) != argv[(v -> size) - 1])
	{
		multiply_doc(envp, v);
		v -> kek++;
	}
	append(argv, v);
	if (access("!BUF!", 0) == 0)
		unlink("!BUF!");
	unlink("!OUT!");
}

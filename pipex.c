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

static int	find_size(char **argv)
{
	int	size;

	size = 0;
	while (*argv != 0)
	{
		size++;
		argv++;
	}
	return (size);
}

static int	check(int argc, char **envp)
{
	if (argc < 5)
	{
		perror("pobolshe argumentov vvedi, durachina\n");
		return (0);
	}
	while (*envp != 0 && ft_strncmp(*envp, "PATH", 4) != 0)
		envp++;
	if (*envp == 0)
	{
		perror("a gde PATH?!\n");
		return (0);
	}
	return (1);
}

static void	just_do_it(int argc, char **argv, char **envp, t_wtf *v)
{
	v -> in = open(argv[1], O_RDONLY);
	if (argc > 4)
		v -> out = open(argv[(v -> size) - 1], \
		O_CREAT + O_RDWR + O_TRUNC, 0644);
	else
		v -> out = open(argv[(v -> size) - 1], O_CREAT + O_RDWR, 0644);
	dup2((v -> out), 1);
	dup2((v -> in), 0);
	if (access(argv[1], 0) == 0)
	{
		while (*(v -> ways) != 0 && execve(*(v -> ways), \
		v -> split, envp) == -1)
			v -> ways++;
		if (*(v -> ways) == 0)
		{
			write(2, "netu takoy komandi, durik: ", 27);
			write(2, *(v -> kek), ft_strlen(*(v -> kek)));
			write(2, "\n", 1);
			exit(EXIT_SUCCESS);
		}
	}
	else
		exit(EXIT_SUCCESS);
}

static void	init_outfile(int argc, char **argv, char **envp, t_wtf *v)
{
	v -> ways = find_ways(envp, *(v -> kek));
	v -> split = ft_split(*(v -> kek), ' ');
	v -> pid = fork();
	if (v -> pid == 0)
		just_do_it(argc, argv, envp, v);
	else
		wait(0);
	del_matrix(v -> ways);
	del_matrix(v -> split);
}

int	main(int argc, char **argv, char **envp)
{
	t_wtf	*v;
	t_wtf	tmp;

	v = &tmp;
	v -> size = find_size(argv);
	if (check(argc, envp) == 0)
		return (0);
	if (ft_strncmp(argv[1], "here_doc", 8) == 0 && ft_strlen(argv[1]) == 8)
	{
		here_doc(argc, argv, envp, v);
		return (0);
	}
	v -> kek = &argv[2];
	if (access(argv[1], 0) != 0)
		perror("takogo file netu kak bi (ツ)\n");
	init_outfile(argc, argv, envp, v);
	v -> kek++;
	while (*(v -> kek) != argv[(v -> size) - 1])
	{
		multiply_func(argv, envp, v);
		(v -> kek)++;
	}
	if (access("!BUF!", 0) == 0)
		unlink("!BUF!");
	return (0);
}

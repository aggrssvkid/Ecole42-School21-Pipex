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

void	del_matrix(char **matrix);

char	**get_mem(char **len)
{
	int		i;
	char	**matrix;

	i = 0;
	while (len[i] != 0)
		i++;
	matrix = malloc ((i + 1) * sizeof(char *));
	return (matrix);
}

char	**modern(char **suda, char **arr, char *str)
{
	int		i;
	char	**kek;
	char	*tmp;

	i = 0;
	while (arr[i] != 0)
	{
		suda[i] = ft_strjoin(arr[i], str);
		tmp = suda[i];
		if (ft_strrchr(tmp, ' ') != 0)
		{
			kek = ft_split(suda[i], ' ');
			tmp = suda[i];
			suda[i] = *kek;
			*kek = tmp;
			del_matrix(kek);
		}
		i++;
	}
	suda[i] = 0;
	return (suda);
}

char	**conc_str(char **ways, char *prog_name)
{
	char	**join;
	char	**end;

	join = get_mem(ways);
	if (join == 0)
		return (0);
	join = modern(join, ways, "/");
	if (join == 0)
		return (0);
	end = get_mem(ways);
	if (end == 0)
	{
		del_matrix(join);
		return (0);
	}
	end = modern(end, join, prog_name);
	del_matrix(join);
	return (end);
}

char	**find_ways(char **env, char *prog_name)
{
	char	*first_str;
	char	**ways;
	char	**kek;

	while (ft_strncmp(*env, "PATH", 4) != 0 && *env != 0)
		env++;
	ways = ft_split(*env, ':');
	if (ways == 0)
		return (0);
	first_str = ft_strdup((*ways) + 5);
	if (first_str == 0)
	{
		del_matrix(ways);
		return (0);
	}
	free(*ways);
	*ways = first_str;
	kek = conc_str(ways, prog_name);
	del_matrix(ways);
	return (kek);
}

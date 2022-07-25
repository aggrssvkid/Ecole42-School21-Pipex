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

#ifndef LIBPIPEX_H
# define LIBPIPEX_H
# define BUFFER_SIZE 10000

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

typedef struct s_wtf
{
	char	**ways;
	char	**kek;
	char	**split;
	int		size;
	int		pid;
	int		in;
	int		out;
}	t_wtf;

typedef struct s_var
{
	char	buffer[BUFFER_SIZE + 1];
	char	*runman;
	char	*tmp;
	char	*fre;
	char	*getline;
	int		n;

}	t_var;

int		main(int argc, char **argv, char **envp);
char	**find_ways(char **env, char *prog_name);
void	del_matrix(char **matrix);
void	multiply_func(char **argv, char **envp, t_wtf *v);
char	*get_next_line(int fd);
void	here_doc(int argc, char **argv, char **envp, t_wtf *v);
void	multiply_doc(char **envp, t_wtf *v);
void	append(char **argv, t_wtf *v);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strrchr(const char *s, int c);

#endif

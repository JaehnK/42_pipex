/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:41:57 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/04 20:10:29 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include "./libft/libft.h"

typedef struct	s_vars
{
	char	**envp;
	char	**argv;
	char	**paths;
	int		argc;
	int		idx;
}	t_vars;

typedef	struct	s_chld
{
	int		fd[2];
	pid_t	*pid;
}	t_chld;

void	ft_error(int num, char *errm);
t_vars	*ft_parse(int argc, char **argv, char **envp);
void	ft_pipex(t_vars *vars);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:30:37 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/18 10:39:31 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

static int	ft_create_child(t_vars *vars, int idx, int prev_fd)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) < 0)
		ft_error(errno, "pipe");
	pid = fork();
	if (pid < 0)
		ft_error(errno, "fork");
	else if (pid == 0)
	{
		if (idx == 2)
			ft_execute(vars, idx, vars->infile_fd, fd[1]);
		else if (idx == vars->argc - 2)
			ft_execute(vars, idx, prev_fd, vars->outfile_fd);
		else
			ft_execute(vars, idx, prev_fd, fd[1]);
	}
	else
	{
		if (prev_fd != -1)
			close(prev_fd);
		close(fd[1]);
		prev_fd = fd[0];
	}
	return (prev_fd);
}

void	ft_pipex(t_vars *vars)
{
	int		idx;
	int		prev_fd;
	int		infile;
	int		outfile;

	idx = 2;
	prev_fd = -1;
	infile = open(vars->argv[1], O_RDONLY);
	outfile = open(vars->argv[vars->argc - 1], \
		O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (outfile < 0)
		ft_error(errno, "Check Outfile");
	vars->infile_fd = infile;
	vars->outfile_fd = outfile;
	while (idx < vars->argc - 1)
		prev_fd = ft_create_child(vars, idx++, prev_fd);
	close(infile);
	close(outfile);
	while (wait(NULL) > 0)
		;
}

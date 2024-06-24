/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:41:31 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/04 20:16:16 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex_bonus.h"

void	ft_error(int num, char *errm)
{
	errno = num;
	perror(errm);
	exit(EXIT_FAILURE);
}

void	ft_heredoc_gnl(t_vars *vars, int fd[2])
{
	char	*line;

	close(fd[0]);
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, vars->argv[2], ft_strlen(vars->argv[2])) == 0 \
			&& line[ft_strlen(vars->argv[2])] == '\n')
			break ;
		if (ft_strncmp(line, "EOF\n", 4) == 0)
			break ;
		write(fd[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(fd[1]);
}

void	ft_heredoc(t_vars *vars)
{
	pid_t	pid;
	int		fd[2];
	int		status;

	if (pipe(fd) < 0)
		ft_error(errno, "pipe");
	pid = fork();
	if (pid < 0)
		ft_error(errno, "Fork Failed");
	if (pid == 0)
	{
		ft_heredoc_gnl(vars, fd);
		exit(EXIT_SUCCESS);
	}
	else
	{
		waitpid(pid, &status, 0);
		close(fd[1]);
		vars->infile_fd = fd[0];
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	*vars;

	vars = ft_parse(argc, argv, envp);
	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", ft_strlen(argv[2])) == 0)
		{
			ft_heredoc(vars);
			ft_pipex(vars, 3);
		}
		else
			ft_pipex(vars, 2);
	}
	else
		ft_error(EINVAL, ft_itoa(argc));
	exit (0);
}

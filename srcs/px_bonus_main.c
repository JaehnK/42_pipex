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

void	ft_heredoc(t_vars *vars)
{
	pid_t	pid;
	int		fd[2];
	char	*line;
	char	*limiter;

	pid = fork();
	pipe(fd[2]);
	limiter = ft_strjoin(vars->argv[3], "\n");
	line = get_next_line(1);
	close(fd[0]);
	while (ft_strncmp(line, limiter, ft_strlen(line)))
	{
		write(fd[1], line, ft_strlen(line));
		free(line);
		line = get_next_line(1);
	}
	close(fd[1]);
}
int	main(int argc, char **argv, char **envp)
{
	t_vars	*vars;

	vars = ft_parse(argc, argv, envp);
	if (argc > 5)
	{
		if (ft_strncmp(argv[2], "here_doc", ft_strlen(argv[2])) == 0)
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

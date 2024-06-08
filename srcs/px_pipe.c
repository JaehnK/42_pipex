/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 17:30:37 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/08 17:30:39 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../pipex.h"

int	ft_redirection_input(char **argv)
{
	int	input_fd;

	close(STDIN_FILENO);
	input_fd = open(argv[1], O_RDONLY);
	return (input_fd);
}

void	ft_pipe(char **argv)
{
	pid_t	pid;
	ssize_t	byts;
	int		fd[2];
	int		i;
	int		status;
	int		input_fd;
	char	buf[30];

	if (pipe(fd) < 0)
		ft_error(errno, "pipe");
	pid = fork();
	if (pid < 0)
		ft_error(ECHILD, "FORK");
	ft_printf("BEFORE FORK\n");
	
	if (pid > 0)
	{
		printf("PARENT GO\n");
		close(fd[0]);
		input_fd = ft_redirection_input(argv);
		while ((byts = read(input_fd, buf, sizeof(buf))) > 0)
			write(fd[1], buf, byts);
		close(input_fd);
		close(fd[1]);
		waitpid(pid, &status, 0);
		ft_printf("parent exit\n");
	}
	else
	{
		ft_printf("CHILD GO\n");
		dup2(fd[0], 3);
		write(1, "WRITEFINISHED\n", 15);
		close(fd[1]);
		close(fd[0]);


		exit(EXIT_SUCCESS);
	}
	
}

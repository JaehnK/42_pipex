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

int	ft_rdr_inpt(char **argv)
{
	int	input_fd;

	close(STDIN_FILENO);
	input_fd = open(argv[1], O_RDONLY);
	return (input_fd);
}

t_chld	*ft_crt_chld(void)
{
	int		fd[2];
	pid_t	pid;
	t_chld	*chld;

	if (pipe(fd) == -1)
		ft_error(EPIPE, "PIPE");
	pid = fork();
	if (pid < 0)
		ft_error(ECHILD, "FORK");
	chld = (t_chld *) malloc(sizeof(chld) * 1);
	if (!chld)
		ft_error(ENOMEM, "chld");
	chld->pid = &pid;
	chld->fd[0] = fd[0];
	chld->fd[1] = fd[1];
	return (chld);
}

void	ft_rd2wrt(int ifd, int ofd)
{
	char	buf[30];
	ssize_t	byts;

	byts = read(ifd, buf, sizeof(buf));
	while (byts > 0)
	{
		ft_printf("%s", buf);
		write(ofd, buf, byts);
		byts = read(ifd, buf, sizeof(buf));
	}
	close(ifd);
	close(ofd);
	ft_printf("rd2wrt end\n");
	return ;
}

void	ft_pipex(t_vars *vars)
{
	int		status; 
	t_chld	*first;

	first = ft_crt_chld();
	if (first->pid > 0)
	{
		close(first->fd[0]);
		ft_rd2wrt(ft_rdr_inpt(vars->argv), first->fd[1]);
		waitpid(*first->pid, &status, 0);
	}
	else
	{
		dup2(first->fd[0], 3);
		ft_rd2wrt(3, STDOUT_FILENO);

		exit(1);
	}

}

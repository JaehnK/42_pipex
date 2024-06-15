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
#include "../includes/pipex.h"

void	ft_error(int num, char *errm)
{
	errno = num;
	perror(errm);
	exit(EXIT_FAILURE);
}

void	ft_check_argc(int argc)
{
	if (argc == 5)
		return ;
	else if (argc != 5)
		ft_error(EINVAL, ft_itoa(argc));
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	*vars;
	pid_t	pid;

	ft_check_argc(argc);
	vars = ft_parse(argc, argv, envp);
	//ft_pipex(vars);
	ft_execve(vars, 2);
	exit (0);
}

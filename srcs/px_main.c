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

static int	ft_check_space(char *cmd)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	while (i < (int) ft_strlen(cmd))
	{
		if (cmd[i++] != 32)
			flag = 0;
	}
	return (flag);
}

static void	ft_check_argc(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc != 5)
		ft_error(EINVAL, ft_itoa(argc));
	while (i < argc)
	{
		if (ft_check_space(argv[i]))
		{
			write(1, "command not found:  \n", 22);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_vars	*vars;

	ft_check_argc(argc, argv);
	vars = ft_parse(argc, argv, envp);
	ft_pipex(vars);
	exit (0);
}

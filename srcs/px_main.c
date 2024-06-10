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
#include "../pipex.h"

void	ft_error(int num, char *errm)
{
	errno = num;
	perror(errm);
	exit(EXIT_FAILURE);
}

void	ft_check_accessible(char **argv)
{
	int	f1;
	int	f2;

	f1 = access(argv[1], R_OK);
	f2 = access(argv[4], W_OK);
	if (f1 == -1)
		ft_error(ENOENT, argv[1]);
	if (f2 == -1)
		ft_error(ENOENT, argv[4]);
	return ;
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

	ft_check_argc(argc);
	ft_check_accessible(argv);
	vars = ft_parse(argc, argv, envp);
	ft_pipex(vars);
	return (0);
}

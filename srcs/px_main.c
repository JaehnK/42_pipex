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
	exit(1);
}

int	ft_check_accessible(char **argv)
{
	int	f1;
	int	f2;

	f1 = access(argv[1], R_OK);
	f2 = access(argv[4], W_OK);
	if (f1 == -1)
		ft_error(ENOENT, argv[1]);
	if (f2 == -1)
		ft_error(ENOENT, argv[4]);
	return (1);
}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		input_fd;
	int		fd[2];

	if (argc != 5)
		ft_error(EINVAL, "five arguments required");
	paths = ft_parse_path(envp);
	ft_check_accessible(argv);
	ft_pipe(argv);
	return (0);
}

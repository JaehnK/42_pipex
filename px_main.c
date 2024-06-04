/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:41:31 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/04 20:56:51 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "pipex.h"

int	ft_check_files(char **argv)
{
	return(1);
}

int	main(int argc, char **argv, char **envp)
{
	if (argc != 4)
	{
		write(1, "Invalid Arguments\n", 19);
		exit(1);
	}
	ft_check_files(argv);
	ft_printf("%d", (int)ft_strlen(argv[1]));
}

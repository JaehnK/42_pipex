/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 13:41:57 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/18 10:55:46 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX__BONUSH
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_vars
{
	char	**envp;
	char	**argv;
	char	**paths;
	int		argc;
	int		infile_fd;
	int		outfile_fd;
}	t_vars;

void	ft_error(int num, char *errm);
t_vars	*ft_parse(int argc, char **argv, char **envp);
void	ft_pipex(t_vars *vars, int idx);
void	ft_execute(t_vars *vars, int idx, int ifd, int ofd);

#endif

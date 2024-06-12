/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_parsepath.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehukim <jaehukim42@student.42gyeong      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 16:31:00 by jaehukim          #+#    #+#             */
/*   Updated: 2024/06/08 16:31:08 by jaehukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/pipex.h"

static char	*ft_left(char *line, int size)
{
	int		i;
	char	*dst;

	i = 0;
	dst = (char *) malloc(sizeof(char) * (ft_strlen(line) - size + 1));
	while (i < ft_strlen(line) - size)
	{
		dst[i] = line[i + size];
		i++;
	}
	dst[i] = '\0';
	free(line);
	return (dst);
}

static char **ft_parse_argv(int argc, char **argv)
{
	int		idx;	
	char	**new_argv;
	
	idx = 0;
	new_argv = (char **) malloc(sizeof(char *) * argc);
	if (!new_argv)
		ft_error(errno, "new_argv");
	while (idx < argc)
	{
		new_argv[idx] = ft_strdup(argv[idx]);
		idx++;
	}
	new_argv[idx] = NULL;
	return (new_argv);
}

static char	**ft_parse_path(char **envp)
{
	int		i;
	char	*tmp;
	char	*first;
	char 	**paths;
	
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", ft_strlen("PATH=")))
		i++;
	tmp = ft_strdup(envp[i]);
	paths = ft_split(tmp, ':');
	paths[0] = ft_left(paths[0], 5);
	free(tmp);
	return (paths);
}

t_vars	*ft_parse(int argc, char **argv, char **envp)
{
	t_vars	*vars;

	vars = (t_vars *) malloc(sizeof(t_vars) * 1);
	if (!vars)
		ft_error(errno, "vars");
	vars->paths = ft_parse_path(envp);
	vars->argv = ft_parse_argv(argc, argv);
	vars->envp = envp;
	vars->argc = argc;
	vars->idx = 0;
	return (vars);
}

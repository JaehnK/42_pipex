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

char	*ft_left(char *line, int size)
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

char	**ft_parse_path(char **envp)
{
	int		i;
	char	*first;
	char 	**paths;
	
	i = 0;
	while (envp[i] && ft_strncmp(envp[i], "PATH=", ft_strlen("PATH=")))
		i++;
	paths = ft_split(envp[i], ':');
	paths[0] = ft_left(paths[0], 5);
	return (paths);
}

int	ft_check_accessible(char **argv)
{
	int	f1;
	int	f2;

	f1 = access(argv[1], R_OK);
	f2 = access(argv[4], W_OK);
	if (f1 + f2 == 0)
		return (1);
	else
		return (0);
}

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
	int		fd[2];
	int		status;
	char	buf[30];

	pid = fork();
	ft_printf("BEFORE FORK\n");
	if (pid > 0)
	{
		printf("PARENT GO\n");
		fd[0] = ft_redirection_input(argv);
		while (!waitpid(pid, &status, WUNTRACED)){}
		ft_printf("parent exit\n");
	}
	else
	{
		printf("CHILD GO\n");
		read(fd[1], buf, sizeof(buf));
		printf("child : %s\n", buf);
	}

}

int	main(int argc, char **argv, char **envp)
{
	char	**paths;
	int		input_fd;
	int		fd[2];

	if (argc != 5)
	{
		errno = 1;
		perror("Argument Count error");
		exit(1);
	}
	paths = ft_parse_path(envp);
	if (ft_check_accessible(argv) == 0)
	{
		perror("File Access Error");
		exit(1);
	}
	input_fd = ft_redirection_input(argv);
	ft_pipe(argv);
}

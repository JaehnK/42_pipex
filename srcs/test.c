#include "../includes/pipex.h"

int main(int argc, char **av, char **envp)
{
	char *argv[] = {"/usr/bin/ls", NULL, NULL};
	execve(argv[0], argv, envp);
}
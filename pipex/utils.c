#include "pipex.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	fork_n_dub(t_ppx *ppx, int ifd, int ofd, int i)
{
	int		ends[2];
	pid_t	child1;

	if (pipe(ends) < 0)
	{
		ft_putstr_fd("Error occurred while creating a pipe\n", 2);
		exit(EXIT_FAILURE);
	}
	dup2(ifd, 0);
	close(ifd);
	if (i == ppx->argc - 3)
		dup2(ofd, 1);
	else
		dup2(ends[1], 1);
	child1 = fork();
	if (child1 == 0)
		execve(ppx->the_path[i - 1], ppx->cmds[i - 1], ppx->envp);
	else
	{
		close(ends[1]);
		waitpid(child1, NULL, 0);
	}
	if (i < ppx->argc - 3)
		return (fork_n_dub(ppx, ends[0], ofd, i + 1));
}

void	create_fds(t_ppx *ppx, char **argv)
{
	ppx->ifd = open(argv[1], O_RDONLY);
	ppx->ofd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (ppx->ifd < 0 || ppx->ofd < 0)
	{
		if (ppx->ifd < 0)
		{
			ft_putstr_fd("Error occurred while reading from the file\n", 2);
			exit(EXIT_FAILURE);
		}
		else if (ppx->ofd < 0)
		{
			ft_putstr_fd("Error occurred while writing to the file\n", 2);
			exit(EXIT_FAILURE);
		}
	}
}

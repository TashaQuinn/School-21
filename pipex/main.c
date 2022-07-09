#include "pipex.h"

int	is_valid(t_ppx *ppx, char *cmd, int n)
{
	int		i;

	i = 0;
	while (ppx->sh_paths[i])
	{
		ppx->the_path[n] = ft_strjoin(ppx->sh_paths[i], '/', cmd);
		if (access(ppx->the_path[n], X_OK) == 0)
			return (0);
		free(ppx->the_path[n]);
		i++;
	}
	return (1);
}

char	*find_paths(char **envp)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			flag = 1;
			return (&envp[i][6]);
		}
		else
			i++;
	}
	if (flag == 0)
	{
		ft_putstr_fd("Error accessing a variable PATH", 2);
		exit(EXIT_FAILURE);
	}
	return (NULL);
}

void	parse_cmds(t_ppx *ppx, char **argv, char **envp)
{
	int	i;

	i = 0;
	ppx->sh_paths = ft_split(find_paths(envp), ':');
	while (i < 2)
	{
		ppx->cmds[i] = ft_split(argv[i + 2], ' ');
		if (is_valid(ppx, ppx->cmds[i][0], i) == 1)
		{
			ft_putstr_fd("Invalid command\n", 2);
			free_array(ppx->sh_paths);
			while (i--)
				free_array(ppx->cmds[i]);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	ppx->cmds[i] = NULL;
}

void	last_free(t_ppx *ppx)
{
	int	i;

	i = 0;
	free_array(ppx->sh_paths);
	while (i < 2)
		free(ppx->the_path[i++]);
	free(ppx->the_path);
	i = 0;
	while (ppx->cmds[i])
		free_array(ppx->cmds[i++]);
	free(ppx->cmds);
	free(ppx);
}

int	main(int argc, char **argv, char **envp)
{
	t_ppx	*ppx;
	int		i;

	i = 1;
	if (argc != 5)
	{
		ft_putstr_fd("Incorrect number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	ppx = malloc(sizeof(t_ppx));
	ppx->envp = envp;
	ppx->argc = argc;
	ppx->cmds = malloc(sizeof(char **) * 3);
	ppx->the_path = malloc(sizeof(char *) * 3);
	create_fds(ppx, argv);
	parse_cmds(ppx, argv, envp);
	fork_n_dub(ppx, ppx->ifd, ppx->ofd, i);
	last_free(ppx);
}

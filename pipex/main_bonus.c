#include "pipex_bonus.h"

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

void	parse_cmds(t_ppx *ppx, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (ppx->here == 1)
		j = 1;
	else
		j = 0;
	ppx->sh_paths = ft_split(find_paths(ppx->envp), ':');
	while (j < ppx->argc - 3)
	{
		ppx->cmds[i] = ft_split(argv[j + 2], ' ');
		if (is_valid(ppx, ppx->cmds[i][0], i) == 1)
		{
			ft_putstr_fd("Invalid command\n", 2);
			free_array(ppx->sh_paths);
			while (i--)
				free_array(ppx->cmds[i]);
			exit(EXIT_FAILURE);
		}
		i++;
		j++;
	}
	ppx->cmds[i] = NULL;
}

void	init_ppx(t_ppx *ppx, int argc, char **envp, int flag)
{
	ppx->envp = envp;
	ppx->argc = argc;
	if (flag == 0)
	{
		ppx->here = 0;
		ppx->cmds = malloc(sizeof(char **) * (argc - 2));
		ppx->the_path = malloc(sizeof(char *) * (argc - 2));
	}
	else
	{
		ppx->here = 1;
		ppx->cmds = malloc(sizeof(char **) * (argc - 3));
		ppx->the_path = malloc(sizeof(char *) * (argc - 3));
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_ppx	*ppx;
	int		i;
	int		flag;

	i = 1;
	flag = 0;
	if (argc < is_here(argv[1], &flag))
	{
		ft_putstr_fd("Incorrect number of arguments\n", 2);
		exit(EXIT_FAILURE);
	}
	ppx = malloc(sizeof(t_ppx));
	init_ppx(ppx, argc, envp, flag);
	create_fds(ppx, argv);
	parse_cmds(ppx, argv);
	fork_n_dub(ppx, ppx->ifd, ppx->ofd, i);
	last_free(ppx);
}

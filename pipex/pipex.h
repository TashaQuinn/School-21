#ifndef PIPEX_H
# define PIPEX_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <sys/wait.h>

typedef struct s_ppx
{
	char	**sh_paths;
	char	**the_path;
	char	***cmds;
	int		ifd;
	int		ofd;
	char	**envp;
	int		argc;
}	t_ppx;

void	ft_putstr_fd(char *s, int fd);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *str1, const char *str2, size_t n);
char	*ft_strjoin(char const *s1, char c, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	create_fds(t_ppx *ppx, char **argv);
void	fork_n_dub(t_ppx *ppx, int ifd, int ofd, int i);
void	free_array(char **array);

#endif
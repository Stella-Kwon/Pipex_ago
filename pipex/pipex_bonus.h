#ifndef PIPEX_H
# define PIPEX_H
# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>
# include<string.h>
# include<sys/wait.h>
# include<errno.h>
# include "ft_printf/ft_printf.h"

//# define EXIT_FAILURE 1 //there is already this mecro in stdlib.h
# define EXIT_PATH 1
# define EXIT_ARGC 2
# define EXIT_FOPEN 3
# define EXIT_PFD 4
# define EXIT_EXECUTE 5
# define EXIT_PIPE 6
# define EXIT_STRU 7
# define READ 0 
# define WRITE 1

typedef struct s_arg
{
	int	infile;
	int	outfile;
	char	**env;
	int	**pfd;
	char ***cmds;
	int	count_cmd;
	char	**path;
	int	i;
	int	j;
	char	*temp_path;
	char	*temp_wholepath;
}				t_arg;

// typedef struct s_path
// {
// 	char *temp_path;
//     char *temp_wholepath;
//     int i;
//     int j;
// }			t_path;
/***구조체 https://dojang.io/mod/page/view.php?id=418
 https://rumiamochi.tistory.com/22
*/
//structure itself doesnt work as a global variable.
/*if you dont give pointer then you should
void	init_args(t_arg *arg, int argc, char *argv[], char *envp[])
{
	if (argc != 5)
		exit_with_error(EXIT_FAILURE, "failure by number of arguments", NULL);
	arg->path = init_path(envp);
	arg->envp = envp;
	arg->infile = argv[1];
	arg->cmd_cnt = argc - 3;
	arg->cmd = (char ***)malloc(sizeof(char **) * (arg->cmd_cnt + 1));
	if (arg->cmd == NULL)
		exit_with_error(EXIT_FAILURE, "failure in allocating cmd", NULL);
	arg->cmd[0] = NULL;
	init_cmd(arg, argv);
	arg->outfile = argv[argc - 1];
}
do like this and call it in main first.
*/
//so to keep the value itslef stored at each variables in struct, you should give return vlaue or
// you should give it as pointer so it can hold the value which means need to malloc the structure.
//when it is normal struct then ->  or .  both fine
//but in pointer only t_arg->path is fine.


/********find_path.c********/
int path_find(t_arg *stru);
int add_path(t_arg *stru, int argc);
int count_argv(t_arg *stru, int argc);


#endif
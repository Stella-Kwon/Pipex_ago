/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:18:02 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/21 16:36:20 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_fd(int argc, t_arg *stru)
{
	int	i;

	stru->pfd = (int **)malloc((argc -2) * sizeof(int *));
	if (!stru->pfd)
		error_exit(EXIT_PFD, "FAILURE MALLOCING PFD", NULL);
	i = 1;
	while (i < (argc -2))//not argc -3 : reason is i start with 1
	{
		stru->pfd[i] = (int *)malloc(2 * sizeof(int));
		if (!stru->pfd[i])
			error_exit(EXIT_PFD, "FAILURE MALLOCING PFD[i]", NULL);
		i++;
	}
	return (0);
}
/***need to make logic to close evert time of pfd, so better to use other function***/
// int	pipe_create(int argc, t_arg *stru)
// {
// 	int	i;

// 	i = 0;
// 	pipe_fd(argc,stru);
// 	while (i < stru->count_cmd)// count value si the same as i==1 < argc - 2, but should start with 0 as an index.
// 	{
// 		if (pipe(stru->pfd[i]) == -1)
// 		{
// 			while (0 <= i)
// 			{
// 				close(stru->pfd[i][READ]);
// 				close(stru->pfd[i][WRITE]);
// 				i--;
// 			}
// 			error_exit(EXIT_PIPE, "ERROR with piping", strerror(errno));
// 		}
// 		i++;
// 	}
// 	return (0);
// }
int	pipe_create_and_cmd(int argc, t_arg *stru)
{
	int i;
	
	i = pipe_fd(argc, stru);
	if( i == EXIT_PFD)
		error_exit(EXIT_PFD, "pipe_fd function error", NULL);
	
	if (stru->i== 1)
		infile(arg);
	else
	{
		if (dup2(stru->pfd[i - 1][READ], STDIN_FILENO) < 0)
			exit_with_error(EXIT_FAILURE, strerror(errno), NULL);
		close(stru->pfd[i - 1][READ]);
	}
	if (i == arg.cmd_cnt)
		outfile(arg);
	else
	{
		if (dup2(p[i][WRITE], STDOUT_FILENO) < 0)
			exit_with_error(EXIT_FAILURE, strerror(errno), NULL);
	}
	execve(stru->cmds[stru->i][0], stru->cmds[stru->i], stru->env);
	if (errno == 2)//number 2 일때가 못찾았을때.
		exit_with_error(EXIT_EXECUTE, "command not found", stru->cmds[stru->i][0]);
	else
		exit_with_error(EXIT_EXECUTE, "failure by execve", NULL);
}
// int excution(int argc, char **argv, t_arg *stru)
// {
//     pid_t pid;

//     if (pipe_create(argc, stru) == EXIT_PIPE)
//         error_exit(EXIT_PIPE, "ERROR with piping", strerror(errno));
//     stru->i = 0;
//     while(stru->i++ < stru->count_cmd)
//     {
//         pid = fork();
//         if(pid < 0)
//             exit_error(EXIT_PIPE,"fork failure", strerror(errno));
    
//         if(pid == 0)
//         {
//             if(argv[1])
//             {
//                 if(infile(argc, argv, stru) = EXIT_FOPEN)
//                     error_exit(EXIT_FOPEN, "infile function error", strerror(errno));
// 				else 
// 				{
					
// 				}
//             }
//             if(argv[argc - 1])
//             {
//                if(outfile(argc, argv, stru) = EXIT_FOPEN)
//                     error_exit(EXIT_FOPEN, "outfile function error", strerror(errno));
//             }
//                 execve(stru->cmds[stru->i], stru->cmds[stru->i], stru->env)
//         }
//         else
//         {
            
//         }
//     }

// }
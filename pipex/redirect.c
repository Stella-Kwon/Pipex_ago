/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sukwon <sukwon@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 21:20:42 by sukwon            #+#    #+#             */
/*   Updated: 2023/03/20 10:07:14 by sukwon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int excution(t_arg *stru, char **argv, int argc)
{
    pid_t pid;

    stru->i = 0;
    while(stru->i < stru->count_cmd - 1)
    {
        pid = fork();
        if(pid < 0)
        exit_error(EXIT_FAILURE,"fork failure", strerror(errno));
    
        if(pid == 0)
        {
            while( i < stru->count_cmd) 
            execve(stru->cmds[i], stru->cmds[i], env)
        }
        else
        {
        
        }
    }

}
int child_stdout(int pid, int oldfd, int newfile)
{
    if(pid == 0)
    {
        if(argv)
        dup2(oldfd,newfile);
        close(fd);
        close(fd);
        execve("argv[2]","argv[1]","argv")

    }
    /**/
    return 0;
}

int infile(int argc, char **argv, t_arg *stru)
{
    stru->infile;
    int infile2;
    
    stru->infile = open(argv[1], O_RDONLY);
    if(stru->infile < 0)
        exit_error(EXIT_FOPEN, "No such file or directory", argv[1]);
    infile2 = dup2(infile,STDIN_FILENO);
    if(infile2 < 0)
        exit_error(EXIT_FOPEN,strerror(errno),NULL);
    close(infile);
    return 0;
}

int outfile(int argc, char **argv, t_arg *stru)
{
    int outfile;
    int outfile2;
    
    outfile = open(argv[argc -1], O_WRONLY|O_TRUNC|O_CREAT, 0644);
    if(outfile < 0)
        exit_error(EXIT_FAILURE,,"Permission denied", argv[argc-1]);
    outfile2 = dup2(outfile,STDOUT_FILENO);
    if(outfile2 < 0)
        exit_error(EXIT_FAILURE,strerror(errno), NULL);
    close(outfile);
    return 0;
}
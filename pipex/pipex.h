#ifndef PIPEX_H
# define PIPEX_H
# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>
# include<sys/wait.h>
# include<errno.h>

typedef struct s_fdlist
{
    pid_t pid;
    int fd;
    int FILENO;
}               t_fdlist;
int pipe_create(int fd);
int fork_handling();

#endif
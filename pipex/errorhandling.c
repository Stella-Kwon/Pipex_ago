int pipe_create(int fd)
{
    if(pipe(fd) < 0)
    {
        perror("PIPE ERROR : ");
        return 1;
    }
    return 0;
}

int fork_handling(pid_t pid)ß
{
    pid = fork();
    if(pid == -1)
    {
        perror("FORK ERROR : ");
        return 2;
    }
    return 0;
}
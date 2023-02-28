
int main(int argc, char *argv[])
{
    int fd[2];
    if(pipe_create(fd) == 1)
        exit (1);

    pid_t pid1;
    pid_t pid2;
    if(fork_handling(pid1) == 2 || fork_handling(pid2) == 2)
        exit (2);
    child_stdout();
    child_stdin();
    
    return 0;
}
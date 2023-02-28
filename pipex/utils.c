
int child_stdout(int pid, int oldfd, int newfile)
{
    if(pid == 0)
    {
        dup2(oldfd,newfile);
        close(fd);
        close(fd);
        execve("argv[2]","argv[1]","argv")

    }
    /*https://velog.io/@kyj93790/Pipex-%ED%99%98%EA%B2%BD%EB%B3%80%EC%88%98environment-variable-PATH*/
    return 0;
}
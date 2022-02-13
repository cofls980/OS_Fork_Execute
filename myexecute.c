#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main(int argc, char *argv[]) {
	int pid, waitPid, status;
	char *path = "./mycat";
	char *command[] = {"./mycat", argv[1], NULL};

	if (argc != 2) {
		printf("execute: argc error\n");
		exit(-1);
	}
	
	printf("********** execute start **********\n");
	// make child process 
	// and execute cat (do not use just "cat", use another name)	
	if ((pid = fork()) == 0)
	{
		execv(path, command);
		printf("exec failed\n");
	}
	else if (pid > 0)
	{
		waitPid = wait(&status);
		if (waitPid == -1)
			printf("wait return error\n");
	}
	else
	{
		printf("fork fail\n");
	}
	printf("********** execute finish **********\n");
	return 0;
}

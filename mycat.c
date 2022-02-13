#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {

	int fd; //file descripter
	int res;
	char buf[BUF_SIZE]; //read buffer

	if (argc != 2) { //argc,argv error check
		printf("cat: argc error\n");
		exit(1);
	}

	printf("********** read %s start **********\n", argv[1]);
	
	//open file
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("fail to open %s\n", argv[1]);
		return (0);
	}
	//read file
	while ((res = read(fd, buf, BUF_SIZE)) > 0)
		printf("%s", buf);
	//close file
	close(fd);
	printf("********** read %s finish **********\n", argv[1]);
	return 0;
}

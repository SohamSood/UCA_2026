#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUF_SIZE 1024

int main(int argc, char *argv[]) {
	int inputFd, outputFd, openFlags;
	mode_t fileParams;
	ssize_t numRead;
	char buf[BUF_SIZE];
	if(argc != 3) {
		printf("Usage ./copy <file1> <file2>] \n");
		exit(-1);
	}
	inputFd = open(argv[1], O_RDONLY);
	if(inputFd == -1) {
		printf("Error opening file %s\n",argv[1]);
		exit(-1);
	}
	openFlags = O_CREAT | O_WRONLY | O_TRUNC;
	fileParams = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
	outputFd = open(argv[2], openFlags, fileParams);
	if(outputFd == -1) {
                printf("Error opening file %s\n",argv[1]);
                exit(-1);
        }
	while((numRead = read(inputFd, buf , BUF_SIZE )) > 0 ) {
		if(write(outputFd, buf , numRead) != numRead) {
			printf("error while processing\n");
			exit(-1);
		}
	}	
	close(inputFd);
	close(outputFd);
	return 0;
}

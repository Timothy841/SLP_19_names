#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	int pipew = open("mario", O_WRONLY);
	if (pipew == -1){
		mkfifo("mario", 0644);
		pipew = open("mario", O_WRONLY);
	}
	int piper = open("luigi", O_RDONLY);
	if (piper == -1){
		mkfifo("luigi", 0644);
		piper = open("luigi", O_RDONLY);
	}
	char line[100];
	printf("Changes 'h' to 'H'\n");
	while (1){
		printf("Input:\n");
		fgets(line, 100, stdin);
		write(pipew, line, 100);
		read(piper, line, 100);
		printf("%s", line);
	}
	return 0;
}

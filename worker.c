#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void change(char *line){
	for (int i = 0; i<strlen(line); i++){
		if (line[i] == 'h'){
			line[i] = 'H';
		}
	}
}

int main(){
	int piper = open("mario", O_RDONLY);
	if (piper == -1){
		mkfifo("mario", 0644);
		piper = open("mario", O_RDONLY);
	}
	int pipew = open("luigi", O_WRONLY);
	if (pipew == -1){
		mkfifo("luigi", 0644);
		pipew = open("luigi", O_WRONLY);
	}
	char line[100];
	while (1){
		read(piper, line, 100);
		change(line);
		write(pipew, line, 100);
		printf("Changed input and fed it back\n");
	}
	return 0;
}

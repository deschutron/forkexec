#include <unistd.h>
#include <stdio.h>
#include <string.h>
void showHelp(void);
void forkexec(char*, char**);

int main(int argC, char** argV) {
	if (argC == 1) {
		showHelp();
		return 1;
	}
	if (argV[1][0] == '-' && argV[1][1] == 'h') {
		showHelp();
		if (argC > 2) {
			main(argC - 1, &argV[1]);
		}
	}
	forkexec(argV[1], &argV[1]);
}

void showHelp() {
	printf("forkexec - execute a program in a new process\n");
	printf("forkexec [command [argument ...]]\n");
}

void forkexec(char* fn, char** argV) {
	if (!vfork()) {
		execvp(fn, argV);
	}
}

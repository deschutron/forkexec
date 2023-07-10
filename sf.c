// Silent Forkexec
// Copyright (C) 2007-2008 Alex Wiegand, All rights reserved, for now...

#include <unistd.h>
#include <stdio.h>
#include <string.h>
void showHelp(void);
void forkexec(char*, char**);
char silentFile[] = "/dev/null";

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
	// change where the program's output will go
	// reassigning stdout
	freopen(silentFile, "w", stdout);
	// reassigning stderr
	freopen(silentFile, "w", stderr);
	// run the program in a fork
	forkexec(argV[1], &argV[1]);
}

void showHelp() {
	printf("sf - Silent Forkexec - execute a program in a new process with no output\n");
	printf("sf [command [argument ...]]\n");
}

void forkexec(char* fn, char** argV) {
#ifndef _WIN32
	// !fork() means fork() returned zero,
	// which means that the fork worked and now we're in the child process.
	// Note: it runs fork() when it reads this statement
	if (!fork()) {
		execvp(fn, argV);
	}
#else
	spawnvp(P_NOWAIT, fn, (const char* const*) argV);
#endif
}

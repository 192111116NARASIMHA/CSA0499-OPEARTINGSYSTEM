/* Process creation - fork.c */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
	pid_t	pid;
	int n,i;

	printf("\n Enter a integer");
	scanf("%d",&n);
	pid = fork();

	if (pid < 0)
	{
		printf("Process creation error");
		exit(-1);
	}
	else if (pid == 0)
	{
		printf("Child process:");
		printf("incrementing n in the child process by 2 %d",n+2);
		for(i=0;i<=n;i=i+2)
		{
		 printf(" \t %d",i);
		}
		printf("\nProcess id is %d", getpid());
		printf("\nProcess id of parent is %d\n", getppid());
	}
	else
	{
		printf("\nParent process:");
		printf("incrementing n in the parent process by 4 %d",n+4);
		printf("\nProcess id is %d", getpid());
		printf("\nProcess id of shell is %d\n", getppid());
	}
}

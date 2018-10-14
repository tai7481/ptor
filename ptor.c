/*William Tai
 *CS270, Fall 2018
 *9 October 2018
 *Homework #4 */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>

//Function Prototypes
//void SigHandler(int Sig);

int main(int argc, char *argv[])
{
    int Fork_Rslt;
    int Result = -1;
    char str1[256];
    char str2[256];
    FILE *f1, *f2;

    strcpy(str2, "exit");

    f1 = fopen("ptor-parent-file.txt", "w");
    f2 = fopen("ptor-child-file.txt", "w");

    signal(SIGUSR1, SIG_IGN);
    printf("\nCreating Child Process: ...\n");
    Fork_Rslt = fork();
    
    if (Fork_Rslt < 0)
    {
	printf("Fork unsuccessful...!");
    }
    else if (Fork_Rslt > 0)    //must be parent process
    {
        //signal(SIGUSR1, SIG_IGN);
	sleep(1);
        printf("cmd: ");
	gets(string);
	Result = strcmp(str1, str2);
	if (Result == 0)
	{
	   signal(SIGINT, SIGUSR2);
	   sleep(1);
	
    }
    else			//child process
    {
	signal(SIGINT, SIGUSR1);
}

//void SigHandler(int Sig)
                                                          

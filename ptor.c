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
//void SigHand1(int Sig);	
void ParentProcess(int CHPID);
void ChildProcess();

int main()
{
    int Fork_Rslt;
    
    signal(SIGUSR1, SIG_IGN);
    printf("\nCreating Child Process: ...\n");
    Fork_Rslt = fork();
    
    if (Fork_Rslt < 0)
    {
	printf("Fork unsuccessful...!");
    }
    else if (Fork_Rslt > 0)    //must be parent process
    {
	ParentProcess(Fork_Rslt);	
    }
    else			//child process
    {
	ChildProcess();
    }

    return 0;
}

//void SigHand1(int Sig)
//{
//    if (Sig == SIGUSR1)
//    {
//	printf("Signal Caught!\n");
//    }
//    else if (Sig == SIGUSR2)
//    {
//	 
//}

void ParentProcess(int CHPID)
{
    char str1[256];
    char str2[256];
    FILE *f1;
    FILE *f4;
    int Result = -1;
    
    strcpy(str2, "exit");

    while(Result != 0)
    {
    	signal(SIGUSR1, SIG_IGN);
    	sleep(2);

    	printf("cmd: ");
    	gets(str1);
    	Result = strcmp(str1, str2);
    	if (Result == 0)
    	{
	    signal(SIGINT, SIGUSR2);
	    sleep(5);
	    //waits for child to die
	    exit(status);
     	}

    	f1 = fopen("ptor-parent-file.txt", "a");
    	fprintf(f, str1);

    	signal(SIGINT, SIGUSR1);
    	sleep(5);
    	signal(SIGUSR2, SIG_IGN);

    	fclose(f1);
    	f4 = fopen("ptor-child-file.txt", "r");
    	fgets(str1, 256, f4);
    	printf("%s \n", str1);
    } 
}

void ChildProcess()
{
    FILE *f2;
    FILE *f3;
    int Again = 1;	//boolean for loop
    char str3[256];
    char tstr1[50], tstr2[50], tstr3[50], tstr4[50], tstr5[50], tstr6[50];
    int r1 = r2 = r3 = r4 = r5 = r6 = -1;
    int InvalidCMDcount = 0;

    sleep(5);
    signal(SIGINT, SIGUSR1);
    sleep(5);
    //child termination command
    signal(SIGUSR1, SIG_IGN);
    f2 = fopen("ptor-parent-file.txt", "r");
    fgets(str3);
    r1 = strcmp(str3, tstr1);
    r2 = strcmp(str3, tstr2);
    r3 = strcmp(str3, tstr3);
    r4 = strcmp(str3, tstr4);
    r5 = strcmp(str3, tstr5);
    r6 = strcmp(str3, tstr6);
    fclose(f2);

    while (Again == 1)
    {
    	if (r1 == 0)
    	{
	    //Hamming Distance
	    f3 = fopen("ptor-child-file.txt", "a");
	    fprintf(f3, "Results are: " ... );
	    fclose(f3);
    	}
    	else if (r2 == 0)
    	{
	    //number of one bits tester
	    f3 = fopen("ptor-child-file.txt", "a");
            fprintf(f3, "Results are: " ... );
	    fclose(f3);
    	}
    	else if (r3 == 0)
    	{
	    //Identify longest RLE
	    f3 = fopen("ptor-child-file.txt", "a");
	    fprintf(f3, "Results are: " ... );
	    fclose(f3);
    	}
    	else if (r4 == 0)
    	{
	    //calculate and print to user checksum
	    f3 = fopen("ptor-child-file.txt", "a");
	    fprintf(f3, "Results are: " ... );
	    fclose(f3);
    	}
    	else if (r5 == 0)
    	{
	    //adds two binary numbers together
	    f3 = fopen("ptor-child-file.txt", "a");
	    fprintf(f3, "Results are: " ... );
	    fclose(f3);
    	}
    	else if (r6 == 0)
    	{
	    //message to see number of valid/invalid commands
	    f3 = fopen("ptor-child-file.txt", "a");
	    fprintf(f3, "Results are: " ... );
	    fclose(f3);
    	}
    	else
    	{
	    printf("Invalid Command!\n");
	    InvalidCMDcount++;
	    Again = 1;
        }
    }
    signal(SIGINT, SIGUSR2);
}

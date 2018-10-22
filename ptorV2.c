/*William Tai
 *CS270, Fall 2018
 *9 October 2018
 *Homework #4 */

#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>

//Function Prototypes
//void SigHand1(int Sig);	
void ParentProcess(int PID);
void ChildProcess(int CHPID);
void sighand(int SIGNAL);
void Sighand2(int SIGNAL);
int BakedHam(char str[256]);
int BitCMP(char str[256]);
int REALLY(char str[256]);
int Getsome(char str[256]);
int BinAdd(char str[256]);
int CMDCheck(char str[256]);

//Global Variable for counting invalid commands
int InvalidCMDcount = 0;
int ValidCMDcount = 0;

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
	ParentProcess(0);	
    }
    else			//child process
    {
	ChildProcess(Fork_Rslt);
    }

    return 0;
}

void sighand(int SIGNAL)
{
    printf("Signal Caught %d\n", SIGNAL);
}

void Sighand2(int SIGNAL)
{
    printf("Termination Signal Received\n");
    printf("Exiting with status %d\n", InvalidCMDcount);
    exit(InvalidCMDcount);
}

void ParentProcess(int CHPID)
{
    char str1[256];
    char str2[256];
    char str3[256];
    FILE *f1;
    FILE *f4;
    int Result = -1;
    int ID = CHPID;
    int status;
    
    strcpy(str2, "exit");	//covers lower case exit
    strcpy(str3, "Exit");	//covers Capitalized E for exit command

    while(Result != 0)
    {
    	sleep(5);	//waits for child to send signal
	signal(SIGUSR1, &sighand);

    	printf("cmd: ");
    	gets(str1);
    	Result = strcmp(str1, str2);
	Result = strcmp(str1, str3);
    	if (Result == 0)
    	{
	    //signal(SIGINT, SIGUSR2);
	    status = kill(ID, SIGUSR2);
	    sleep(5);
	    //waits for child to die
	    exit(status);
     	}

    	f1 = fopen("ptor-parent-file.txt", "a");
    	fprintf(f, str1);

    	//signal(SIGINT, SIGUSR1);
    	kill(ID, SIGUSR1);
    	sleep(50);
    	signal(SIGUSR2, &sighand);

    	fclose(f1);
    	f4 = fopen("ptor-child-file.txt", "r");
    	fgets(str1, 256, f4);
    	printf("%s \n", str1);
	Result = 1
    } 
}

void ChildProcess(int PID)
{
    FILE *f2;
    FILE *f3;
    int Again = 1;	//boolean for loop
    char str3[256];
    //char tstr1, tstr2, tstr3, tstr4, tstr5, tstr6;
    int r1 = r2 = r3 = r4 = r5 = r6 = -1;
    int ParentID = PID;

    sleep(5);
    //signal(SIGINT, SIGUSR1);
    kill(ParentID, SIGUSR1);
    sleep(5);
    signal(SIGUSR2, &Sighand2);
    signal(SIGUSR1, &sighand);
    f2 = fopen("ptor-parent-file.txt", "r");
    fgets(str3);
    fclose(f2);

    while (Again == 1)
    {
    	if (str3[0] == 'H')
    	{
	    r1 = BakedHam(str3);
	    f3 = fopen("ptor-child-file.txt", "a");
	    fprintf(f3, "Results are: %d\n", r1);
	    printf("Hamming Distance: %d\n", r1);
	    fclose(f3);
    	}
    	else if (str3[0] == 'O')
    	{
	    r2 = BitCMP(str3);
	    f3 = fopen("ptor-child-file.txt", "a");
            fprintf(f3, "Results are: %d\n", r2);
	    printf("Next Highest is: %d\n", r2);
	    fclose(f3);
    	}
    	else if (str3[0] == 'R')
    	{
	    r3 = REALLY(str3);
	    f3 = fopen("ptor-child-file.txt", "a");
	    fprintf(f3, "Results are: " ... );
	    fclose(f3);
    	}
    	else if (str3[0] == 'X')
    	{
	    r4 = Getsome(str3);
	    f3 = fopen("ptor-child-file.txt", "a");
	    fprintf(f3, "Results are: " ... );
	    fclose(f3);
    	}
    	else if (str3[0] == '+')
    	{
	    r5 = BinAdd(str3);
	    f3 = fopen("ptor-child-file.txt", "a");
	    fprintf(f3, "Results are: %d\n", r5);
	    printf("Results are: %d\n", r5);
	    fclose(f3);
    	}
    	else if (str3[0] == '!')
    	{
	    r6 = CMDCheck(str3);
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
    //signal(SIGINT, SIGUSR2);
    kill(ParentID, SIGUSR2);
    printf("ptor: terminating with status %d\n", InvalidCMDcount);
    exit(InvalidCMDcount);
}

int BakedHam (char str[256])
{
    char Temp[256];
    char sub1[128];
    char sub2[128];
    int i = 2;
    int j = 0;
    int k = 0;
    int count = 0;

    strcpy(Temp, str);
    for (i = 2; i < 256; i++)
    {
	sub1[i-2] = Temp[i];
	if (Temp[i+1] == ' ')
	{
	    j = i + 2;
	    i = 256;
	}
    }
    for (j; j < 256; j++)
    {
	sub2[k] = Temp[j];
	if (Temp[j] == '\0')
	{
	    j = 256;
	}
	k++;
    }

    //Hamming Code
    i = 0;
    while (sub1[i] != '')
    {
	if (sub1[i] != sub2[i])
	{
	    count++;
	}
	i++;
    }

    return count;
}

int BitCMP (char str[256])
{
    char temp[256];
    char numTemp;
    int number;
    unsigned Right1;
    unsigned NextH1bit;
    unsigned Right1Pat;
    unsigned next = 0;

    strcpy(temp, str);

    numTemp = Temp[2];
    number = numTemp - '0';

    Right1 = number & -(signed)number;
    NextH1bit = number + Right1;
    Right1Pat = number ^ NextH1bit;
    Right1Pat = (Right1Pat)/Right1;
    Right1Pat >>= 2;

    next = NextH1bit | Right1Pat;

    return next;
}

int REALLY (char str[256])
{
    
}

int Getsome(char str[256])
{

}

int BinAdd(char str[256])
{
    long bin1, bin2;
    int i = 0, rem = 0, sum[20];
    int j = 2, k = 0, m = 0;
    char temp1[16], temp2[16];
    char str1[256];
    int Result = 0;
    char Results[20];

    strcpy(str1, str);

    for (j; j < 256; j++)
    {
	temp1[j-2] = str1[j];
	if (str1[j] == ' ')
	{
	    k = j+1;
	    j = 256;
	    temp1[k-1] = '\0';
	}
    }
    j = 0;
    for (k; k < 256; k++)
    {
	temp2[j] = str1[k];
	if (str1[k+1] == '\0')
	{
	    temp2[j+1] = '\0';
	    k = 256;
	}
	j++;
    }

    sscanf(temp1, "%d", &bin1);
    sscanf(temp2, "%d", &bin2);

    while (bin1 != 0 || bin2 != 0)
    {
	sum[i++] =(bin1 % 10 + bin2 % 10 + rem) % 2;
	rem =(bin1 % 10 + bin2 % 10 + rem) / 2;
	bin1 = bin1 / 10;
	bin2 = bin2 / 10;
    }

    if (rem != 0)
    {
	sum[i++] = rem;
    }
    --i;

    for (m = 0; m < 20; m++)
    {
	Results[m] = sum[i];
	i--;
    }
    sscanf(Results, "%d", &Result);

    return Result;
}

int CMDCheck()
{

}


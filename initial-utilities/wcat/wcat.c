#include <stdio.h>
#include <stdlib.h>

int main (int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Please restart the program and enter a file name.\n");
        exit(0);
    }
    char c;
    
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) 
    {
        printf("cannot open file\n");
        exit(1);
    }

    for (c = getc(fp); c != EOF; c = getc(fp)) 

        printf("%c", c);

    fclose(fp);
}
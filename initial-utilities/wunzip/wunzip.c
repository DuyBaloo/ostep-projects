#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
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

    int a = 0;
    for (c = getc(fp); c != EOF; c = getc(fp)) 
    {
        if(c > 0 && c < 99999)
        {
            a = c;
            fp += 1;
        }
        if(c > 'a' && c < 'z')
        {
            for(int i = 0; i < a; i++)
            {
                printf("%c", c);
            }

        }
    }
    fclose(fp);
}
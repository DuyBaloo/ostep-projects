#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Please restart the program, enter file name to read from and write to.\n");
        exit(0);
    }
    char c;
    
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) 
    {
        printf("cannot open file\n");
        exit(1);
    }

    int i = 0, j = 0;
    int count[24] = {0};
    char str[24];

    for (c = getc(fp); c != EOF; c = getc(fp)) 
    {
        i = c - 97;
        count[i]++;
    }

    for(i = 0; i < 24; i++)
    {
        if(count[i] != 0)
        {
            str[i] = i + 97;
        }
    }

    char main[30];

    for(i = 0; i < sizeof(str); i++)
    {
        for(j = 0; j < 2 * sizeof(str); j++)
        {
            main[j] = count[i];
            main[j++] = str[i];
        }
    }
    FILE *fp1 = fopen(argv[3], "w");
    fwrite(main, 1, sizeof(main), fp1);

    fclose(fp);
    fclose(fp1);
}

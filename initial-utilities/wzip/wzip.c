#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    // if (argc < 4)
    // {
    //     printf("Please restart the program, enter file name to read from and write to.\n");
    //     exit(0);
        
    // } 
    // else if(argc == 4)
    {
        printf("%d", argc);
        char c;
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            printf("cannot open file\n");
            exit(1);
        }

        int i, j;
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
        
        char str1[100];

        for(i = 0; i < sizeof(str); i++)
        {
            if(count[i] != 0)
            {
                j = 0;
                str1[j] = count[i];
                ++j;
                str1[j] = str[i];
            }
            printf("%c", str1[i]);
        }

        
        FILE *fp1 = fopen(argv[3], "w");
        fwrite(str1, 1, sizeof(str1), fp1);

        fclose(fp);
        fclose(fp1);

        fp = NULL;
        fp1 = NULL;
    }
}

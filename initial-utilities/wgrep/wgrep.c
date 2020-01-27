#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
    if (argc == 1 || argc > 3)
    {
        printf("Please restart the program and enter a file name.\n");
        exit(0);
    }
    else if(argc == 2)
    {
        puts("Input your string:");
        char str[1000];
        fgets(str, sizeof(str), stdin);
        char *comp = strstr(str, argv[1]);

        if(comp != NULL)
        {
            printf("Input string contains search term '%s'.\n", argv[1]);
        }
        else
        {
            puts("Input string does not contain the search term.");
        }
    }
    else
    {  
        FILE *fp = fopen(argv[2], "r");
        if (fp == NULL) 
        {
            printf("cannot open file\n");
            exit(1);
        }

        size_t len = 0;
        fseek(fp, 0L, SEEK_END);
        int sz = ftell(fp);
        rewind(fp);
        int control = 0;
        char str[sz];
        char *b = str;
        char *comp;

        while (control <= sz) 
        {
        getline(&b, &len, fp);
        comp = strstr(b, argv[1]);
        if(comp != NULL)
            {
                printf("%s", b);
            }
            control++;
        }

        fclose(fp);
        fp = NULL;

    }  
}

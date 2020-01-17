#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
    if (argc <= 2)
    {
        printf("Please restart the program and enter a file name.\n");
        exit(0);
    }
    else
    {
        char c;
        
        
        FILE *fp = fopen(argv[2], "r");
        if (fp == NULL) 
        {
            printf("cannot open file\n");
            exit(1);
        }
        int size = sizeof(argv[2]);
        char str[size];
        char *b = str;
        size_t len = 0;
        size_t read;

        
        while ((read = getline(&b, &len, fp)) != -1) 
        {
		    if(argv[1] == strstr(argv[2], b))
            {
                printf("%c", b);
            }
	    }

        fclose(fp); 
    }
    
    
}
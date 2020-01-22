#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (int argc, char *argv[])
{
    if (argc < 3)
    {
        printf("Please restart the program and enter a file name.\n");
        exit(0);
    }
    else
    {  
        FILE *fp = fopen(argv[2], "r");
        if (fp == NULL) 
        {
            printf("cannot open file\n");
            exit(1);
        }
        int size = sizeof(argv[2]);
        size_t len = 0;
        size_t read;
	fseek(fp, 0L, SEEK_END);
	int sz = ftell(fp);
        rewind(fp);
	int control = 0;
	char str[sz];
        char *b = str;
	char *comp;

        while (control <= sz) 
      	{
		read = getline(&b, &len, fp);
		comp = strstr(b, argv[1]);
		if(comp != NULL)
            {
                printf("%s", b);
            }
		control++;
	}

        fclose(fp); 
    }
    
    
}

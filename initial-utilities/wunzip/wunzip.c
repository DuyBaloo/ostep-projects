#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please restart the program and enter a file name.\n");
        exit(0);
    }

    char c, buffer[100];
    
    FILE *fp = fopen(argv[1], "r");
    if (fp == NULL) 
    {
        printf("cannot open file\n");
        exit(1);
    }
    fseek(fp, 0L, SEEK_END);
    int sz = ftell(fp);
    rewind(fp);

    fread(buffer, sz, 1, fp);
    printf("%s\n", buffer);
    fclose(fp);
}
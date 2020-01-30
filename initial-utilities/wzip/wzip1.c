#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Please restart the program, enter file name to read from and write to.\n");
        exit(0);
        
    } 
    else if(argc >= 2)
    {
        int i, j, k = 0;
        char c;
        int arrsize = sizeof(&argv)/sizeof(char);
        int count[100] = {0};
        char str[100];
        FILE *fp[arrsize];
        for(i = 0; i < arrsize; i++)
        {
            fp[i] = fopen(argv[i + 1], "r");
            if (fp[i] == NULL)
            {
                printf("cannot open file\n");
                exit(1);
            }
            

            for (c = getc(fp[i]); c != EOF; c = getc(fp[i])) 
            {
                i = c - 97;
                count[k]++;
                k++;
            }

            
        }
        
        for(i = 0; i < 24; i++)
            {
                if(count[i] != 0)
                {
                    str[k] = i + 97;
                    k++;
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
            }
        
        

        
        FILE *fpp = fopen(argv[arrsize], "w");
        fwrite(str1, 1, sizeof(str1), fpp);
        for(i = 0; i < arrsize; i++)
        {

            fclose(fp[i]);
        }
 
        // fclose(fp1);

        // fp = NULL;
        // fp1 = NULL;
    }

}

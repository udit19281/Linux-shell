#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        struct stat st = {0};
        if (stat(argv[1], &st) == -1)
        {
            mkdir(argv[1], 0700);
        }
        else
        {
            // already exist error
            printf("mkdir: cannot create directory '%s': file exists \n", argv[1]);
        }
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "-v") == 0)
        {
            struct stat st = {0};
            if (stat(argv[2], &st) == -1)
            {
                mkdir(argv[2], 0700);
                printf("mkdir: created directory '%s' \n", argv[2]);
            }
            else
            {
                printf("mkdir: cannot create directory '%s': file exists \n", argv[2]);
            }
        }
        else if (strcmp(argv[1], "-p") == 0)
        {
            struct stat st = {0};
            if (stat(argv[2], &st) == -1)
            {
                mkdir(argv[2], 0700);
            }
        }
        else{
            printf("Error : wrong arguments \n");
            exit(-1);
        }
    }
    else{
      printf("Error : wrong arguments \n");
            exit(-1);   
    }
    return 0;
}

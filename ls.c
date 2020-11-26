#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
int main(int argc, char const *argv[])
{
    /* code */
    struct dirent **namelist;
    int n;
    n = scandir(".", &namelist, NULL, alphasort);

    if (n < 0)
    {
        perror("scandir");
        exit(EXIT_FAILURE);
    }
    else
    {
        if (argc == 1)
        {
            while (n--)
            {
                if (namelist[n]->d_name[0] == '.')
                {
                }
                else
                {
                    printf("%s ", namelist[n]->d_name);
                }
            }
            printf("\n");
        }
        else if (strcmp(argv[1], "-a") == 0)
        {
            while (n--)
            {
                printf("%s ", namelist[n]->d_name);
            }
            printf("\n");
        }
        else if (strcmp(argv[1], "-1") == 0)
        {
            while (n--)
            {
                if (namelist[n]->d_name[0] == '.')
                {
                }
                else
                {
                    printf("%s \n", namelist[n]->d_name);
                }
            }
        }
        else{
            printf("invalid arguments for 'ls' command \n");
            exit(-1);
        }
       
    }
    return 0;
}

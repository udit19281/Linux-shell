#include <stdio.h>
#include<stdlib.h>
#include<string.h>  
int main(int argc, char const *argv[])
{
    if (argc == 2)
    {
        if (remove(argv[1]) == 0)
        {
            printf("Deleted Successfully \n");
        }
        else
        {
            printf("Error while deleting file : '%s' \n", argv[1]);
        }
    }
    else if (argc == 3)
    {
        if (strcmp(argv[1], "-f") == 0)
        {
            remove(argv[2]);
        }
        else if (strcmp(argv[1], "-i") == 0)
        {
            char cho;
            printf("Do you want to remove file '%s' ? (y/n) :", argv[2]);
            scanf("%c", &cho);
            if (cho == 'y')
            {
                if (remove(argv[2]) == 0)
                {
                    printf("Deleted Successfully \n");
                }
                else
                {
                    printf("Error while deleting file :%s \n", argv[2]);
                }
            }
        }
        else{
            // wrong arguments
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

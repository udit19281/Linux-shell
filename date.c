#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        struct tm *pt;
        time_t ti;
        time(&ti);
        pt = localtime(&ti);
        char *ist = asctime(pt);
        int l = strlen(ist);
        if (ist[l - 1] == '\n')
        {
            ist[l - 1] = 0;
        }
        printf("%s IST \n", ist);
    }
    else if (argc == 2)
    {
        if (strcmp(argv[1], "-u") == 0)
        {
            struct tm *ptm;
            time_t ut;
            time(&ut);
            ptm = gmtime(&ut);
            time_t utc = mktime(ptm);
            char *ust = asctime(ptm);
            int L = strlen(ust);
            if (ust[L - 1] == '\n')
            {
                ust[L - 1] = 0;
            }
            printf("%s UTC\n", ust);
        }
         else if(strcmp(argv[1],"-help")==0){
             printf("date : date [-u] [-help] \nprint the system date and time \n");
             printf("Options : \n-u : print Coordinated Universal Time(UTC) \n");
             printf("-help : display the help menu \n");
         }    
         else{
             printf("An Error Occurred while processing 'date' command  \n");
          exit(-1);
         }
    }
    else{
        printf("An Error Occurred while processing 'date' command  \n");
          exit(-1);
    }

    return 0;
}

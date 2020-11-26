#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
int main(int argc, char const *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    
   
    if (argc == 2)
    {
        file = fopen(argv[1], "r");
         if (file == NULL)
    {
        // no file exist
        printf("cat: '%s': No such file \n",argv[1]);
        exit(-1);
    }
        while ((read = getline(&line, &len, file)) != -1)
        {
            printf("%s", line);
        }
        fclose(file);
    }
    else if (argc == 3)
    {
        file = fopen(argv[2], "r");
         if (file == NULL)
    {
        // no file exist
        printf("cat: '%s': No such file \n",argv[2]);
        exit(-1);
    }
        if (strcmp(argv[1], "-E") == 0)
        {
            char line[1024];
            int len=0;
            while(fgets(line,1024,file)!=NULL){
                len=strlen(line);
                  if(line[len-1]=='\n'){line[len-1]=0;}
                printf("%s$ \n",line);
            }
            fclose(file);
        }
        else  if (strcmp(argv[1], "-n") == 0)
        {
            file = fopen(argv[2], "r");
            char line[1024];
            int len=0;
            int i=0;
            while(fgets(line,1024,file)!=NULL){
                len=strlen(line);
                  if(line[len-1]=='\n'){line[len-1]=0;}
                printf("    %d %s \n",i+1,line);
                i++;
            }
            fclose(file);
        }
        else{
            // error 
             printf("Error : wrong arguments \n");
            exit(-1);
        }
    }
    else
    {
         printf("Error : wrong arguments \n");
            exit(-1);
        // invalid arguments error
    }

    return 0;
}

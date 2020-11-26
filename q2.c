#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void echos(char *input[50], int size)
{
if(input[1]==NULL){
  printf("Error in 'echo' no argument given \n");
  return;
}
  if ((input[1] != NULL) && strcmp(input[1], "-n") == 0)
  {
    if(input[2]==NULL){
      printf("Error in 'echo' no argument given \n");
  return;
    }
    for (int k = 2; k < size; ++k)
    {
      printf("%s ", input[k]);
    }
  }
  else if ((input[1] != NULL) && strcmp(input[1], "-E") == 0)
  {
    if(input[2]==NULL){
      printf("Error in 'echo' no argument given \n");
  return;
    }
    for (int k = 2; k < size; ++k)
    {
      printf("%s ", input[k]);
      if (k == size - 1)
      {
        printf("\n");
      }
    }
  }
  else
  {
    for (int k = 1; k < size; ++k)
    {
      printf("%s ", input[k]);
      if (k == size - 1)
      {
        printf("\n");
      }
    }
  }
}
void cdhelp()
{
  printf("cd: cd [-L] [-h] path \nChange the shell working directory.\n");
  printf("Change the current directory to DIR.  The default DIR is the value of the HOME shell variable. \n");
  printf("Options : \n -L:force symbolic links to be followed. \n -h:show help menu \n");
}
void pwdhelp()
{
  printf("pwd: pwd [-P] [h] \nPrint the name of the current working directory.\n");
  printf("Options: \n -P: avoid all symlinks \n -h:show help menu \n");
}
void exithelp()
{
  printf("exit: exit [-n] [-h] \n Exit the shell \n");
  printf("Options: \n -n:Exit the shell with a status of N. \n -h:show help menu \n");
}
int main(int argc, char const *argv[])
{
  char input[50];
  char *arr[50];
  char *history[1000];
  // arr[1]="z";arr[2]="z";
  int hist = 0;

  char s[100];
  char g[100];
  char *current_path = getcwd(g, 100);
  printf("\n \t WELCOME TO THE LINUX SHELL MADE WITH LOVE BY UDIT BHATI 2019281 \n\n");

  while (1)
  {
    int in=0;
    while(arr[in]!=NULL){
arr[in]=NULL;
in++;
    }

    printf("%s $", getcwd(s, 100));
    fgets(input, 50, stdin);

    char *tmp;
    int len = strlen(input);
    if (input[len - 1] == '\n')
    {
      input[len - 1] = 0;
    }
    history[hist++] = strdup(input);

    tmp = strtok(input, " ");
    int i = 0;
    int size = 0;
    arr[i] = tmp;

    while (tmp != NULL)
    {
      arr[i++] = tmp;
      tmp = strtok(NULL, " ");
      size++;
    }
    if (strcmp(arr[0], "echo") == 0)
    {
      echos(arr, size);
    }

    else if (strcmp(arr[0], "cd") == 0)
    {

      // default option
      if ((arr[1] != NULL) && strcmp(arr[1], "-L") == 0)
      {
        if(arr[2]==NULL){
        printf("Error in 'cd' no argument given \n");
    }
    else{
        chdir(arr[2]);
    }
      }
      else if ((arr[1] != NULL) && strcmp(arr[1], "-h") == 0)
      {
        // print help
        
        cdhelp();
        arr[1]=0;
      }

      else if (size == 1)
      {
        // if only cd is specified
        chdir(getenv("HOME"));
      }
      else
      {
        // path followed by cd
        chdir(arr[1]);
      }
    }

    else if (strcmp(arr[0], "pwd") == 0)
    {
      char st[100];
      char *res = getcwd(st, 100);

      if ((arr[1] != NULL) && strcmp(arr[1], "-P") == 0)
      {
        //  default
          if(arr[2]!=NULL){
        printf("Error in 'pwd' no argument needed \n");
    }else{
        printf("%s \n", res);}
      }
      else if ((arr[1] != NULL) && strcmp(arr[1], "-h") == 0)
      {
        //  show help
          if(arr[2]!=NULL){
        printf("Error in 'pwd' no argument needed \n");
    }
    else{
        pwdhelp();
        arr[1]=0;}
      }

      else
      {
        //  only pwd
        printf("%s \n", res);
      }
    }
    else if (strcmp(arr[0], "history") == 0)
    {
      if ((arr[1] != NULL) && strcmp(arr[1], "-d") == 0)
      {
        // delete specific element help
        
        int f = atoi(arr[2]);
        for (int h = f - 1; h < hist-1 ; ++h)
        {
          history[h] = history[h + 1];
        }
        hist--;
        
      }
      else if ((arr[1] != NULL) && strcmp(arr[1], "-c") == 0)
      {
        // clear array
           if(arr[2]!=NULL){
        printf("Error in 'history' no argument needed \n");
    }else{
        hist = 0;}
      }
      else
      {
        // print history
        for (int i = 0; i < hist; ++i)
        {
          printf(" %d  %s \n", i + 1, history[i]);
        }
      }
    }
    else if (strcmp(arr[0], "exit") == 0)
    {
      if(arr[2]==NULL){
      if ((arr[1] != NULL) && strcmp(arr[1], "-n") == 0)
      {
        // exit with exit code n
        exit(atoi(arr[2]));
      }
      else if ((arr[1] != NULL) && strcmp(arr[1], "-h") == 0)
      {
        // show help
        exithelp();
        arr[1]=0;
      }
      else
      {
        // normal exit
        exit(0);
      }
      }
      else{
        printf("Invalid argument with 'exit'\n");
      }
    }

    else if (strcmp(arr[0], "ls") == 0)
    {
      int g = fork();
      if (g < 0)
      {
        printf("Error while forking a child process");
        exit(1);
        // error while making child
      }
      else if (g == 0)
      {
        // child process
        char cdr[100];
        strcpy(cdr,current_path);
        strcat(cdr, "/./ls");

        if ((arr[1] != NULL))
        {
          char *argz[] = {cdr, arr[1]};
          execl(argz[0], argz[0], argz[1], NULL);
        }

        else 
        {
          char *argz[] = {cdr};
          execl(argz[0], argz[0], NULL);
        }
        exit(1);
      }
      else
      {
        wait(NULL);
      }
    }
    else if (strcmp(arr[0], "cat") == 0)
    {
      int f=fork();
      if(f<0){
      printf("Error while forking a child process");
      exit(1);
      }
      else if(f==0){
        // child
           char cdr[100];
           strcpy(cdr,current_path);
        strcat(cdr, "/./cat");
        if((arr[1] != NULL) && (arr[2] != NULL)){
        char *argz[] = {cdr, arr[1],arr[2]};
          execl(argz[0], argz[0], argz[1],arr[2], NULL);
        }
        else if((arr[1] != NULL) ){
          char *argz[] = {cdr, arr[1]};
          execl(argz[0], argz[0], argz[1], NULL);
        }
        else{
          // wrong arguments with mkdir
          printf("An Error Occurred while processing 'cat' command  \n");
          exit(-1);
        }
        exit(0);

      }
      else{
        // parrent
        wait(NULL);
      }
    }
    else if (strcmp(arr[0], "rm") == 0)
    {
      int f=fork();
      if(f<0){
      printf("Error while forking a child process");
      exit(1);
      }
      else if(f==0){
        // child
        char cdr[100];
        strcpy(cdr,current_path);
        strcat(cdr, "/./rm");
        if((arr[1] != NULL) && (arr[2] != NULL)){
        char *argz[] = {cdr, arr[1],arr[2]};
          execl(argz[0], argz[0], argz[1],arr[2], NULL);
        }
        else if((arr[1] != NULL) ){
          char *argz[] = {cdr, arr[1]};
          execl(argz[0], argz[0], argz[1], NULL);
        }
        else{
          // wrong arguments with mkdir
          printf("An Error Occurred while processing 'rm' command  \n");
          exit(-1);
        }
        exit(0);

      }
      else{
        // parrent
        wait(NULL);
      }

    }
    else if (strcmp(arr[0], "mkdir") == 0)
    {
      int f=fork();
      if(f<0){
      printf("Error while forking a child process");
      exit(1);
      }
      else if(f==0){
        // child
           char cdr[100];
           strcpy(cdr,current_path);
        strcat(cdr, "/./mkdir");
        if((arr[1] != NULL) && (arr[2] != NULL)){
        char *argz[] = {cdr, arr[1],arr[2]};
          execl(argz[0], argz[0], argz[1],arr[2], NULL);
        }
        else if((arr[1] != NULL) ){
          char *argz[] = {cdr, arr[1]};
          execl(argz[0], argz[0], argz[1], NULL);
        }
        else{
          // wrong arguments with mkdir
          printf("An Error Occurred while processing 'mkdir' command  \n");
          exit(-1);
        }
        exit(0);
      }
      else{
        // parrent
        wait(NULL);
      }
    }
    else if(strcmp(arr[0],"date")==0){
      int f=fork();
      if(f<0){
      printf("Error while forking a child process");
      exit(1);
      }
      else if(f==0){
        // child
           char cdr[100];
           strcpy(cdr,current_path);
        strcat(cdr, "/./date");
        if((arr[1] != NULL) ){
        char *argz[] = {cdr, arr[1]};
          execl(argz[0], argz[0], argz[1], NULL);
        }
        else if((arr[0] != NULL) ){
          char *argz[] = {cdr, arr[1]};
          execl(argz[0], argz[0], argz[1], NULL);
        }
        else{
          printf("An Error Occurred while processing 'date' command  \n");
          exit(-1);
        }
        exit(0);
      }
      else{
        // parrent
        wait(NULL);
      }
    }
  }
  return 0;
}

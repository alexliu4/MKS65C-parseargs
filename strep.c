#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

//helper: returns # of args in line
int counter(char * line){
  int count = 1, len = strlen(line), i;
  for (i=0; i<=len; i++){
    if (line[i] == ' '){
      count++;
    }
  }
  return count;
}

char ** parse_args( char * line ){
  char ** str = malloc(sizeof(char *) * 6);
  char * s1 = line;
  int i;
  //int flags = counter(line);
  //printf("Num of flags: %d\n", flags);
  for (i = 0; i < 5; i++){
    // printf("DOING STRSEP [%s]\n", strsep( &s1, " " ));
    // printf("The Addition:%s\n", s1);
    str[i] = strsep( &s1, " ");
    //printf("[%s]\n", s1);
  }
  return str;
}

void printer(char ** line){
  int i = 0;
  while (i < 6){
    printf("The %dth element: %s\n",i , line[i]);
    i++;
  }
}

int main(int argc, char * argv[]){
    char command[100] = "la -a -l";
    printf("Type in command: %s\n", command);
    //scanf("%s", command);
    //printf("Num of args: %d\n", counter(command));
    //fgets(command, 20, stdin);
    char ** args = parse_args(command);
    printer(args);
    //executing the command (args[0]) with the flags (args)
    // printf("ARGS[0]: %s\n", args[0]);
    execvp(args[0], args);
  return 0;
}

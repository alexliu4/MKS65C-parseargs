#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int counter(char * line){
  int i = 0;
  int count = 0;
  while (line[i] != NULL) {
    count += (line[i] == ' ');
    i++;
  }
  return count;
}

char ** parse_args( char * line ){
  char ** str = (char **) malloc(200);
  char *s1 = line;
  int i;
  int flags = counter(line) + 1;
  //printf("%d\n", flags);
  for (i = 0; i < flags; i++){
    // printf("DOING STRSEP [%s]\n", strsep( &s1, " " ));
    // printf("The Addition:%s\n", s1);
    str[i] = strsep( &s1, " " );
    //printf("[%s]\n", s1);
  }
  return str;
}

void printer(char ** line, int flags){
  int i = 0;
  while (i < flags){
    printf("The %dth element: %s\n",i , line[i]);
    i++;
  }
}

int main(int argc, char * argv[]){
    char command[100];
    printf("Type in command: ");
    scanf("%s", command);
    // fgets(command, 20, stdin);
    char ** args = parse_args(command);
    printer(args, counter(command)+1);
    //executing the command (args[0]) with the flags (args)
    // printf("ARGS[0]: %s\n", args[0]);
    execvp(args[0], args);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

int flags = 0;

int counter(char * line){
  int i, count;
  for (i = 0, count = 0; line[i]; i++){
    count += (line[i] == ' ');
  }
  return count;
}

char ** parse_args( char * line ){
  char ** str = (char **) malloc(4);
  char *s1 = line;
  int i;
  flags = counter(line) + 1;
  //printf("%d\n", flags);
  for (i = 0; i < flags; i++){
    // printf("DOING STRSEP [%s]\n", strsep( &s1, " " ));
    // printf("The Addition:%s\n", s1);
    str[i] = strsep( &s1, " " );
    //printf("[%s]\n", s1);
  }
  return str;
}

void printer(char ** line){
  int i = 0;
  while (i < flags){
    printf("The %dth element: %s\n",i , line[i]);
    i++;
  }
}

int main(int argc, char * argv[]){
    char command[100];
    printf("Type in command: ");
    // scanf("%s", command);
    fgets(command, 100, stdin);
    char ** args = parse_args(command);
    printer( args );
    //executing the command (args[0]) with the flags (args)
    // printf("ARGS[0]: %s\n", args[0]);
    // char * ans = strcat("/bin/", args[0]);
    // execvp(args[0], args);
    // printf("ERROR: %s\n", strerror(errno));
  return 0;
}

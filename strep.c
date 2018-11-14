#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


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
  int count = counter(line);
  for (i = 0; i <= count; i++){
    //printf("[%s]\n", strsep( &s1, " " ));
    str[0] = &s1;
    //printf("[%s]\n", s1);
  }
  return str;
}

void printer(char ** line){
  int i = 0;
  while (line){
    printf("%s\n", line[i]);
    i++;
  }
}

int main() {
  char line[100] = "ls Puneet Alex";
  printer( parse_args(line) );
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int parse_args( char * line ){
  char *s1 = line;
  if (line){
    printf("[%s]\n", strsep( &s1, " " ));
    printf("[%s]\n", s1);
    parse_args(s1);
  }
  return 0;
}

int main() {
  char line[100] = "ls Puneet Alex";
  parse_args(line);
  return 0;
}

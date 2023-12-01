#include <stdio.h>
#include <string.h>

char* translate[9] = {
  "one",
  "two",
  "three",
  "four",
  "five",
  "six",
  "seven",
  "eight",
  "nine"  
};

int match(char* c) {
  for (int i=0; i<9; i++) {
    if (strncmp(translate[i], c, strlen(translate[i]))) {
      continue;
    }
    return i+1;
  }
  return -1;
}

int main() {
  FILE *f = fopen("input.txt", "r");
  char line[256];
  int sum = 0;

  while (fgets(line, sizeof(line), f)) {
    printf("%s", line);
    for (int i=0;; i++) {
      if (line[i]>='0' && line[i]<='9') {
        sum += (line[i]-'0')*10;
        break;
      }
      int num = match(line+i);
      if (num!=-1) {
        printf("%d ", num);
        sum += num*10;
        break;
      }
    }
    for (int i=strlen(line)-1;; i--) {
      if (line[i]>='0' && line[i]<='9') {
        sum += line[i]-'0';
        break;
      }
      int num = match(line+i);
      if (num!=-1) {
        printf("%d\n", num);
        sum += num;
        break;
      }
    }
  }
  
  printf("\n%d\n", sum);

  fclose(f);
  return 0;
}
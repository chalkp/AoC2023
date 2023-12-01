#include <stdio.h>
#include <string.h>

int main() {
  FILE *f = fopen("input.txt", "r");
  char line[256];
  int sum = 0;

  while (fgets(line, sizeof(line), f)) {
    for (int i=0;; i++) {
      if (line[i]>='0' && line[i]<='9') {
        sum += (line[i]-'0')*10;
        break;
      }
    }
    for (int i=strlen(line)-1;; i--) {
      if (line[i]>='0' && line[i]<='9') {
        sum += line[i]-'0';
        break;
      }
    }
  }
  
  printf("%d", sum);

  fclose(f);
  return 0;
}
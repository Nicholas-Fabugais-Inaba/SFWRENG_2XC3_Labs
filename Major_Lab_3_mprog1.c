#include <stdio.h>

void alphrot(char x[]) {
  int i;
  for(i = 0; x[i] != '\0'; i++) {
    if ('a' <= x[i] && x[i] < 'z')
      x[i] = x[i]-'a'+'B';
    else if (x[i] == 'z')
      x[i] = x[i]-'z'+'A';
    else if ('A' <= x[i] && x[i] < 'Z')
      x[i] = x[i]-'A'+'b';
    else if (x[i] == 'Z')
      x[i] = x[i]-'Z'+'a';
  }
}

int main() {
  char buf[500];

  printf("enter a word ");
  scanf("%s",buf);
  printf("word entered is \"%s\"\n",buf);
  alphrot(buf);
  printf("word after the alphabet was modified \"%s\"\n",buf);
  return 0;
}

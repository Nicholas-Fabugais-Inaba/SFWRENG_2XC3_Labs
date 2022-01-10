#include <stdio.h>
#include <string.h>

int ispalindrome(char x[]) {
  int i, len, mid;
  len = strlen(x);
  mid = len/2;
  for(i = 0; i <= mid; i++) {
    if (x[i] != x[len-i-1])
      return 0;
  }
  return 1;
}

int main() {
  int result;
  char buf[500];

  printf("enter a word ");
  scanf("%s",buf);
  result = ispalindrome(buf);
  if (result == 1)
    printf("the word \"%s\" is a palindrome\n",buf);
  else
    printf("the word \"%s\" is not a palindrome\n",buf);
}

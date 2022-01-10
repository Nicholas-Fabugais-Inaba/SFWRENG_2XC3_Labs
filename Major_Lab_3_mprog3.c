#include <stdio.h>

void init_arr(int x[],int len) {
  int i;
  for(i = 0;i < len;i++) {
    printf("enter value for item with index %d:",i);
    scanf("%d",&x[i]);
  }
}

void add_arr(int x[],int y[],int z[],int len) {
  int i;
  for(i = 0; i < len;i++) z[i]=x[i]+y[i];
}

void sub_arr(int x[],int y[],int z[],int len) {
  int i;
  for(i = 0;i < len;i++) z[i]=x[i]-y[i];
}

void show_arr(int x[],int len) {
  int i;
  for(i = 0;i < len;i++) 
    printf("%d ",x[i]);
  printf("\n");
}

int main() {
  int x[6],y[6],z[6];
  printf("initialize array x of length 3\n");
  init_arr(x,3);
  printf("x: ");
  show_arr(x,3);
  printf("initialize array y of length 3\n");
  init_arr(y,3);
  printf("y: ");
  show_arr(y,3);
  add_arr(x,y,z,3);
  printf("array addition: ");
  show_arr(z,3);
  sub_arr(x,y,z,3);
  printf("array subtraction: ");
  show_arr(z,3);
  printf("initialize array x of length 6\n");
  init_arr(x,6);
  printf("x: ");  
  show_arr(x,6);
  printf("initialize array y of length 6\n");  
  init_arr(y,6);
  printf("y: ");
  show_arr(y,6);
  add_arr(x,y,z,6);
  printf("array addition: ");
  show_arr(z,6);
  sub_arr(x,y,z,6);
  printf("array subtraction: ");
  show_arr(z,6);
  return 0;
}

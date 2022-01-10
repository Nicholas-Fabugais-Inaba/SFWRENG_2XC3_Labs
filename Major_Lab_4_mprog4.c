#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_struct {
  char name_value[10];
  struct node_struct * next;
} NODE;

NODE* new_node(char name[]) {
  NODE* n = (NODE*) malloc(sizeof(NODE));
  strcpy(n->name_value, name); 
  n->next = 0;
}

NODE* insert(NODE* list_start,char name[]) {
  NODE* p;
  if (list_start == 0) {
    list_start = new_node(name);
    return list_start;
  }
  NODE* n = new_node(name);
  if (strcmp(name,list_start->name_value) < 0) {
    n->next = list_start;
    list_start = n;
    return list_start;
  }
  if (strcmp(name,list_start->name_value) == 0) {
    return list_start;
  }
  for(p = list_start;p->next != 0;p = p->next) {
    if (strcmp(name,p->next->name_value) < 0) {
      n->next = p->next;
      p->next = n;
      return list_start;
    }
  }
  p->next = n;
  return list_start;
}  

void show_list(NODE* list_start) {
  NODE* p;
  if (list_start == 0) {
    printf("empty list\n");
    return;
  }
  for(p = list_start; p != 0; p = p->next) {
    printf("%s\n",p->name_value);
  }
}

int main() {
  char name[10];
  NODE* list_start = 0;

  while(1) {
    printf("enter name (less than 9 chars, quit to quit): ");
    scanf("%s",name);
    if (strcmp(name,"quit") == 0) break;
    list_start = insert(list_start,name);
  }
  show_list(list_start);
  return 0;

}

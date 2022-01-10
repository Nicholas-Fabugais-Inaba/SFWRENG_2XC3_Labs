#include <stdio.h>
#include <string.h>
#include <unistd.h>

int peg1[9], peg2[9], peg3[9];

void display_pegs() {

  int i,j;
  
  printf("\n");
  for(i = 8;i >= 0;i--) {
    if (peg1[i] == 0) {
      for(j = 0;j < (10-peg1[i]);j++) {
        printf(" ");
      }
      printf("|");
      for(j = 0;j < (10-peg1[i]);j++) {
        printf(" ");
      }
      printf("  ");      
    } else {
      for(j = 0;j < (10-peg1[i]);j++) { 
        printf(" ");
      }
      for(j = 0;j < peg1[i];j++) { 
        printf("+");
      }
      printf("|");
      for(j = 0;j < peg1[i];j++) { 
        printf("+");
      }
      for(j = 0;j < (10-peg1[i]);j++) {
        printf(" ");
      }
      printf("  ");
    }
    if (peg2[i] == 0) {
      for(j = 0;j < (10-peg2[i]);j++) {
        printf(" ");
      }
      printf("|");
      for(j = 0;j < (10-peg2[i]);j++) {
        printf(" ");
      }
      printf("  ");
    } else {
      for(j = 0;j < (10-peg2[i]);j++) { 
        printf(" ");
      } 
      for(j = 0;j < peg2[i];j++) { 
        printf("+");
      }
      printf("|");
      for(j = 0;j < peg2[i];j++) { 
        printf("+");
      }
      for(j = 0;j < (10-peg2[i]);j++) { 
        printf(" ");
      }
      printf("  ");
    }
    if (peg3[i] == 0) {
      for(j = 0;j < (10-peg3[i]);j++) {
        printf(" ");
      }
      printf("|");
      for(j = 0;j < (10-peg3[i]);j++) {
        printf(" ");
      }
      printf("\n");
    } else {           
      for(j = 0;j < (10-peg3[i]);j++) { 
        printf(" ");
      }
      for(j = 0;j < peg3[i];j++) { 
        printf("+");
      }
      printf("|");
      for(j = 0;j < peg3[i];j++) { 
        printf("+");
      }
      for(j = 0;j < (10-peg3[i]);j++) { 
        printf(" "); 
      }
      printf("\n");
    }
  }
  for(i = 0;i < 3;i++) { 
    printf("XXXXXXXXXXXXXXXXXXXXX  ");
  }
  printf("\n");
  
}

void move(int pegA[9],int pegB[9]) {
  int i,j;
  for(i = 8;i >= 0;i--) {
    if (pegA[i] != 0) {
      for(j = 0;j < 9;j++) {
        if (pegB[j] == 0) {
          pegB[j] = pegA[i];
          pegA[i] = 0;
          break;
        }
      }
      break;
    }
  }
  display_pegs();
  sleep(1);
}

void hantow(int nod,int pego[9],int pegd[9],int pegh[9]) {
  if (nod > 1) hantow(nod-1,pego,pegh,pegd);
  move(pego,pegd);
  if (nod > 1) hantow(nod-1,pegh,pegd,pego);
}

int main(int argc,char* argv[]) {

  int i;

  if (argc != 2) {
    printf("incorrect number of command line arguments\n");
    return 0;
  }

  if (strlen(argv[1]) != 1) {
    printf("wrong command line argument\n");
    return 0;
  }

  if (argv[1][0] < '1' || argv[1][0] > '9') {
    printf("wrong command line argument\n");
    return 0;
  }

  int num_of_disks = argv[1][0]-'0';
  int nod = num_of_disks;
  for(i = 0;i < 9;i++) {
    peg1[i] = 0;
    peg2[i] = 0;
    peg3[i] = 0;
  }
  for(i = 0;i < num_of_disks;i++) {
    peg1[i] = nod;
    if (nod != 0) nod--;
  }

  display_pegs();
  
  hantow(num_of_disks,peg1,peg2,peg3);
  printf("done\n");
}

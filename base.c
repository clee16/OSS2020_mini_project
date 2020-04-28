#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "base.h"

int createOriginal(Member* memlist[], int** count){
  char str[100];
  FILE* fp1 = fopen("origin.txt","rt");// already existed file
  FILE* fp2 = fopen("data.txt","wt");// new file to contain already existed file's information

  char a[10],b[10],c[20];
  int d;

  while(!feof(fp1)){
    fscanf(fp1,"%s %s %s %d\n",a,b,c,&d);

    memlist[**count]=(Member*)malloc(sizeof(Member));
    strcpy(memlist[**count]->name,a);
    strcpy(memlist[**count]->id,b);
    strcpy(memlist[**count]->major,c);
    memlist[**count]->activity = d;

    fprintf(fp2,"%s %s %s %d\n",memlist[**count]->name,memlist[**count]->id,memlist[**count]->major,memlist[**count]->activity);
    
    (**count)++;
  }

  fclose(fp1);
  fclose(fp2);
  return **count;
  
}
/////////////////////////////////////////////////////////
int add_user(Member* memlist[], int** count, int plus){
  for(int i=0;i<plus;i++){
      memlist[**count]=(Member*)malloc(sizeof(Member));
      printf("Entering member[%d] info.[format: name id major the#ofActivity]: ",**count+1);
      scanf("%s %s %s %d",memlist[**count]->name,memlist[**count]->id,memlist[**count]->major,&memlist[**count]->activity);
      (**count)++;
    }
    return **count;
}
/////////////////////////////////////////////////////////
int check_user(Member* memlist[], int** count, Member* tempuser){
  int a;
  for(int i=0;i<**count;i++){
    a = strcmp(memlist[i]->name, tempuser->name);
    if(a == 0) return i;
  }
  return -1;
}
/////////////////////////////////////////////////////////
void showMoreInfo(Member* memlist[],int** count,int check){
  printf("\n----------same age----------\n");
  for(int i=0;i<**count;i++){
    if(check == i) continue;
    if(!strncmp(memlist[i]->id,memlist[check]->id,3))
      printf("%s %s %s %d\n",memlist[i]->name,memlist[i]->id,memlist[i]->major,memlist[i]->activity);
  }
  printf("\n----------same major--------\n");
  for(int i=0;i<**count;i++){
    if(check == i) continue;
    if(!strcmp(memlist[i]->major,memlist[check]->major))
      printf("%s %s %s %d\n",memlist[i]->name,memlist[i]->id,memlist[i]->major,memlist[i]->activity);  
  }
  printf("\n----same num. of activity---\n");
  for(int i=0;i<**count;i++){
    if(check ==i) continue;
    if(memlist[i]->activity == memlist[check]->activity)
      printf("%s %s %s %d\n",memlist[i]->name,memlist[i]->id,memlist[i]->major,memlist[i]->activity);  
  }
}
////////////////////////////////////////////////////
void save_list(Member* memlist[],int** count){
  FILE* fp=fopen("data.txt","wt");
    for(int i=0;i<**count;i++){
      fprintf(fp,"%s %s %s %d\n",memlist[i]->name,memlist[i]->id,memlist[i]->major,memlist[i]->activity);
    }
    fclose(fp);
}
////////////////////////////////////////////////////
int load_list(Member* memlist[],int** count){
  int i = 0;
    FILE* fp=fopen("report.txt","wt");
    fprintf(fp,"name     id               major       # of activity\n");
    fprintf(fp,"---------------------------------------------------\n");

    for(i=0;i<**count;i++){
      fprintf(fp,"%-8s %5s %16s\t %5d\n",memlist[i]->name,memlist[i]->id,
      memlist[i]->major,memlist[i]->activity);
      if(feof(fp)) break;
    }

    fprintf(fp,"---------------------------------------------------\n");
    fclose(fp);
    return i;  
}

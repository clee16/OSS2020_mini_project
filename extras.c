#include <stdio.h>
#include <string.h>
#include "extras.h"
#include <stdlib.h>

int ascending(int a,int b){return a-b;};
int descending(int a,int b){return b-a;};
void swap(Member* a,Member* b){
  Member temp = *a;
  *a = *b;
  *b = temp;
}
////////////////////////////////////////////////////////
int delete_user(Member* memlist[],int** count,Member* tempuser){
	int del_index;
  for(int i=0;i<**count;i++){
    if(!strcmp(memlist[i]->name,tempuser->name)){
      del_index = i+1; 
      break;
    }
  }
  for(int i=del_index-1;i<**count-1;i++){
    memcpy(memlist[i],memlist[i+1],sizeof(Member));
  }

  return (**count)-1;
}
//////////////////////////////////////////////
void sorting_ID(Member* memlist[],int left,int right,int(*comp)(int,int)){
  int pivot=left;
	int j=pivot;
	int i=left+1;
	
	if(left<right){
	  for(;i<=right;i++){
      if(comp(atoi(memlist[i]->id),atoi(memlist[pivot]->id))<0){
	      j++;
	      swap(memlist[j],memlist[i]);
	    }
	  }
	  
	  swap(memlist[left],memlist[j]);
	  pivot=j;
	  
	 sorting_ID(memlist,left,pivot-1,comp);
	 sorting_ID(memlist,pivot+1,right,comp);
  }
}
/////////////////////////////////////////
void sorting_Activity(Member* memlist[],int left,int right){
  int pivot=left;
	int j=pivot;
	int i=left+1;
	
	if(left<right){
	  for(;i<=right;i++){
      if(memlist[i]->activity < memlist[pivot]->activity){
	      j++;
	      swap(memlist[j],memlist[i]);
	    }
	  }
	  
	  swap(memlist[left],memlist[j]);
	  pivot=j;
	  
	 sorting_Activity(memlist,left,pivot-1);
	 sorting_Activity(memlist,pivot+1,right);
  }
}
/////////////////////////////////////////////
void show_all(Member* memlist[],int** count){
  printf("Member list\n");
  printf("No. name      id            major      # of activity\n");
  for(int i=0;i<**count;i++){
    printf("%2d %-8s %5s %16s\t %5d\n",i+1,memlist[i]->name,memlist[i]->id,memlist[i]->major,memlist[i]->activity);
  }
}
////////////////////////////////////////////////
void update_information(Member* memlist[],int**count,Member* tempuser){
  int up_index;
  char answer;

  for(int i=0;i<**count;i++){
    if(!strcmp(memlist[i]->name,tempuser->name)){
      up_index = i;
      break;
    }
  }

  printf("Do you want to change %s's Major? [y/n]: ",tempuser->name);
  scanf(" %c",&answer);
  if(answer == 'y'){
    printf("Before: %s\n",memlist[up_index]->major);
    printf("Enter the new major: ");
    scanf("%s",memlist[up_index]->major);
    printf("After: %s\n",memlist[up_index]->major);
  }

  printf("Do you want to change %s's activity number? [y/n]: ",tempuser->name);
  scanf(" %c",&answer);
  if(answer == 'y'){
    printf("Before: %d\n",memlist[up_index]->activity);
    printf("Enter the new activity number: ");
    scanf("%d",&memlist[up_index]->activity);
    printf("After: %d\n",memlist[up_index]->activity);
  }
}
////////////////////////////////////////////////////
void display_statistics(Member* memlist[],int** count,int sortedBy){
  int num=1;
  char str[10];

  if(sortedBy==1){
    for(int i=0;i<**count-1;i++){
      if(!strncmp(memlist[i]->id,memlist[i+1]->id,3)){
        num++;
        if(i==**count-2){
          printf("Id %s~: %d member\n",strncpy(str,memlist[i]->id,3),num);  
        }
      }else{
        printf("Id %s~: %d member\n",strncpy(str,memlist[i]->id,3),num);
        num=1;
        *str = '\0';  
      }
    }
  }
  if(sortedBy==2){
    for(int i=0;i<**count-1;i++){
      if(memlist[i]->activity==memlist[i+1]->activity){
        num++;
        if(i==**count-2){
          printf("Activity %d: %d member\n",memlist[i]->activity,num);  
        }
      }else{
        printf("Activity %d: %d member\n",memlist[i]->activity,num);
        num=1;  
      }
    }
  }
}

/* Advanced search feature
** This feature allows the user to find members by specifying major and # of activities */
void advanced_search(Member* memlist[], int** count) {
	char major[32];		// condition 1
	int activity;		// condition 2
	int found = 0;
	
	printf("Enter the major you want to search: ");
	scanf("%s", major);
	getchar();
	printf("Enter the activity number you want to search: ");	
	scanf("%d", &activity);
	getchar();

	printf("\nSearching.....\n\n");

	printf("Member list\n");
  	printf("No. name      id            major      # of activity\n");		
	for(int i = 0; i < **count; i++) {
		if(!strcmp(memlist[i]->major, major) && memlist[i]->activity == activity) {
			printf("%2d %-8s %5s %16s\t %5d\n",i+1,memlist[i]->name,memlist[i]->id,memlist[i]->major,memlist[i]->activity);
			found = 1;
		}
  	}
	
	if (!found)
		printf("No result found for major = \"%s\" and # of activity = \"%d\"\n", major, activity);
}

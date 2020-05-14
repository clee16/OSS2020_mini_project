#ifndef _EXTRAS_H_
#define _EXTRAS_H_

#include "record.h"

// function prototypes
void swap(Member* a,Member* b);
int ascending(int a,int b);
int descending(int a,int b);

int delete_user(Member* memlist[],int** count,Member* tempuser);
void sorting_ID(Member* memlist[],int left,int right,int(*comp)(int,int));
void sorting_Activity(Member* memlist[],int left,int right);
void show_all(Member* memlist[],int** count);
//////////////////////////////////////////////
void update_information(Member* memlist[],int** count,Member* tempuser);
void display_statistics(Member* memlist[],int** count,int sortedBy);
void advanced_search(Member* memlist[], int** count);
#endif

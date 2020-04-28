#ifndef _BASE_H_
#define _BASE_H_

#include "record.h"

// function prototypes
int createOriginal(Member* memlist[], int** count);
int add_user(Member* memlist[], int** count, int plus);
int check_user(Member* memlist[], int** count, Member* tempuser);
void showMoreInfo(Member* memlist[],int** count,int check);
void save_list(Member* memlist[],int** count);
int load_list(Member* memlist[],int** count);

#endif

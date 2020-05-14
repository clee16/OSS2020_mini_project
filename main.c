#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "base.h"
#include "extras.h"
#include "record.h"

#define MAX_RECORDS 1000

// function prototypes
void input_handler(char input[], Member* memlist[],int* count,Member find,int* isappended);
void display_menu();

// main function
int main(){

	Member* memlist[MAX_RECORDS];
  Member find; // for menu 3(Member search by entering name)
  int user_count = 0; // count the number of records
  int isappended = 0;
	char input[64] = "";

	while(strcmp(input, "99") != 0){
		display_menu();
		printf("\nSelect a menu> ");
    scanf("%s",input);
    getchar();
		//fgets(input, 64, stdin);
		//input[strlen(input)-1] = '\0';
    
		input_handler(input, memlist,&user_count,find,&isappended);
	}

	return 0;
}

void input_handler(char input[], Member* memlist[],int* count,Member find,int* isappended){

	// TODO: Modify this function as you need

	if(!strcmp(input, "1")){
    if(*isappended==1){
      printf("You've already appeded this file.");
      return;
    }
    *isappended = 1;
    printf("Reading information from data file\n");
    *count = createOriginal(memlist,&count);
  }
	else if(!strcmp(input, "2")){
    int plus;
    printf("Adding new Record\n");
    printf("Enter the number you want to add: ");
    scanf("%d",&plus);
    *count = add_user(memlist,&count,plus);
  }	
	else if(!strcmp(input, "3")){
    char answer[10];
    printf("Enter the name you want to find: ");
    scanf("%s",find.name);
    int check = check_user(memlist,&count,&find);
    if(check != -1){
      printf("Member is existing.\n");
      printf("%s %s %s %d\n",memlist[check]->name,memlist[check]->id,memlist[check]->major,memlist[check]->activity);
      printf("More information? [y/n]");
          scanf("%s",answer);
          if(!strcmp(answer,"y")){
            showMoreInfo(memlist,&count,check);
          }
    }else{
      printf("Member is not existing.\n");
    }
  }
	else if(!strcmp(input, "4")){
    save_list(memlist,&count);
    printf("Success: Saving to data.txt\n");
  }
  else if(!strcmp(input, "5")){
    printf("Reading %d member(s) from data.txt, and Saving to report.txt successfully.\n",load_list(memlist,&count));
  }
  else if(!strcmp(input, "6")){
    printf("Enter the name you want to delete: ");
    scanf("%s",find.name);
    *count = delete_user(memlist,&count,&find);
    show_all(memlist,&count);
  }
  else if(!strcmp(input, "7")){
    printf("Ascending order: press 'a' key\nDescending order: press 'd' key: ");
    char choice;
    scanf("%c",&choice);
    if(choice == 'a'){
      sorting_ID(memlist,0,*count-1,ascending);
      show_all(memlist,&count);
      printf("\n");
      display_statistics(memlist,&count,1);
    }else if(choice == 'd'){
      sorting_ID(memlist,0,*count-1,descending);
      show_all(memlist,&count);
      printf("\n");
      display_statistics(memlist,&count,1);
    }else{
      printf("TRY ARAIN: Press 'a' or 'd'\n");
    }   
  }
  else if(!strcmp(input, "8")){
    sorting_Activity(memlist,0,*count-1);
    show_all(memlist,&count);
    printf("\n");
    display_statistics(memlist,&count,2);
  }
  else if(!strcmp(input, "9")){
    printf("Enter a name you want to update: ");
    scanf("%s",find.name);
    update_information(memlist,&count,&find);
    show_all(memlist,&count);
  }
  else if(!strcmp(input, "10")){
    advanced_search(memlist, &count);
  }
  else if(!strcmp(input, "*")){
    show_all(memlist,&count);
  }
	else if(!strcmp(input, "99")){
    for(int i=0;i<*count;i++) free(memlist[i]);
		printf("Disables memory usage...\n");
    printf("Terminating... bye!\n"); // Quit - no operation (an empty statement with a semi-colon)
  }else
		printf("Unknown menu: %s \n\n", input);
}



// Function: display_menu() -> show the entire menu
// Input: none
// Output: none
void display_menu(){

	// TODO: Modify this function as you need
  printf("\n");
	printf("*********************************************\n");
	printf("       Academic Member List Management       \n");
	printf("*********************************************\n");
	printf(" 1. Create a new data record from a data file\n");
	printf(" 2. Create a new member\n");
	printf(" 3. Member search by entering name\n");
	printf(" 4. Save the entire data to data.txt file\n");
	printf(" 5. Export the entire data from data.txt to report.txt\n");
  	printf(" --------------------------------------------\n");
  	printf(" 6. Delete member\n");
	printf(" 7. Sorting by ID\n");
  	printf(" 8. Sorting by Activity\n");
  	printf(" 9. Update information\n");
  	printf("10. Advanced search\n");
	printf(" *. Show current state\n");
  	printf(" --------------------------------------------\n");
  	printf("99. quit\n");
  	printf("*********************************************\n");
}

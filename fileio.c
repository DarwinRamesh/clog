#include <stdio.h>
#include <stdlib.h>
#include "fileio.h"

void writefile(char *sleep){
  
  	FILE *filePtr; //delaring file ptr
  	filePtr = fopen("taskslog.txt", "a"); // w, write, w+ update, a append
  
  	if (filePtr == NULL){
    	printf("Error : Could not open or create the file.\n");
  	}
	
  	fprintf(filePtr, "%s", sleep);

  	printf("Succesfully written task to file\n");

  	fclose(filePtr);
                
	}

void readfile(){

	FILE *filePtr;	
	filePtr = fopen("taskslog.txt", "r");	

	if (filePtr == NULL){
	printf("Error : Could not read file. \n");
	}

	char readFile[100];
	
	while(fgets(readFile, 100, filePtr)) {
	printf("%s", readFile);
	}

	fclose(filePtr);

}

void gettasks(int c){
  	printf("Enter a task, 'q' to finsh, 'r' to read.\n");

  	char task_buffer[256];

 	while(1){
    
    	printf("> ");

    	if (fgets(task_buffer, sizeof(task_buffer), stdin) == NULL){
      	break;
    	}
    	if(task_buffer[0] == 'q' && (task_buffer[1] == '\n' || task_buffer[1] == '\0')) {	
      	break;
    	}
    	if(task_buffer[0] == '\n'){
	printf("Please enter a valid task!\n");
    	}
	if(task_buffer[0] == 'r' && task_buffer[1] == '\n'){
	printf("Reading Files : ");
	readfile();
	}
	else{
	writefile(task_buffer);
	printf("Task captured!\n");
	}
 	}
}


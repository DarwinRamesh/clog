#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fileio.h"

void write_file(char *task_buffer){
  
  	FILE *filePtr; 
  	filePtr = fopen("taskslog.txt", "a"); 
  
  	if (filePtr == NULL){
    		printf("Error : Could not open or create the file.\n");
  	}	 

  	fprintf(filePtr, "%s", task_buffer);
	printf("Task added!\n");

  	fclose(filePtr);
                
	}

void read_file(){

	FILE *filePtr;	
	filePtr = fopen("taskslog.txt", "r");	

	if (filePtr == NULL){
		printf("Error : Could not open or read file. \n");
	}

	char input_buffer[100];
	int array_index = 1;
	
	while(fgets(input_buffer, sizeof(input_buffer), filePtr)) {	
		if (input_buffer[strlen(input_buffer) - 1] == '\n') {
			array_index++;
				if (array_index > 1){
				printf("%d - %s", array_index - 1, input_buffer);
				}

		}
	}	

	fclose(filePtr);

}

void perform_tasks(){
  	printf("Enter a task, 'q' to finsh, 'r' to read, 'R' to remove. \n");

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
			continue;
    		}

		if(task_buffer[0] == 'r' && task_buffer[1] == '\n'){
			printf("Reading Files : \n");
			read_file();
			continue;
		}

		if(task_buffer[0] == 'R' && task_buffer[1] == '\n'){
			printf("Please specify the number of the task you would like to delete.\n");
			remove_tasks();
			continue;
		}

		if(task_buffer[0] != 'q' || task_buffer[0] != '\n' || task_buffer[1] != '\0' || task_buffer[0] != 'r') {
			write_file(task_buffer);
			continue;

		}

 	}
}

void remove_tasks(){
	
	FILE *src_file;
	FILE *temp_file;
	char file_buffer[256];
	int removed_line = 0;
	int current_line = 0;	

	const char *src_file_name = "taskslog.txt";
	const char *temp_file_name = "temp.txt";
	const char *new_file_name = "taskslog.txt";

	src_file = fopen("taskslog.txt", "r");
	temp_file = fopen("temp.txt", "w");

	if (src_file == NULL || temp_file == NULL){
		perror("Error accessing files. Exiting.\n");
		exit(EXIT_FAILURE);
	}

	scanf("%i", &removed_line);

	int c;
	while((c = getchar()) != '\n' && c != EOF);

	while(fgets(file_buffer, sizeof(file_buffer), src_file) != NULL){
		if(current_line != removed_line){	
			fputs(file_buffer, temp_file);	
		}
		
		current_line++;
	}

	fclose(src_file);

	if(remove(src_file_name) == 0){
		printf("File updated!\n");
	}else{
		printf("Couldn't delete file\n'");
	}

	fclose(temp_file);
	rename(temp_file_name, new_file_name);
}


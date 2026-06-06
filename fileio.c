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
                
}

void gettasks(int c){
  printf("Enter a task, 'q' to finsh.\n");

  char task_buffer[256];

  while(1){
    
    printf("> ");

    if (fgets(task_buffer, sizeof(task_buffer), stdin) == NULL){
      break;
    }
    if(task_buffer[0] == 'q' && (task_buffer[1] == '\n' || task_buffer[1] == '\0')) {
      break;
    }
    writefile(task_buffer);
    printf("Task captured.\n");
  }
}

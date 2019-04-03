// author: Yerbolat Amangeldi
#include <unistd.h>
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <string.h>
#include <fcntl.h>

int main(){
    char str[512];
    char *ext = "exit";
    int background = 0;
    int mode = 0;

    while(1){
      printf("Enter a command: ");
      fgets(str, 30, stdin);
      str[strcspn(str, "\n")] = '\0';
      if(strcmp(str, ext) == 0){
        printf("exit!!!!\n");
        exit(0);
      }
      else{
        if(strcmp(str, "") != 0){
          char *argv[64];
          char *p = strtok(str, " ");
          int i = 0;
          pid_t  pid;
          int status;

          while(p != NULL){
            argv[i++] = p;
            p = strtok(NULL, " ");
          }

          // for(int j = 0; j < i; j++){
          //   printf("%d arg: %s; ", j, argv[j]);
          // }
          argv[i] = NULL;

          if(!strcmp(argv[i-1],"&")){
        		background = 1;
        		argv[i-1] = NULL;
        	}
          if(i > 2 && !strcmp(argv[i - 2], ">")) {
            mode = 1; // redirect output & rewrite
          }
          else if(i > 2 && !strcmp(argv[i - 2], "2>")){
            mode = 2; // redirect error
          }

          else if(i > 2 && !strcmp(argv[i - 2], "<")){
            mode = 3; // redirect input
          }

          else if(i > 2 && !strcmp(argv[i - 2], ">>")){
            mode = 4; // redirect output & append
          }

          if ((pid = fork()) < 0) {
          	printf("ERROR: forking child process failed\n");
          	exit(1);
     	    }

          else if (pid == 0) {
        		printf("%d",getpid());
            if(background) {
        			fclose(stdin);
        			fopen("/dev/null", "r");
        			execvp(argv[0], argv);
        		}

            else if(mode == 1){
              close(1);
              char *arg[i];
              for(int k = 0; k < i - 2; k++){
                arg[k] = argv[k];
              }
              arg[i - 2] = NULL;
              fopen(argv[i - 1], "w");
              execvp(arg[0], arg);
            }

            else if(mode == 2){
              close(2);
              char *arg[i];
              for(int k = 0; k < i - 2; k++){
                arg[k] = argv[k];
              }
              arg[i - 2] = NULL;
              fopen(argv[i - 1], "w");
              execvp(arg[0], arg);
            }

            else if(mode == 3){
              close(0);
              char *arg[i];
              for(int k = 0; k < i - 2; k++){
                arg[k] = argv[k];
              }
              arg[i - 2] = NULL;
              fopen(argv[i - 1], "r");
              execvp(arg[0], arg);
            }
            else if(mode == 4){
              close(1);
              char *arg[i];
              for(int k = 0; k < i - 2; k++){
                arg[k] = argv[k];
              }
              arg[i - 2] = NULL;
              fopen(argv[i - 1], "a");
              execvp(arg[0], arg);
            }

            else if (execvp(argv[0], argv) < 0) {
           		printf("ERROR: execution failed\n");
           		exit(1);
          	}
     	    }
     	    else {
        		if (background) {
        			//execvp(*argv, argv);
        		}
            else{
        			waitpid(pid, &status, 0);
        		}
     	    }
        }
      }
      // system(str);
      }

    return 0;
}

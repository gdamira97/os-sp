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
    int pipeExists = 0;
    int pipeIndex = 0;
    int pi[2];
    pipe(pi);


    while(1){
      printf("$: ");
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

          for(int j = 0; j < i; j++){
            if(!strcmp(argv[j],"|")){
              pipeExists = 1;
              pipeIndex = j;
              break;
            }
          }

          argv[i] = NULL;


          if(!strcmp(argv[i-1],"&")){
        		background = 1;
        		argv[i-1] = NULL;
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

            else if(pipeExists){
              close(pi[0]);
              dup2(pi[1], 1);
              char *argc[pipeIndex + 1];
              printf("child\n");
              for(int l = 0; l < 2; l++){
                argc[l] = argv[l];
              }
              argc[2] = NULL;
              execvp(argc[0], argc);
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
                else if(pipeExists){

                  close(pi[1]);
                  dup2(pi[0], 0);

                  char *argp[i - pipeIndex];
                  int range = i - pipeIndex - 1;
                  for(int m = 0; m < range; m++){
                    int inc = m + pipeIndex + 1;
                    argp[m] = argv[inc];
                  }
                  argp[range] = NULL;
                  execvp(argp[0], argp);
                  waitpid(pid, &status, 0);
                }
                else{
                        waitpid(pid, &status, 0);
                    }
     	    }
        }
      }
    }
    return 0;
}

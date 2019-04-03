#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void operation(int, char*, char*);

int main(int argc,char* argv[]){
	char* a = argv[1];
	char* b = argv[2];
	for (int i=0;i<4;i++){
		int rc = fork();
	        if (rc == 0){
        		operation(i,a,b);
                	exit(0);
        	}else if(rc>0){
			 wait(NULL);
		}
	}
    	printf("parent: done\n");
}

void operation(int n,char* a,char* b){
	char *myargs[5];
	if(n==0){
		myargs[0] = "python";
		myargs[1] = "plus.py";		
		myargs[2] = a;		
		myargs[3] = b;
		myargs[4] = NULL;
		execvp(myargs[0], myargs);
	}else if(n==1){
		myargs[0] = "java";
		myargs[1] = "minus";		
		myargs[2] = a;		
		myargs[3] = b;
		myargs[4] = NULL;
		execvp(myargs[0], myargs);
	}else if(n==2){
		myargs[0] = "node";
		myargs[1] = "mul";		
		myargs[2] = a;		
		myargs[3] = b;
		myargs[4] = NULL;
		execvp(myargs[0], myargs);
	}else if(n==3){
		myargs[0] = "bash";
		myargs[1] = "div.sh";		
		myargs[2] = a;		
		myargs[3] = b;
		myargs[4] = NULL;
		execvp(myargs[0], myargs);
	}
}

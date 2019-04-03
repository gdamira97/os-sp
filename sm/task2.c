//Fullname: Dayana Tezekbayeva
//Group: 3EN04B

#include <stdio.h>
#include <math.h>
#include <getopt.h>
#include <string.h>
int main(int argc, char *argv[]){
    int dictionary;
    int option_index = 0;
    
    struct option long_options[] = {
        {"russian",optional_argument,NULL,'r'},
        {"kazakh",optional_argument,NULL,'k'}
    };

    if((dictionary = getopt_long(argc,argv,"kr",long_options,&option_index))!=-1){
        switch(dictionary){
            case 'k':
                printf("salem\n");
                break;
            case 'r':
                printf("privet\n");
                break;
        }
    }else{
        if(strcmp(argv[0],"./saysalem") == 0){
            printf("salem\n");
        }else if (strcmp(argv[0],"./sayprivet") == 0){
            printf("privet\n");
        }else if (strcmp(argv[0],"./sayhi") == 0) {
            printf("sayhi\n");
            
        }
    }
    return 0;
}

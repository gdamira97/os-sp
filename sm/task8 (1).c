//author Yerbolat Amangeldi
#include <stdio.h>
#include <stdlib.h>
int main(){
  int * data;

  data = (int *) malloc(3 * sizeof(int));
  data[0] = 1;
  data[1] = 2;
  data[2] = 3;

  data = (int * ) realloc(data, 5);
  data[3] = 4;
  data[4] = 5;

  for(int i = 0; i < 5; i++){
    printf("%d element is: [%d]\n", i + 1, data[i]);
  }
  free(data);
}

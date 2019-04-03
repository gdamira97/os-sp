//author Yerbolat Amangeldi
#include <stdio.h>
#include <stdlib.h>
int main(){
  int * data = malloc(100 * sizeof(int));
  data[0] = 123;
  free(data);
  printf("0's element is %d\n", data[0]);
}

// when run by default ./task6 output would be
// 0's element is 123

//valgrind output: shows error as
/*
==11368== Command: ./task6
==11368==
==11368== Invalid read of size 4
==11368==    at 0x4005E6: main (task6.c:8)
==11368==  Address 0x5204040 is 0 bytes inside a block of size 400 free'd
==11368==    at 0x4C2EDEB: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==11368==    by 0x4005E1: main (task6.c:7)
==11368==  Block was alloc'd at
==11368==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==11368==    by 0x4005C7: main (task6.c:5)
==11368==
0's element is 123
==11368==
==11368== HEAP SUMMARY:
==11368==     in use at exit: 0 bytes in 0 blocks
==11368==   total heap usage: 2 allocs, 2 frees, 1,424 bytes allocated
==11368==
==11368== All heap blocks were freed -- no leaks are possible
==11368==
==11368== For counts of detected and suppressed errors, rerun with: -v
==11368== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/

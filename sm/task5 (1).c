//author Yerbolat Amangeldi
#include <stdio.h>
#include <stdlib.h>
int main(){
  int * data = malloc(100 * sizeof(int));
  data[100] = 0;
  free(data);
}

// when run by default ./task5 nothing happens

//gdb output: also do not sees any problem
/*
Starting program: /home/hfm/Desktop/splab4-hackerfrommars/task5
[Inferior 1 (process 10908) exited normally]
*/

//valgrind output: detects errors
/*
==10992== Invalid write of size 4
==10992==    at 0x400586: main (task5.c:5)
==10992==  Address 0x52041d0 is 0 bytes after a block of size 400 alloc'd
==10992==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10992==    by 0x400577: main (task5.c:4)
==10992==
==10992==
==10992== HEAP SUMMARY:
==10992==     in use at exit: 0 bytes in 0 blocks
==10992==   total heap usage: 1 allocs, 1 frees, 400 bytes allocated
==10992==
==10992== All heap blocks were freed -- no leaks are possible
==10992==
==10992== For counts of detected and suppressed errors, rerun with: -v
==10992== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/


// even though c allows this kind of maipulations this is very dangerous so the programm is not right!!!

//author Yerbolat Amangeldi
#include <stdio.h>
#include <stdlib.h>
int main(){
	int * p = (int *) malloc(sizeof(int));
	// for task 4 no free(p)
}

//when run by default nothing happens

//gdb output nothing happens
/*
(gdb) run
Starting program: /home/hfm/Desktop/splab4-hackerfrommars/task4
[Inferior 1 (process 10416) exited normally]
*/

// valgrind output detects problem of not free()
/*==10482== HEAP SUMMARY:
==10482==     in use at exit: 4 bytes in 1 blocks
==10482==   total heap usage: 1 allocs, 0 frees, 4 bytes allocated
==10482==
==10482== 4 bytes in 1 blocks are definitely lost in loss record 1 of 1
==10482==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==10482==    by 0x400537: main (task4.c:4)
==10482==
==10482== LEAK SUMMARY:
==10482==    definitely lost: 4 bytes in 1 blocks
==10482==    indirectly lost: 0 bytes in 0 blocks
==10482==      possibly lost: 0 bytes in 0 blocks
==10482==    still reachable: 0 bytes in 0 blocks
==10482==         suppressed: 0 bytes in 0 blocks
==10482==
==10482== For counts of detected and suppressed errors, rerun with: -v
==10482== ERROR SUMMARY: 1 errors from 1 contexts (suppressed: 0 from 0)
*/

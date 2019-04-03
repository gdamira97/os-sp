// Fullname: Kamila Kusainova
// Group: 3EN04A
#include <stdio.h>
#include <stdlib.h>
int main(){
  int * data = malloc(100 * sizeof(int));
  data[3] = 123;
  free(&data[3]);
}


//default output:
/*
*** Error in `./task7': free(): invalid pointer: 0x000000000222701c ***
======= Backtrace: =========
/lib/x86_64-linux-gnu/libc.so.6(+0x777e5)[0x7fec1fe0f7e5]
/lib/x86_64-linux-gnu/libc.so.6(+0x8037a)[0x7fec1fe1837a]
/lib/x86_64-linux-gnu/libc.so.6(cfree+0x4c)[0x7fec1fe1c53c]
./task7[0x40059a]
/lib/x86_64-linux-gnu/libc.so.6(__libc_start_main+0xf0)[0x7fec1fdb8830]
./task7[0x400499]
======= Memory map: ========
00400000-00401000 r-xp 00000000 08:04 52561221                           /home/hfm/Desktop/splab4-hackerfrommars/task7
00600000-00601000 r--p 00000000 08:04 52561221                           /home/hfm/Desktop/splab4-hackerfrommars/task7
00601000-00602000 rw-p 00001000 08:04 52561221                           /home/hfm/Desktop/splab4-hackerfrommars/task7
02227000-02248000 rw-p 00000000 00:00 0                                  [heap]
7fec18000000-7fec18021000 rw-p 00000000 00:00 0
7fec18021000-7fec1c000000 ---p 00000000 00:00 0
7fec1fb82000-7fec1fb98000 r-xp 00000000 08:01 3150521                    /lib/x86_64-linux-gnu/libgcc_s.so.1
7fec1fb98000-7fec1fd97000 ---p 00016000 08:01 3150521                    /lib/x86_64-linux-gnu/libgcc_s.so.1
7fec1fd97000-7fec1fd98000 rw-p 00015000 08:01 3150521                    /lib/x86_64-linux-gnu/libgcc_s.so.1
7fec1fd98000-7fec1ff58000 r-xp 00000000 08:01 3150483                    /lib/x86_64-linux-gnu/libc-2.23.so
7fec1ff58000-7fec20158000 ---p 001c0000 08:01 3150483                    /lib/x86_64-linux-gnu/libc-2.23.so
7fec20158000-7fec2015c000 r--p 001c0000 08:01 3150483                    /lib/x86_64-linux-gnu/libc-2.23.so
7fec2015c000-7fec2015e000 rw-p 001c4000 08:01 3150483                    /lib/x86_64-linux-gnu/libc-2.23.so
7fec2015e000-7fec20162000 rw-p 00000000 00:00 0
7fec20162000-7fec20188000 r-xp 00000000 08:01 3150455                    /lib/x86_64-linux-gnu/ld-2.23.so
7fec20365000-7fec20368000 rw-p 00000000 00:00 0
7fec20384000-7fec20387000 rw-p 00000000 00:00 0
7fec20387000-7fec20388000 r--p 00025000 08:01 3150455                    /lib/x86_64-linux-gnu/ld-2.23.so
7fec20388000-7fec20389000 rw-p 00026000 08:01 3150455                    /lib/x86_64-linux-gnu/ld-2.23.so
7fec20389000-7fec2038a000 rw-p 00000000 00:00 0
7ffcb59c0000-7ffcb59e1000 rw-p 00000000 00:00 0                          [stack]
7ffcb59f8000-7ffcb59fa000 r--p 00000000 00:00 0                          [vvar]
7ffcb59fa000-7ffcb59fc000 r-xp 00000000 00:00 0                          [vdso]
ffffffffff600000-ffffffffff601000 r-xp 00000000 00:00 0                  [vsyscall]
Aborted (core dumped)
*/

// valgrind output:
/*
==11963== Invalid free() / delete / delete[] / realloc()
==11963==    at 0x4C2EDEB: free (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==11963==    by 0x400599: main (task7.c:7)
==11963==  Address 0x520404c is 12 bytes inside a block of size 400 alloc'd
==11963==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==11963==    by 0x400577: main (task7.c:5)
==11963==
==11963==
==11963== HEAP SUMMARY:
==11963==     in use at exit: 400 bytes in 1 blocks
==11963==   total heap usage: 1 allocs, 1 frees, 400 bytes allocated
==11963==
==11963== 400 bytes in 1 blocks are definitely lost in loss record 1 of 1
==11963==    at 0x4C2DB8F: malloc (in /usr/lib/valgrind/vgpreload_memcheck-amd64-linux.so)
==11963==    by 0x400577: main (task7.c:5)
==11963==
==11963== LEAK SUMMARY:
==11963==    definitely lost: 400 bytes in 1 blocks
==11963==    indirectly lost: 0 bytes in 0 blocks
==11963==      possibly lost: 0 bytes in 0 blocks
==11963==    still reachable: 0 bytes in 0 blocks
==11963==         suppressed: 0 bytes in 0 blocks
==11963==
==11963== For counts of detected and suppressed errors, rerun with: -v
==11963== ERROR SUMMARY: 2 errors from 2 contexts (suppressed: 0 from 0)
*/

/*
I think it shows as default or valgrind can help us with this kind of errors.
*/

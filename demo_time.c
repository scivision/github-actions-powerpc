//  https://man7.org/linux/man-pages/man3/__ppc_get_timebase.3.html

#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/platform/ppc.h>

/* Maximum value of the Time Base Register: 2^60 - 1.
  Source: POWER ISA.  */
#define MAX_TB 0xFFFFFFFFFFFFFFF

int main(void){
uint64_t tb1, tb2, diff;

uint64_t freq = __ppc_get_timebase_freq();
printf("Time Base frequency = %"PRIu64" Hz\n", freq);

tb1 = __ppc_get_timebase();

// Do some stuff...

tb2 = __ppc_get_timebase();

if (tb2 > tb1) {
    diff = tb2 - tb1;
} else {
    /* Treat Time Base Register overflow.  */
    diff = (MAX_TB - tb2) + tb1;
}

printf("Elapsed time  = %1.2f usecs\n",
        (double) diff * 1000000 / freq );

return EXIT_SUCCESS;
}

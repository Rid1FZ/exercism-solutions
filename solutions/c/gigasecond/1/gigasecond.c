#include "gigasecond.h"

#include <time.h>

void gigasecond(time_t input, char* output, size_t size)
{
    time_t after_gigasec = input + (time_t)1000000000L;

    struct tm* time_in_tm = gmtime(&after_gigasec);

    strftime(output, size + 1, "%Y-%m-%d %H:%M:%S", time_in_tm);
}

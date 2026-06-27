#include "clock.h"

#include <stdint.h>
#include <stdlib.h>

struct clock {
    uint16_t hour;
    uint16_t minute;
};

static struct clock to_clock(clock_t c)
{
    char* endptr1;
    char* endptr2;

    uint16_t hour = (uint16_t)strtol(c.text, &endptr1, 10);
    uint16_t minute = (uint16_t)strtol(endptr1 + 1, &endptr2, 10);

    return (struct clock){
        .hour = hour,
        .minute = minute,
    };
}

clock_t clock_create(int hour, int minute)
{
    const int seconds_in_day = 86400;

    int64_t total_seconds = (int64_t)hour * 3600 + (int64_t)minute * 60;

    total_seconds %= seconds_in_day;
    if (total_seconds < 0) total_seconds += seconds_in_day;

    int h = (int)(total_seconds / 3600);
    int m = (int)((total_seconds % 3600) / 60);

    clock_t result;

    // the -Werror flag is preventing to use something like `snprintf`. So formatting is being done manually
    result.text[0] = '0' + (h / 10);
    result.text[1] = '0' + (h % 10);
    result.text[2] = ':';
    result.text[3] = '0' + (m / 10);
    result.text[4] = '0' + (m % 10);
    result.text[5] = '\0';

    return result;
}

bool clock_is_equal(clock_t a, clock_t b)
{
    struct clock ca = to_clock(a);
    struct clock cb = to_clock(b);

    return ca.hour * 3600 + ca.minute * 60 == cb.hour * 3600 + cb.minute * 60;
}

clock_t clock_add(clock_t clock, int minute_add)
{
    struct clock c = to_clock(clock);

    return clock_create(c.hour, c.minute + minute_add);
}

clock_t clock_subtract(clock_t clock, int minute_subtract)
{
    struct clock c = to_clock(clock);

    return clock_create(c.hour, c.minute - minute_subtract);
}

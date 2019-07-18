#include "iotAuth_time.h"

/**
 * Return the current time.
 **/
double current_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (double)(tv.tv_sec) + (double)(tv.tv_usec)/1000000.00;
}

/**
 * Given two times, t1 and t2, it calculates the
 * elapsed time between the two events.
 **/
double elapsed_time(double t1, double t2)
{
    return (double)(t2-t1)*1000;
}
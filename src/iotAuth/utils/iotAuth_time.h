#ifndef IOT_AUTH_TIME_H
#define IOT_AUTH_TIME_H

#include <sys/time.h>

/**
 * Return the current time.
 **/
double current_time();

/**
 * Given two times, t1 and t2, it calculates the
 * elapsed time between the two events.
 **/
double elapsed_time(double t1, double t2);

#endif
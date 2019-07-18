#ifndef IOT_AUTH_UTILS_H
#define IOT_AUTH_UTILS_H

#include <stdio.h>      /*  printf, NULL    */
#include <stdlib.h>     /*  srand, rand     */
#include <time.h>       /*  time            */

class IotAuthUtils
{
    public:
        IotAuthUtils();

        /**
         * Generates a random number, with the upper
         * bound specified as a parameter.
         **/
        int generateRandomNumber(int upper_bound);

    private:

        
};

#endif
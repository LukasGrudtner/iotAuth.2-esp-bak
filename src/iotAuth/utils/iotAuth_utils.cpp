#include "iotAuth_utils.h"

IotAuthUtils::IotAuthUtils()
{
    srand(time(NULL));
}

int IotAuthUtils::generateRandomNumber(int upper_bound)
{
    return rand() % upper_bound;
}
#include "iotAuth_client.h"

/**
 * STEP 1
 * Sends request to start the connection
 * to the server.
 **/
void IotAuthClient::send_syn()
{
    sequence = iotAuthUtils.generateRandomNumber(INITIAL_SEQUENCE_VALUE_UPPER_BOUND);
    generateNonce(nonceA);

    iotAuth_syn toSend;
    strncpy(toSend.nonce, nonceA, sizeof(toSend.nonce));

    t1 = current_time();
}
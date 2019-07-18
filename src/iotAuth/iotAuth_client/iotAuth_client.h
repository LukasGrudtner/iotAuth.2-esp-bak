#ifndef IOT_AUTH_CLIENT_H
#define IOT_AUTH_CLIENT_H

#include <Arduino.h>    /* Please disregard this library if you are in the ArduinoIDE. */
#include <string.h>
#include "settings.h"
#include "../utils/iotAuth_utils.h"
#include "../utils/iotAuth_time.h"

#define INITIAL_SEQUENCE_VALUE_UPPER_BOUND 9999

class IotAuthClient
{
    public:
        IotAuthClient();

        /**
         * Establishes connection to the server at the
         * specified address and port. The default port
         * is 8080, defined in settings.h.
         **/
        int connect(char *address, int port=DEFAULT_PORT);

        /**
         * Enters the listening state, waiting for data
         * coming from the server.
         **/
        String listen();

        /**
         * Sends data to the server.
         **/
        int publish(char *data);

        /**
         * Terminates conecction to the server.
         **/
        int disconnect();

        /**
         * Indicates whether or not there is a 
         * connection to the server.
         **/
        bool isConnected();

    private:

        IotAuthUtils iotAuthUtils;

        long sequence;

        /*  Stores the nonce of both parts, A and B. */
        char nonceA[129];
        char nonceB[129];

        /*  Timestamps. */
        double t1, t2;

        /**
         * STEP 1
         * Sends request to start the connection
         * to the server.
         **/
        void send_syn();

        /**
         * STEP 2
         * Receives confirmation from the server
         * regarding step 1.
         **/
        void recv_ack();

        /**
         * Generates a new nonce incrementing the 
         * sequence value.
         **/
        void generateNonce(char *nonce);
};

#endif
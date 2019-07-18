#ifndef SETTINGS_H
#define SETTINGS_H

#define DEFAULT_PORT 8080
#define SYN_VALUE false
#define ACK_VALUE true

typedef enum
{
    // OK,
    DENIED,
    TIMEOUT,
    NO_REPLY,
    INVALID_NONCE,
    INVALID_FDR,
    HASH_INVALID,
    FINISHED,
    NOT_CONNECTED,
} status;

typedef struct syn
{
    bool message = SYN_VALUE;
    char nonce[129];
} iotAuth_syn;

typedef struct ack
{
    bool message = ACK_VALUE;
    char nonceA[129];
    char nonceB[129];
} iotAuth_ack;

#endif
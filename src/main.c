#include <ctype.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "crc.h"

int main()
{
    const char* toto = "A";
    printf("Le CRC16 de A est: 0x%4x\n", crc16_ccitt(toto));
    return 0;
}

#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>



/**
 * Library-level functions.
 * You should use them in the main sections.
 */

uint64_t convertToUint64 (double number)
{
    return *((uint64_t *)(&number));
}

bool getBit (const uint64_t number, const uint8_t index)
{
    uint64_t mask = 1ull << index;
    uint64_t temp = mask & number;
    temp >>= index;

    return temp;
}


/**
 * Checkers here:
 */

bool checkForPlusZero (uint64_t number)
{
    return number == 0x0000000000000000;
}

bool checkForMinusZero (uint64_t number)
{
    return number == 0x8000000000000000;
}

bool checkForPlusInf (uint64_t number)
{
    return number == 0x7FF0000000000000;
}

bool checkForMinusInf (uint64_t number)
{
    return number == 0xFFF0000000000000;
}

bool checkForPlusDenormal (uint64_t number)
{
    // Sign
    if (getBit(number, 63) == 1)
        return false;

    // Exponent
    for (int i = 52; i <= 62 ; ++i)
    {
        if (getBit(number, i) == 1)
            return false;
    }

    // Fraction
    if (getBit(number, 0) == 0)
        return false;

    return true;
}

bool checkForMinusDenormal (uint64_t number)
{
    // Sign
    if (getBit(number, 63) == 0)
        return false;

    // Exponent
    for (int i = 52; i <= 62 ; ++i)
    {
        if (getBit(number, i) == 1)
            return false;
    }

    // Fraction
    if (getBit(number, 0) == 0)
        return false;

    return true;
}

bool checkForSignalingNan (uint64_t number)
{
    // Exponent
    for (int i = 52; i <= 62 ; ++i)
    {
        if (getBit(number, i) == 0)
            return false;
    }

    // Fraction
    if (getBit(number, 0) == 0)
        return false;
    if (getBit(number, 51) == 1)
        return false;

    return true;
}

bool checkForQuietNan (uint64_t number)
{
    // Exponent
    for (int i = 52; i <= 62 ; ++i)
    {
        if (getBit(number, i) == 0)
            return false;
    }

    // Fraction
    if (getBit(number, 51) == 0)
        return false;

    return true;
}

bool checkForPlusNormal (uint64_t number)
{
    // Sign
    if (getBit(number, 63) == 1)
        return false;

    if (checkForPlusZero(number) ||
        checkForMinusZero(number) ||
        checkForPlusInf(number) ||
        checkForMinusInf(number) ||
        checkForPlusDenormal(number) ||
        checkForMinusDenormal(number) ||
        checkForSignalingNan(number) ||
        checkForQuietNan(number)
            )
        return false;

    return true;
}

bool checkForMinusNormal (uint64_t number)
{
    // Sign
    if (getBit(number, 63) == 0)
        return false;

    if (checkForPlusZero(number) ||
        checkForMinusZero(number) ||
        checkForPlusInf(number) ||
        checkForMinusInf(number) ||
        checkForPlusDenormal(number) ||
        checkForMinusDenormal(number) ||
        checkForSignalingNan(number) ||
        checkForQuietNan(number)
            )
        return false;

    return true;
}


void classify (double number)
{
    if (checkForPlusZero(convertToUint64(number)))
    {
        printf("Plus zero\n");
    }

    else if (checkForMinusZero(convertToUint64(number)))
    {
        printf("Minus zero\n");
    }

    else if (checkForPlusInf(convertToUint64(number)))
    {
        printf("Plus inf\n");
    }

    else if (checkForMinusInf(convertToUint64(number)))
    {
        printf("Minus inf\n");
    }

    else if (checkForPlusNormal(convertToUint64(number)))
    {
        printf("Plus normal\n");
    }

    else if (checkForMinusNormal(convertToUint64(number)))
    {
        printf("Minus normal\n");
    }

    else if (checkForPlusDenormal(convertToUint64(number)))
    {
        printf("Plus Denormal\n");
    }

    else if (checkForMinusDenormal(convertToUint64(number)))
    {
        printf("Minus Denormal\n");
    }

    else if (checkForSignalingNan(convertToUint64(number)))
    {
        printf("Signailing NaN\n");
    }

    else if (checkForQuietNan(convertToUint64(number)))
    {
        printf("Quiet NaN\n");
    }

    else
    {
        printf("Error.\n");
    }
}

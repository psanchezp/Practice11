// Autor: Patricio Sanchez
// Matricula: A01191893
// Fecha: 9/19/2016
//
//
//

#include <stdio.h>
#include <string.h>

int binaryToInt (char *c)
{
    int itotal = 0;

    while (*c)
    {
        if (*c - '0' < 0 || *c - '0' > 1)
        {
            printf("Invalid character found returning value\n");
            return itotal;
        }

        itotal*=2;
        if (*c == '1')
        {
            itotal += 1;
        }
        *c ++;
    }

    return itotal;
}

int hextoInt (char *c)
{
    int iTotal = 0;

    while (*c)
    {
        iTotal*=16;
        switch(*c)
        {
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
        case '8':
        case '9':
        case '0':
            {
                iTotal += (*c - '0');
                break;
            }
        case 'a':
            {
                iTotal += 10;
                break;
            }
        case 'b':
            {
                iTotal += 11;
                break;
            }
        case 'c':
            {
                iTotal += 12;
                break;
            }
        case 'd':
            {
                iTotal += 13;
                break;
            }
        case 'e':
            {
                iTotal += 14;
                break;
            }
        case 'f':
            {
                iTotal += 15;
                break;
            }
        default:
            {
                printf("Invalid character\n");
                return -1;
            }
        }
        c++;
    }

    return iTotal;
}

double asciiToDouble (char *c)
{
    double dTotal = 0;
    double dDecimal = 0;
    int iBoolean = 0;
    int iBoolPosNeg;

    if (*c == '-')
    {
        iBoolPosNeg = 1;
        c++;
    }
    else if (*c == '+')
    {
        iBoolPosNeg = 0;
        c++;
    }

    while(*c && iBoolean == 0)
    {
        if (*c == '.')
        {
            iBoolean = 1;
            dDecimal = 1;
        }
        else
        {
            dTotal*=10;
            if (*c - '0' >= 0 && *c - '0' <= 9)
            {
                dTotal += (*c - '0');
            }
            else
            {
                if(iBoolPosNeg)
                {
                    dTotal*=-1;
                }
                printf("Invalid character found returning value\n");
                return dTotal;
            }
        }
        c++;
    }

    //Decimal loop
    while(*c && iBoolean == 1)
    {
        dDecimal/=10;
        if (*c - '0' > 0 && *c - '0' <= 9)
        {
            dTotal += (*c - '0')*dDecimal;
        }
        else
        {
            if(iBoolPosNeg == 1)
            {
                dTotal*=-1.0;
            }
            printf("Invalid character found returning value\n");
            return dTotal;
        }

        c++;
    }

    if (iBoolPosNeg == 1)
    {
        dTotal*=-1.0;
    }

    return dTotal;
}


int main ()
{
    //Variable for display
    int iValue;
    double dValue;
    //Array to get binary input
    char cBinaryInput [33];
    //Array to get hex input
    char cHexInput[9];
    //Array to get decimal input
    char cDecimalInput[32];

    //Input for methods and output
    //Method 1
    printf("Input binary to integer\n");
    scanf("%s", cBinaryInput);
    iValue = binaryToInt(cBinaryInput);
    printf("%i\n", iValue);

    //Method 2
    printf("Input hex to integer (type 'exit' to end program)\n");
    scanf("%s",cHexInput);
    while (strcmp(cHexInput, "exit") != 0)
    {
        iValue = hextoInt(cHexInput);
        printf("%i\n", iValue);
        printf("Input hex to integer (type 'exit' to end program)\n");
        scanf("%s",cHexInput);
    }

    //Method 3
    printf("Input ascii to decimal\n");
    scanf("%s", cDecimalInput);
    dValue = asciiToDouble(cDecimalInput);
    printf("%f\n", dValue);

    return 0;
}

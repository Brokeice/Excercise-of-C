#include <stdio.h>
#include <string.h>

const int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
const char* symbols[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

char * intToRoman(int num){
    char *Roman = (char*)malloc(sizeof(char)*16);
    int i = 0;

    Roman[0] = '\0';
    for(i; i < 13; i++)
    {
        while (num >= values[i])
        {
            num -= values[i];
            strcpy(Roman + strlen(Roman), symbols[i]);
        }
        if (num == 0)
        {
            break;
        }
    }
    return Roman;
}

int main()
{
    char *s = intToRoman(1524);
    printf("%s\r\n", s);
    return 0;
}

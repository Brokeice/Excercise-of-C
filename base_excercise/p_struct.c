#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

struct obj
    {
        int16_t subnum;
        int32_t students;
        int32_t score;
        int32_t sex;
    };

int main()
{
    int32_t *pdata;

    struct obj objects = 
    {
        .subnum = 0xaa,
        .students = 0xbb,
        .score = 0xdd,
        .sex = 0xff
    };

    // 如果没有这一行会产生段错误，因为pdata指向未知内存
    pdata = (int32_t *)malloc(sizeof(struct obj));

    printf("[%s]: %d, struct obj size:%ld\r\n", __func__, __LINE__, sizeof(struct obj));

    memcpy(pdata, ((int32_t *)&objects), 16); // segment fault

    printf("subnum:0x%x, student:0x%x, score:0x%x, sex:0x%x\r\n", (int16_t)*pdata, *(pdata+1), *(pdata+2), *(pdata+3));

    return 0;
}
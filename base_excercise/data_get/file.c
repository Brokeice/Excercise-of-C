#include "linklist.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>


uint32_t string_to_linklist(uint8_t *string, struct node *node_list)
{
    uint8_t buf[32] = {0};
    uint32_t i = 0;
    uint32_t val;
    
    if (!string)
    {
        return 1;
    }

    while((*string) != '\0')
    {
        if ((*string == ' ') || (*string == '\n'))
        {
            string++;
            if ((*string <= '9' && *string >= '0') || (*string == '-'))
            {
                val = atoi(buf);
                i = 0;
                memset(buf, 0, 32);
                add_tail(node_list, val);
                // printf("LINE: [%d] FUN: [%s] val: %d\n", __LINE__, __func__,  val);
            }
            
            continue;
        }

        buf[i++] = *string;
        string++;
    } 
    val = atoi(buf);
    add_tail(node_list, val);
    memset(buf, 0, 32);
    // printf("LINE: [%d] FUN: [%s] val: %d\n", __LINE__, __func__,  val);
       
}

uint32_t main ()
{
   FILE *fp;
   int32_t len;
   uint8_t *pbuf = NULL;
   struct node *mylist;

   list_init(&mylist);

   fp = fopen("data.txt", "r");	//前提该文件必须存在
   if( fp == NULL ) 
   {
      perror ("打开文件错误");
      return 1;
   }

   fseek(fp, 0, SEEK_END);
   len = ftell(fp);
   fseek(fp, 0, SEEK_SET);
   
   //申请内存
   pbuf= (char *) malloc(len);
   memset(pbuf,0,len);
   /* 读取并显示数据 */
   fread(pbuf, len, 1, fp);
//    printf("LINE: [%d] FUN: [%s] show: %s\n", __LINE__, __func__,  pbuf);

   string_to_linklist(pbuf, mylist);
   print_list(mylist);
   
   free(pbuf);

//    int32_t val = sizeof(str);
//    printf("value = %d\n", val);

   fclose(fp);

   printf("file.txt 的总大小 = %d 字节\n", len);
   
   return 0;
}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
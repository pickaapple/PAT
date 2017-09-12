//
//  main1006.cpp
//  PAT1
//
//  Created by yhys on 2017/9/6.
//  Copyright © 2017年 ST Studio. All rights reserved.
//
//1006. 换个格式输出整数 (15)
//
//时间限制
//400 ms
//内存限制
//65536 kB
//代码长度限制
//8000 B
//判题程序
//Standard
//作者
//CHEN, Yue
//让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。
//
//输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。
//
//输出格式：每个测试用例的输出占一行，用规定的格式输出n。
//
//输入样例1：
//234
//输出样例1：
//BBSSS1234
//输入样例2：
//23
//输出样例2：
//SS123
#include <stdio.h>

void hundredsToStr(char* outStr, int hundreds)
{
    while(--hundreds>=0)
    {
        *outStr++ = 'B';
    }
    *outStr = '\0';
}

void tensToStr(char* outStr, int tens)
{
    while(--tens>=0)
    {
        *outStr++ = 'S';
    }
    *outStr = '\0';
}

void onesToStr(char* outStr, int ones)
{
    for(int index = 1 ; index <= ones ; ++index)
    {
        *outStr++ = '0' + index;
    }
    *outStr = '\0';
}

int main(int argc, const char * argv[])
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        int hundreds, tens, ones;
        hundreds = n / 100; //最多三位数
        tens = n % 100 / 10;
        ones = n % 10;
        char outStrOnes[ones + 1];
        onesToStr(outStrOnes, ones);
        if(0 == hundreds && 0 == tens){ //一位数
            printf("%s\n",outStrOnes);
        }else if(0 == hundreds){    //两位数
            
            char outStrTens[tens + 1];
            tensToStr(outStrTens, tens);
            
            printf("%s%s\n", outStrTens, outStrOnes);
        }else{      //三位数
            
            char outStrTens[tens + 1];
            tensToStr(outStrTens, tens);
            
            char outStrHundreds[hundreds + 1];
            hundredsToStr(outStrHundreds, hundreds);
            
            printf("%s%s%s\n", outStrHundreds , outStrTens, outStrOnes);
        }
    };
}

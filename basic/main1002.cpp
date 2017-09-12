//
//  main1002.cpp
//  PAT1
//
//  Created by yhys on 2017/9/6.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

//1002. 写出这个数 (20)
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
//
//读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。
//
//输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。
//
//输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。
//
//输入样例：
//1234567890987654321123456789
//输出样例：
//yi san wu

#include <stdio.h>
const char* digitToStr(int n)
{
    switch (n) {
        case 0:
            return "ling";
        case 1:
            return "yi";
        case 2:
            return "er";
        case 3:
            return "san";
        case 4:
            return "si";
        case 5:
            return "wu";
        case 6:
            return "liu";
        case 7:
            return "qi";
        case 8:
            return "ba";
        case 9:
            return "jiu";
    }
    return "";
}

int main(int argc, const char * argv[])
{
    
    char num[100];
    scanf("%s",num);
    
    char* cur = num;
    int result = 0;
    while(*cur != '\0')
    {
        result += *cur - '0';
        ++cur;
    }
    int hundreds = result/100;
    int tens = result%100/10;
    int ones = result%10;
    if(hundreds == 0 && tens == 0)
    {
        printf("%s",digitToStr(ones));
    }else if(hundreds == 0){
        printf("%s %s",digitToStr(tens), digitToStr(ones));
    }else{
        printf("%s %s %s",digitToStr(hundreds),digitToStr(tens), digitToStr(ones));
    }
}






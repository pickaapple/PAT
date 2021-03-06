//
//  main1011.cpp
//  PAT1
//
//  Created by yhys on 2017/9/7.
//  Copyright © 2017年 ST Studio. All rights reserved.
//
//给定区间[-231, 231]内的3个整数A、B和C，请判断A+B是否大于C。
//
//输入格式：
//
//输入第1行给出正整数T(<=10)，是测试用例的个数。随后给出T组测试用例，每组占一行，顺序给出A、B和C。整数间以空格分隔。
//
//输出格式：
//
//对每组测试用例，在一行中输出“Case #X: true”如果A+B>C，否则输出“Case #X: false”，其中X是测试用例的编号（从1开始）。
//
//输入样例：
//4
//1 2 3
//2 3 4
//2147483647 0 2147483646
//0 -2147483648 -2147483647
//输出样例：
//Case #1: false
//Case #2: true
//Case #3: true
//Case #4: false

#include <stdio.h>

int main(int argc, const char * argv[])
{
    long n;
    scanf("%ld", &n);
    long index,num1,num2,num3;
    for (index = 1 ; index <= n; ++index) {
        scanf("%ld %ld %ld", &num1, &num2, &num3);
        printf("Case #%ld: ",index);
        printf(num1 + num2 > num3 ? "true\n" : "false\n");
    }
    return 0;
}

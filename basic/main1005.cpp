//
//  main1005.cpp
//  PAT1
//
//  Created by yhys on 2017/9/6.
//  Copyright © 2017年 ST Studio. All rights reserved.
//
//1005. 继续(3n+1)猜想 (25)
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
//卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。
//
//当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。
//
//现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。
//
//输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。
//
//输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。
//
//输入样例：
//6
//3 5 6 7 8 11
//输出样例：
//7 6
#include <stdio.h>

inline bool isEven(int n)
{
    return (n & 1) == 0;
}

inline int divideDouble(int n)
{
    return n >> 1;
}

inline int multiplus3puls1(int n)
{
    return (n * 3 + 1) >> 1;
}
//标记 不是关键数字的数字，将其变负
void markUnKeyNumber(int* number, int l, int target)
{
    while(--l >= 0)
    {
        if(number[l] == target)
            number[l] = -number[l];
    }
}
inline void swapDoubleNumber(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void printKeyNumber(int* number, int l)
{
    //冒泡排序
    int indexX,indexY;
    for(indexX = 0 ; indexX < l ; ++indexX)
    {
        for(indexY = l - 1 ; indexY >= indexX + 1 ; --indexY)
        {
            if(number[indexY] > number[indexY - 1])
            {
                swapDoubleNumber(number+indexY,number+indexY - 1);
            }
        }
    }
    //打印排好序的数组
    printf("%d", number[0]);
    for(indexX = 1 ; indexX < l ; ++indexX)
    {
        if(number[indexX] < 0)
            return;
        printf(" %d",number[indexX]);
    }
}

int main(int argc, const char * argv[])
{
    int n,index,numberTemp;
    scanf("%d", &n);
    int number[n];//如果 该数字为关键数字 则置负。因为数字的大小小于100
    for(index = 0 ; index < n ; ++index)
    {
        scanf("%d", number + index);
    }
    
    for(index = 0 ; index < n ; ++index)
    {
        numberTemp = number[index];
        if(numberTemp < 0)//如果 已经确定不是关键数字 则表示其下的 数字已经判断过。
            continue;
        
        while(1 != numberTemp)
        {
            numberTemp = isEven(numberTemp)?divideDouble(numberTemp):multiplus3puls1(numberTemp);
            markUnKeyNumber(number,n,numberTemp);
        }
    }
    //打印关键数字
    printKeyNumber(number, n);
    return 0;
}






//
//  main1003.cpp
//  PAT1
//
//  Created by yhys on 2017/9/6.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

//1003. 我要通过！(20)
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
//“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。
//
//得到“答案正确”的条件是：
//
//1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
//2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
//3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。
//
//现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
//输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，字符串长度不超过100，且不包含空格。
//
//输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。
//
//输入样例：
//8
//PAT
//PAAT
//AAPATAA
//AAPAATAAAA
//xPATx
//PT
//Whatever
//APAAATAA
//输出样例：
//YES
//YES
//YES
//YES
//NO
//NO
//NO
//NO

#include <stdio.h>

enum
{
    BEFORE_P,
    BETWEEN_P_T,
    AFTER_T
};

bool pass(const char* str)
{
    int state = BEFORE_P;
    int numOfA[] = {0, 0, 0};
    
    while('\0' != *str)
    {
        if('P' == *str){
            if(BEFORE_P != state)
                return false;
            
            state = BETWEEN_P_T;
            
        }else if('T' == *str){
            if(BETWEEN_P_T != state)
                return false;
            
            state = AFTER_T;
            
        }else if('A' == *str){
            ++numOfA[state];
            
        }else{
            return false;
        }
        ++str;
    }
    if(0 == numOfA[1]) //中间必须要有A
        return false;
    
    if(0 == numOfA[0] && 0 == numOfA[2])//两边没有A时，都正确
        return true;
    
    if(0 == numOfA[0] || 0 == numOfA[2])//一边有A，一边没有A，错误
        return false;
    
    if(0 != numOfA[2] % numOfA[0])//T后面的A的个数 是 P前面的A的个数 的倍数
        return false;
    
    if(numOfA[1] != numOfA[2] / numOfA[0])//中间A的个数 为 AFTER_T/BEFORE_P
        return false;
    
    return true;
}

int main(int argc, const char * argv[])
{
    int n;
    scanf("%d", &n);
    
    char str[101];
    for( ; n > 0 ; --n)
    {
        scanf("%s",str);
        printf(pass(str)?"YES\n":"NO\n");
    }
}












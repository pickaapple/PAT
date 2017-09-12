//
//  main1001.cpp
//  PAT1
//
//  Created by yhys on 2017/9/9.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include <stdio.h>
#include <string>

int main(int argc, const char* argv[])
{
    int a, b, sum, index;
    scanf("%d %d", &a, &b);
    sum = a + b;
    if(sum < 0)
    {
        printf("-");
        sum = -sum;
    }
    std::string str = std::to_string(sum);
    int before = str.length() % 3;
    for(index = 0 ; index < before ; ++index)
    {
        printf("%c",str[index]);
    }
    if(before > 0 && str.length() > 3)
        printf(",");
    for(index = before ; index < str.length() - 1 ; ++index)
    {
        printf("%c",str[index]);
        if(0 == (index - before + 1) % 3)
            printf(",");
    }
    printf("%c",str[index]);
}

//
//  main1002.cpp
//  PAT1
//
//  Created by yhys on 2017/9/9.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <float.h>

#define MAX 1001
void input(float* An)
{
    int k;
    int exponents;
    float coefficents;
    scanf("%d", &k);
    for( ; k > 0 ; --k)
    {
        scanf("%d",&exponents);
        scanf("%f",&coefficents);
        An[exponents] += coefficents;
    }
}
int main(int argc, const char* argv[])
{
    float An[MAX] = {0};
    
    int index;
    int nonZeroCount = 0;
    
    input(An);
    input(An);
    
    for(index = 0 ; index < MAX ; ++index)
    {
        if(fabsf(An[index]) > FLT_EPSILON)//浮点数比较 注意绝对值
            ++nonZeroCount;
    }
    
    printf("%d", nonZeroCount);
    for(index = MAX - 1 ; index >= 0 ; --index)
    {
        if(fabsf(An[index]) > FLT_EPSILON)
        {
            printf(" %d %0.1f", index, An[index]);
        }
    }
    return 0;
}

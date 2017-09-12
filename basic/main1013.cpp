//
//  main1013.cpp
//  PAT1
//
//  Created by yhys on 2017/9/9.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include <stdio.h>
#include <math.h>
#include <vector>
//--------------------------------------------
//计算质数的时候，只需要从 1 到 质数平方根 之间计算就可以了
//--------------------------------------------
bool isPrime(std::vector<int>& primes, int target)
{
    int sqr = (int)sqrt(target) + 1;
    std::vector<int>::iterator itr = primes.begin();
    for(itr = primes.begin() ; itr != primes.end() ; ++itr)
    {
        if(*itr > sqr)
            break;
        if(target % *itr == 0)
            return false;
    }
    return true;
}

int getNextPosiblePrime(int prime)
{
    if(3 == prime%10)
        return prime + 4;
    return prime + 2;
}
int getNextPrime(std::vector<int>& primes,int prime)
{
    if(2 == prime)
        return 3;
    if(3 == prime)
        return 5;
    do
    {
        prime = getNextPosiblePrime(prime);
    }
    while(!isPrime(primes, prime));
    
    return prime;
}
int main(int argc, const char* argv[])
{
    int currentPrime;
    std::vector<int> primes;
    currentPrime = 2;
    //input
    int m, n, index;
    scanf("%d %d", &m ,&n);
    
    //output
    int outputCount = 1;
    for(index = 1 ; index < n ; ++index)
    {
        if(index >= m){
            printf("%d", currentPrime);
            if(0 == outputCount++ % 10)
                printf("\n");
            else
                printf(" ");
        }
        primes.push_back(currentPrime);
        currentPrime = getNextPrime(primes,currentPrime);
    }
    printf("%d", currentPrime);
}

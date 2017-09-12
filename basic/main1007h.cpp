//
//  main1007v1.cpp
//  PAT1
//
//  Created by yhys on 2017/9/7.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include <stdio.h>
#include <vector>

typedef struct PrimeWithCount
{
    int prime;//质数
    int count;//前面质数之差为2的个数
    void print()
    {
        printf("%d %d\n", prime, count);
    }
} PrimeWithCount;

//num 的个位数必须是 1 3 7 9 其中一个
int getLastPosiblePrime(const int num)
{
    if(3 == num % 10)
        return num + 4;
    return num + 2;
}

bool isPrime(std::vector<PrimeWithCount>& prePrimes,const int target)
{
    std::vector<PrimeWithCount>::iterator itr;
    for(itr = prePrimes.begin() ; itr != prePrimes.end() ; ++itr)
    {
        if(0 == target % itr->prime)
            return false;
    }
    return true;
}
//--------------------------------------------
//
//    commit 4优化的地方。然并卵
//    采用二分法查询 代替 遍历最后一个查询。
//    同时将list改为vector
//
//--------------------------------------------
//--------------------------------------------
//prePrimes中的个数肯定大于0
int findCountFromStore(std::vector<PrimeWithCount>& prePrimes,const int target)
{
    //二分法查询。
    size_t start = 0;
    size_t end = prePrimes.size() - 1;
    size_t mid;
    while(start != end)
    {
        mid = (start + end) / 2;
        bool bigger = target >= prePrimes[mid].prime;
        bool smaller = target <= prePrimes[mid + 1].prime;
        if(bigger && smaller){
            if(target == prePrimes[mid + 1].prime){//如果和大的一样 则去大的，否则一律取小的。
                return prePrimes[mid + 1].count;
            }
            return prePrimes[mid].count;
        }else if(bigger){ //目标都大于中心点 及 中心点加一
            start = mid;
        }else{ //目标都小于中心点 及 中心点加一
            end = mid;
        }
    }
    return prePrimes[0].count;
}

//遍历查询
//int findCountFromStore(std::vector<PrimeWithCount>& prePrimes,const int target)
//{
//    
//    //--------------------------------------------
//    //
//    //    commit 2错误的地方。
//    //    容器的倒叙遍历应该是从rbegin开始直到rend。
//    //    不应该是从end到begin
//    //
//    //--------------------------------------------
//    //--------------------------------------------
//    std::vector<PrimeWithCount>::reverse_iterator ritr;
//    for(ritr = prePrimes.rbegin() ; ritr != prePrimes.rend() ; ++ritr)
//    {
//        if(target >= ritr->prime)
//        {
//            return ritr->count;
//        }
//    }
//    //--------------------------------------------
//    //
//    //    commit 3错误的地方。
//    //    当目标小于所有储存起来的时候，应该返回0
//    //
//    //--------------------------------------------
//    //--------------------------------------------
//    return 0;
//}

int getSpecialPrimeCount(std::vector<PrimeWithCount>& primes,const int num)
{
//--------------------------------------------
//
//    commit 1错误的地方。
//    因为5的时候 为 1，应该将 9改为 7
//    不过可以删去、因为已经在外面添加进去了，会在findCountFromStore中去寻找
//--------------------------------------------
//    //2-9；独立出来是因为5是特殊的
//    if(num < 5)
//        return 0;
//    if(num < 9)
//        return 2;
//--------------------------------------------
    
    if(num <= primes.back().prime) //如果该数字已经计算过，则直接在vector中寻找。
    {
        return findCountFromStore(primes, num);
    }
    
    PrimeWithCount increase = primes.back();//从存储的vector的最后，开始计算。
    while(increase.prime <= num)
    {
        if(isPrime(primes, increase.prime))
        {
            if(2 == increase.prime - primes.back().prime)
                ++increase.count;
            primes.push_back(increase);
        }
        
        increase.prime = getLastPosiblePrime(increase.prime);
    }
    
    return increase.count;
}

int main(int argc, const char * argv[])
{
    std::vector<PrimeWithCount> primes;
    primes.push_back({3, 0});
    primes.push_back({5, 1});
    primes.push_back({7, 2});
    
    int n;
    while(EOF != scanf("%d", &n))
    {
        printf("%d\n",getSpecialPrimeCount(primes, n));
    }
    return 0;
}

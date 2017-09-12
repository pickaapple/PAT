//
//  main1007.cpp
//  PAT1
//
//  Created by yhys on 2017/9/6.
//  Copyright © 2017年 ST Studio. All rights reserved.
//
//1007. 素数对猜想 (20)
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
//让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。
//
//现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。
//
//输入格式：每个测试输入包含1个测试用例，给出正整数N。
//
//输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。
//
//输入样例：
//20
//输出样例：
//4

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

//prePrimes中的个数肯定大于0
int findCountFromStore(std::vector<PrimeWithCount>& prePrimes,const int target)
{
    //二分法查询
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
                prePrimes[mid + 1].print();
                return prePrimes[mid + 1].count;
            }
            prePrimes[mid].print();
            return prePrimes[mid].count;
        }else if(bigger){ //目标都大于中心点 及 中心点加一
            start = mid;
        }else{ //目标都小于中心点 及 中心点加一
            end = mid;
        }
    }
    prePrimes[0].print();
    return prePrimes[0].count;
    
//    遍历查询
//    std::vector<PrimeWithCount>::iterator itr;
//    for(itr = prePrimes.end() ; itr != prePrimes.begin() ; --itr)
//    {
//        if(target >= itr->prime)
//            return itr->count;
//    }
//    return 0;
}

int getSpecialPrimeCount(std::vector<PrimeWithCount>& primes,const int num)
{
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
    //2-9；独立出来是因为5是特殊的
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

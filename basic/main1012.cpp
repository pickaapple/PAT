//
//  main1012.cpp
//  PAT1
//
//  Created by yhys on 2017/9/7.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include <stdio.h>

class A{
public:
    bool empty;
    
    bool isEmpty() {return empty;};
    
    virtual void input(int number)
    {
        empty = false;
    };
    
    virtual void print() = 0;
    
    A():empty(true){};
};

class A1 : public A
{
public:
    int number;
    
    void input(int number) override
    {
        if(number < 5 || 0 != number%2)
            return;
        A::input(number);
        this->number += number;
    };
    
    void print() override
    {
        if(isEmpty())
            printf("N");
        else
            printf("%d", number);
    }
    
    A1():A(),number(0){}
};

class A2 : public A
{
    int number;
    bool plus;
public:
    void input(int number) override
    {
        A::input(number);
        if(plus)
            this->number += number;
        else
            this->number -= number;
        plus = !plus;
    };
    
    void print() override
    {
        if(isEmpty())
            printf("N");
        else
            printf("%d", number);
    }
    
    A2():A(),number(0),plus(true){}
};

class A3 : public A
{
public:
    int number;
    
    void input(int number) override
    {
        A::input(number);
        ++this->number;
    };
    
    void print() override
    {
        if(isEmpty())
            printf("N");
        else
            printf("%d", number);
    }
    
    A3():A(),number(0){}
};

class A4 : public A
{
public:
    int sum;
    int count;
    
    void input(int number) override
    {
        A::input(number);
        sum += number;
        ++count;
    };
    
    void print() override
    {
        if(isEmpty())
            printf("N");
        else
            printf("%0.1f", (float)sum/count);
    }
    
    A4():A(),sum(0),count(0){}
};

class A5 : public A
{
public:
    int number;
    
    void input(int number) override
    {
        A::input(number);
        if(number > this->number)
            this->number = number;
    };
    
    void print() override
    {
        if(isEmpty())
            printf("N");
        else
            printf("%d", number);
    }
    
    A5():A(),number(0){}
};

int main(int argc, const char* argv[])
{
    //init
    int input,index,n;
    scanf("%d", &n);
    A1 a1;
    A2 a2;
    A3 a3;
    A4 a4;
    A5 a5;
    A* as[5] = {&a1, &a2, &a3, &a4, &a5};
    
    //input
    for( index = 0 ; index < n ; ++index)
    {
        scanf("%d", &input);
        as[input%5]->input(input);
    }
    
    //print
    for( index = 0 ; index < 4 ; ++index)
    {
        as[index]->print();
        printf(" ");
    }
    as[index]->print();
}

//
//  main1003.cpp
//  PAT1
//
//  Created by yhys on 2017/9/10.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include <stdio.h>
#include <stack>

class Matrix
{
public:
    void setRoad(int source, int target, int length)
    {
        x[source][target] = length;
    }
    
    bool findFirstAdjVex(int v, int* adjv)
    {
        return getNextAdjVex(v, 0, adjv);
    }
    
    bool getNextAdjVex(int v, int w, int* next)
    {
        int i = w;
        while(i < numOfY)
        {
            if(x[v][i] > 0)
            {
                *next = i;
                return true;
            }
            ++i;
        }
        return false;
    }
    
    int getDegree(int source)
    {
        int index;
        int result = 0;
        for (index = 0 ; index < numOfY ; ++index) {
            result += x[source][index] > 0 ? 1 : 0;
        }
        return result;
    }
    
    void findShortestPaths(int source, int target, int length)
    {
        bool visited[numOfX];
        int index;
        for(index = 0 ; index < numOfX ; ++index)
        {
            visited[index] = false;
        }
        
        std::stack<int> stack;
        int current = source;
        int child;
        int brother;
        do
        {
            visited[current] = true;
            //visit children
            if(findFirstAdjVex(current, &child))
            {
                bool allVisited = false;
                while(visited[child])
                {
                    if(!getNextAdjVex(current, child, &child))
                    {
                        allVisited = true;
                        break;
                    }
                }
                if(!allVisited)
                {
                    stack.push(current);
                    current = child;
                }
                continue;
            }
            bool goto1 = false;
            do
            {   //visit brother
                if(goto1 && getNextAdjVex(stack.top(), current, &brother))
                {
                    bool allVisited = false;
                    while(visited[brother])
                    {
                        if(!getNextAdjVex(stack.top(), current, &brother))
                        {
                            allVisited = true;
                            break;//dont find non-visited brother
                        }
                    }
                    if(!allVisited)
                    {
                        stack.push(current);
                        current = brother;
                        break;//find non-visited brother and visit brother
                    }
                }
                //dont find non-visited brother and pop parent, then try to find parent's brother
                current = stack.top();
                stack.pop();
                if( 0 == stack.size())
                {
                    break;
                }
            }while((goto1 = getNextAdjVex(stack.top(), current, &brother)));
            
        }while(stack.size() > 0);
        
    }
    
    Matrix(int n, int m)
    :numOfX(n)
    ,numOfY(m)
    {
        x = new int*[n];
        for(int index = 0 ; index < n ; ++index)
        {
            x[index] = new int[m];
        }
    }
    
    ~Matrix()
    {
        for(int index = 0 ; index < numOfX ; ++index)
        {
            delete [] x[index];
        }
        delete [] x;
    }
protected:
    // X -> Y
    int** x;
    int numOfX;
    int numOfY;
};

int main(int argc, const char* argv[])
{
    int numberOfCity, numberOfRoad, currentCity, targetCity, index;
    int* citys;
    
    scanf("%d %d %d %d", &numberOfCity, &numberOfRoad, &currentCity, &targetCity);
    
    Matrix arc(numberOfCity, numberOfCity);
    
    citys = new int[numberOfCity];
    for(index = 0 ; index < numberOfCity ; ++index)
    {
        scanf("%d", &citys[index]);
    }
    int city1, city2, length;
    for(index = 0 ; index < numberOfRoad ; ++index)
    {
        scanf("%d %d %d", &city1, &city2, &length);
        arc.setRoad(city1, city2, length);
    }
    
    while(1)
    {
        
        break;
    }
    
    delete [] citys;
    return 0;
}

//
//  main1014.cpp
//  PAT1
//
//  Created by yhys on 2017/9/9.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include <stdio.h>
#include <string.h>

typedef struct myString
{
    char* cz;
    size_t length;
    char& operator [](size_t index) const
    {
        return cz[index];
    }
} myString;

inline bool isDigital(char c)
{
    return c >= '0' && c <= '9';
}

inline bool isUpperCase(char c)
{
    return c >= 'A' && c <= 'Z';
}

inline bool isLetter(char c)
{
    return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

const char* getDayString(int c)
{
    switch (c) {
        default:
        case 0:
            return "MON";
        case 1:
            return "TUE";
        case 2:
            return "WED";
        case 3:
            return "THU";
        case 4:
            return "FRI";
        case 5:
            return "SAT";
        case 6:
            return "SUN";
    }
}
int getHour(char c)
{
    if(isDigital(c))
        return c - '0';
    else
        return c - 'A' + 10;
}

void findDoubleSameLetter(int* first, int* second,const myString& source1,const myString& source2)
{
    bool findFirst = true;
    int index;
    for(index = 0 ; index < source1.length && index < source2.length ; ++index)
    {
        if(source1[index] == source2[index])
        {
            if(findFirst)
            {
                if(!isUpperCase(source1[index]))
                    continue;
                *first = source1[index] - 'A';
                findFirst = false;
            }else{
                if(!isDigital(source1[index]) && !isUpperCase(source1[index]))
                    continue;
                *second = getHour(source1[index]);
                break;
            }
        }
    }
}

void findMinute(int* miun,const myString& source1,const myString& source2)
{
    int index;
    for(index = 0 ; index < source1.length && index < source2.length ; ++index)
    {
        if(source1[index] == source2[index] && isLetter(source1[index]))
        {
            *miun = index;
            break;
        }
    }
}

int main(int argc, const char * argv[])
{
    int index;
    char input[61];
    myString str[4];
    for(index = 0 ; index < 4 ; ++index)
    {
        scanf("%s", input);
        str[index].length = strlen(input);
        str[index].cz = new char[str[index].length + 1];
        memcpy(str[index].cz, input, str[index].length * sizeof(char));
        str[index][str[index].length] = '\0';
    }
    int firstLetter = 0;
    int secondLetter = 0;
    int thirdLetter = 0;
    
    findDoubleSameLetter(&firstLetter,&secondLetter,str[0],str[1]);
    findMinute(&thirdLetter,str[2],str[3]);
    if(60 ==thirdLetter)
    {
        ++secondLetter;
        thirdLetter = 0;
    }
    if(24 == secondLetter)
    {
        ++firstLetter;
        secondLetter = 0;
    }
    printf("%s %02d:%02d", getDayString(firstLetter %= 7), secondLetter, thirdLetter);
    return 0;
}

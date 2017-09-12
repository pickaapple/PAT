//
//  main1003v1.cpp
//  PAT1
//
//  Created by yhys on 2017/9/11.
//  Copyright © 2017年 ST Studio. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <limits.h>

#define INIT_ARRAY_WITH_DATA(pointer,index,length,value) for(index = 0 ; index < length ; ++index ){pointer[index]=value;}

typedef struct Arc
{
    int tailVertex;
    int headVertex;
    int info;
    
    Arc* headLink;
    Arc* tailLink;
} Arc;

typedef struct Vertex
{
    int data;
    Arc* firstIn;
    Arc* firstOut;
    Vertex():firstOut(NULL),firstIn(NULL)
    {}
    
    Vertex(int adata, Arc* afirstIn, Arc* afirstOut)
    :data(adata)
    ,firstIn(afirstIn)
    ,firstOut(afirstOut)
    {}
    
    virtual ~Vertex()
    {
        Arc* deleteArc;
        while(!firstOut)
        {
            deleteArc = firstOut;
            delete deleteArc;
            firstOut = firstOut->tailLink;
        }
    }
    
    void addTailArc(Arc* arc)
    {
        if(!firstOut)
        {
            firstOut = arc;
            return;
        }
        Arc* tailArc = firstOut;
        while(!tailArc->tailLink) tailArc = tailArc->tailLink;
        tailArc->tailLink = arc;
    }
    
    void addHeadArc(Arc* arc)
    {
        if(!firstIn)
        {
            firstIn = arc;
            return;
        }
        Arc* headArc = firstIn;
        while(!headArc->headLink) headArc = headArc->headLink;
        headArc->headLink = arc;
    }
    
    Arc* addTailArc(const Arc& arc)
    {
        Arc* tailArc = firstOut;
        if(tailArc)
            while(!tailArc->tailLink) tailArc = tailArc->tailLink;
        tailArc->tailLink = new Arc();
        *tailArc->tailLink = arc;
        tailArc->tailLink->tailLink = NULL;
        return tailArc;
    }
    
    Arc* addHeadArc(const Arc& arc)
    {
        Arc* headArc = firstIn;
        if(headArc)
            while(!headArc->headLink) headArc = headArc->headLink;
        headArc->headLink = new Arc();
        *headArc->headLink = arc;
        headArc->headLink->headLink = NULL;
        return headArc;
    }
} Vertex;

class Graph
{
public:
    typedef struct InputVertex
    {
        int data;
    }InputVertex;
    
    typedef struct InputVertexR
    {
        int tail;
        int head;
        int info;
    } InputVertexR;
    
    typedef Vertex __Vertex;
    typedef Arc __VertexArc;
    
    void create(const InputVertex* v, int countV,const InputVertexR* vr, int countVR)
    {
        _vertex = new __Vertex[countV];
        int i;
        for(i = 0 ; i< countV ; ++i)
        {
            _vertex[i] = { v[i].data , NULL , NULL };
        }
        
        for(i = 0 ; i < countVR ; ++i)
        {
            __VertexArc* arcAdded = _vertex[vr[i].tail].addTailArc({vr->tail, vr->head, vr->info, NULL, NULL});
            
            _vertex[vr[i].head].addHeadArc(arcAdded);
        }
        
    }
    
    void destroy()
    {
        delete [] _vertex;
    }
    
    bool findAdjVex(const int v, int * next) const
    {
        if(_vertex[v].firstOut)
        {
            *next = _vertex[v].firstOut->headVertex;
            return true;
        }
        return false;
    };
    
    bool nextAdjVex(const int v, const int w, int * next)
    {
        Arc* tailArc = _vertex[v].firstOut;
        if(!tailArc)
            return false;
        while(tailArc->tailLink)
        {
            if(w == tailArc->headVertex)
            {
                *next = tailArc->tailLink->headVertex;
                return true;
            }
            tailArc = tailArc->tailLink;
        }
        return false;
    }
    
    void shortRoad(const int source)
    {
        bool* finished = new bool[_countVertex];
        int index, min;
        INIT_ARRAY_WITH_DATA(finished,index,_countVertex,false);
        
        
        for(index = 0 ; index < _countVertex ; ++index)
        {
            min = INT_MAX;
        }
        
        delete [] finished;
    }
    
    __Vertex* _vertex;
    int _countVertex, _countArc;
};

int main(int argc, const char * argv [])
{
    int numberOfCity, numberOfRoad, currentCity, targetCity, index;
    Graph::InputVertex* citys;
    Graph::InputVertexR* roads;
    scanf("%d %d %d %d", &numberOfCity, &numberOfRoad, &currentCity, &targetCity);
    
    citys = new Graph::InputVertex[numberOfCity];
    roads = new Graph::InputVertexR[numberOfRoad];
    for(index = 0 ; index < numberOfCity ; ++index)
    {
        scanf("%d", &citys[index].data);
    }
    
    for(index = 0 ; index < numberOfRoad ; ++index)
    {
        scanf("%d %d %d", &roads[index].tail, &roads[index].head, &roads[index].info);
    }
    
    Graph graph;
    graph.create(citys, numberOfCity, roads, numberOfRoad);
    
    
    delete [] citys;
    return 0;
}

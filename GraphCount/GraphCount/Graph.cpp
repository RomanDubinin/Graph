#include <iostream>
using namespace std;

struct Graph
{
    long edgeCount = 0;
    long lastVertex = 0;
    long vertexCount;
    long* head;
    long* tails;

    Graph(long vertexCount, long edgeCount)
    {
        Graph::vertexCount = vertexCount;
        head = new long[vertexCount + 2];
        for (long i = 0; i < vertexCount + 2; i++) {
            head[i] = 0;
        }
        tails = new long[edgeCount + 2];
        for (long i = 0; i < edgeCount + 2; i++)
            tails[i] = 0;
    }

    void Add(long v, long u)
    {
        edgeCount++;
        tails[edgeCount] = u;
        for (long i = lastVertex + 1; i <= v; i++)
            head[i] = edgeCount;
        lastVertex = v;
    }

    void EndInitialize()
    {
        edgeCount++;
        for (long i = lastVertex + 1; i < vertexCount + 2; i++)
            head[i] = edgeCount;
    }
};
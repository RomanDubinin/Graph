#include "Algorithm.h"

long mActually(Graph graph) {

    long n = graph.vertexCount, k = 0;

    long mActually = 0;
    long neighbour = 0;
    for (long i = 0; i<n + 1; i++)
    {
        long j = graph.head[i];
        while (j < graph.head[i+1] && j != 0)
        {
            mActually++;
            neighbour = graph.tails[j];
            for (k = graph.head[neighbour]; k < graph.head[neighbour + 1]; k++)
            {
                if (k == i) break;
            }
            j++;
        }
    }
    return mActually;
}

long oneDirectedNum(Graph graph) {

    long n = graph.vertexCount, k = 0;

    long oneDirectedNum = 0;
    long neighbour = 0;
    bool isDoubleDirection;
    for (long i = 0; i< n + 1; i++)
    {
        long j = graph.head[i];
        while (j < graph.head[i+1] && j != 0)
        {
            neighbour = graph.tails[j];
            isDoubleDirection = false;
            for (k = graph.head[neighbour]; k < graph.head[neighbour + 1]; k++)
            {
                if (graph.tails[k] == i)
                {
                    isDoubleDirection = true;
                    break;
                }
            }
            if (!isDoubleDirection)
                oneDirectedNum++;
            j++;

        }
    }
    return oneDirectedNum;

}

long* GetInPowers(Graph graph)
{
    long* outPowers = new long[graph.vertexCount + 1];
    for (int i = 0; i < graph.vertexCount + 1; i++)
    {
        outPowers[i] = 0;
    }

    long outVertex;
    for (int i = 1; i < graph.edgeCount; i++)
    {
        outVertex = graph.tails[i];
        outPowers[outVertex] += 1;
    }

    return outPowers;
}

long* GetOutPowers(Graph graph)
{
    long* inPowers = new long[graph.vertexCount + 1];
    for (int i = 0; i < graph.vertexCount + 1; i++)
    {
        inPowers[i] = 0;
    }

    for (int i = 1; i < graph.vertexCount + 1; i++)
    {
        inPowers[i] = graph.head[i+1] - graph.head[i];
    }

    return inPowers;
}
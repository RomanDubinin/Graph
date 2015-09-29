#include "Algorithm.h"

int mActually(Graph graph) {

    int n = graph.vNumber, k = 0;

    int mActually = 0;
    int neighbour = 0;
    for (int i = 0; i<n + 1; i++)
    {
        int j = graph.head[i];
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

int oneDirectedNum(Graph graph) {

    int n = graph.vNumber, k = 0;

    int oneDirectedNum = 0;
    int neighbour = 0;
    bool isDoubleDirection;
    for (int i = 0; i< n + 1; i++)
    {
        int j = graph.head[i];
        while (j < graph.head[i+1] && j != 0)
        {
            neighbour = graph.tails[j];
            isDoubleDirection = false;
            for (k = graph.head[neighbour]; k < graph.head[neighbour + 1]; k++)
            {
                if (k == i)
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
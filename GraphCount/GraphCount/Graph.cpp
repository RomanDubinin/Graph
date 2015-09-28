#include <iostream>
using namespace std;
struct Graph
{
	int k;
	int lastV;
	int vNumber;
	int* head;
	int* tails;

	Graph(int vNum, int eNum)
	{
		k = 0;
		lastV = 0;
		vNumber = vNum;
		head = new int[vNum+2];
		tails = new int[eNum+2];
		for (int i = 0; i < vNum+2; i++)
			head[i] = 0;
		for (int i = 0; i < eNum+2; i++)
		{
			tails[i] = 0;
		}
			
	}

	void Add(int v, int u)
	{
		k++;
		tails[k] = u;
		for (int i = lastV + 1; i <= v; i++)
			head[i] = k;
		lastV = v;
	}

	void EndInitialize()
	{
		k++;
		for (int i = lastV + 1; i < vNumber + 2; i++)
			head[i] = k;
	}
};
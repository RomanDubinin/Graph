//#include "stdafx.h"
#include "Graph.cpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>

#if defined(_MSC_VER) && _MSC_VER >= 1400 
#pragma warning(push) 
#pragma warning(disable:4996) 
#endif 

using namespace std;

int n, m, i, j, v, u;
char r;

//главная функция
void main(int argc, char * argv[])
{
	setlocale(LC_ALL, "Rus");

	//cout << argv[1];
	ifstream fin(argv[1]);
	string line;
	std::vector<std::string> splitted;

	getline(fin, line);
	boost::split(splitted, line, boost::is_any_of("\t "));
	n = std::stoi(splitted[2]);
	m = std::stoi(splitted[3]);
	Graph graph = Graph(n, m);

	int k = 0;
	while (!fin.eof()) // checks if file is on it's end, this would be false only after failed read
	{
		if (getline(fin, line)) // returns count of bytes was read, returns 0 on when end of file reached
		{
			//.clear();
			boost::split(splitted, line, boost::is_any_of("\t "));
			k++;

			if (splitted[0].compare("a") == 0)
				graph.Add(std::stoi(splitted[2]), std::stoi(splitted[1]));
			else
				continue;
		}
	}
	graph.EndInitialize();
	cout << "added\n";


	int mActually = 0;
	int oneDirectedNum = 0;
	int neighbour = 0;
	bool isDoubleDirection = false;
	for (i = 0; i<n + 1; i++)
	{
		j = graph.head[i];
		if (i) 
			cout << i << "->";
		while (j < graph.head[i+1] && j != 0)
		{
			mActually++;

			if (j == graph.head[i + 1] - 1)
				cout << graph.tails[j];
			else 
				cout << graph.tails[j] << ", ";

			neighbour = graph.tails[j];
			isDoubleDirection = false;
			for (int k = graph.head[neighbour]; k < graph.head[neighbour + 1]; k++)
			{
				if (k == i)
				{
					isDoubleDirection = true;
					break;
				}
			}
			if (!isDoubleDirection)
			{
				oneDirectedNum++;
			}
				

			j++;
			
		}
		cout << endl;
	}
	cout << mActually << endl;
	cout << oneDirectedNum << endl;
	system("pause>>void");
}
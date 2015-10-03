#include "Algorithm.h"
#include <fstream>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <stdlib.h>

#if defined(_MSC_VER) && _MSC_VER >= 1400 
#pragma warning(push) 
#pragma warning(disable:4996) 
#endif 

using namespace std;

const static int WRONG_ARGS = 1;
const static int WRONG_FILE_FORMAT = 2;

int main(int argc, char * argv[])
{
    setlocale(LC_ALL, "Rus");

    if (argc < 2) {
        cerr << "Not enough args" << endl;
        cerr << "  Usage: " << argv[0] << " graph_to_read_from.gr" << endl;
        exit(WRONG_ARGS);
    }

    ifstream fin(argv[1]);
    string line;
    std::vector<std::string> splitted;

    getline(fin, line); // считываем первую строку
    boost::split(splitted, line, boost::is_any_of("\t ")); // TODO better way to parse this(why not regex?)

    if (splitted.size() < 3) {
        cerr << "Wrong file" << endl;
        exit(WRONG_FILE_FORMAT);
    }

    long n = std::stol(splitted[2]);
    long m = std::stol(splitted[3]);
    Graph graph = Graph(n, m);

    long k = 0;
    while (!fin.eof()) // checks if file is on it's end, this would be false only after failed read
    {
        if (getline(fin, line)) // returns count of bytes was read, returns 0 on when end of file reached
        {
            //.clear(); // заполняем его
            boost::split(splitted, line, boost::is_any_of("\t "));
            k++;

            if (splitted[0].compare("a") == 0)
                graph.Add(std::stoi(splitted[2]), std::stoi(splitted[1]));
            else continue;
        }
    }
    graph.EndInitialize();
    cout << "added\n";

    cout << mActually(graph) << endl;
    cout << oneDirectedNum(graph) << endl;
    cin.get();
    return 0;
}
#include <iostream>
#include <vector>
#include <string>

#include "Sample.hpp"

using namespace std;

void Sample::hello()
{
    vector<string> msg{"Hello", "World"};

    for (const string &word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}
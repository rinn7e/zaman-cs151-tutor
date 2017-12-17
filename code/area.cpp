#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <array>
#include <regex>
#include <random>
#include <stdexcept>

using namespace std;

int area(int length, int width) // compute area of rectangle
{
    return length * width;
}

int main()
{
    cout << "Enter two integers:\n";
    int x, y;
    cin >> x >> y;
    
    if (x <= 0 || y <= 0)
        cout << "error\n";
    
    else
        cout << "Area: " << area(x, y) << '\n';
    
    return 0;
}
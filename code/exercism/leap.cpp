#include <iostream>
using namespace std;

bool is_leap_year(int year) {
    return ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
}

int main(){
    bool result = is_leap_year(1900);
    cout << "Result: " << result << endl;
    return 0;
}
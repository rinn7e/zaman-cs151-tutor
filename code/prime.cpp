// print the first n primes, where n is given by the user

// #include "std_lib_facilities.h"
#include <iostream>
using namespace std;

bool is_prime(int n) // determine whether n is prime,
{                    // assume n is positive
    if (n == 1)
        return false;

    for (int d = 2; d < n; ++d)
        if (n % d == 0)
            return false;

    return true;
}

int main()
{
    cout << "Enter a positive integer:\n";
    int n;
    cin >> n;

    cout << "The first " << n << " primes:\n";

    int num = 1;    // we start looking for primes here
    while (n > 0) {
        if (is_prime(num)) { // when we find one, we decrement n
            cout << num << '\n';
            --n;
        }
        ++num;
    }

    return 0;
}
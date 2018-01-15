#include <iostream>

using namespace std;

int fact(int a){
    if (a == 1) {
        return 1;
    } else 
        return a * fact(a-1);
}

void printHello(){
    cout << "Hello World";
    // return 0;
}

int plusNumberAndPrint(int a){
    int result = a + a;
    cout << result << endl;
    return result;
}

int plusNumber(int a){
    return a + a;
}

int main() {
    // int result = fact(4);
    // printHello();
    cout << plusNumberAndPrint(10);
    // cout << plusNumber(10);
    int array[] = {100, 2, 3};
    // cout << array[7] << endl;
}
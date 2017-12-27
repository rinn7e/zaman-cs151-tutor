#include <iostream>
#include <tuple>
using namespace std;

tuple<int, int> findSecondDegree(float a, float b, float c);

typedef int imageIdType;


int main(){
    imageIdType id1 = 1;
    cout << "Hello World" << endl;

    tuple<int, int> result = findSecondDegree (1, 2, 3);
    cout << "First answer is" << get<0>(result) << endl;
    cout << "Second answer is" << get<1>(result) << endl;
    return 0;
}

tuple<int, int> findSecondDegree(float a, float b, float c){
    tuple<int, int> foo = make_tuple(1, 2); 

    return foo;
}
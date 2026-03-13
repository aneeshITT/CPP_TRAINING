#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;


// to checked the atof function how it give output for diff differ input  !!git!
int main() {

    string input;
    cout<<"Enter a number: ";
    cin>>input;

    double value = atof(input.c_str());
    cout<<"The value is: "<<value<<endl;

    return 0;
}
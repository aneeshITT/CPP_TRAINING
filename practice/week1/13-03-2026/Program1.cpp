#include <iostream>
using namespace std;

int main() {
    int x = 2147483647;
    std::cout<<x<<std::endl;
    x = x + 1;
    std::cout<< x << std::endl;

    return 0;
}
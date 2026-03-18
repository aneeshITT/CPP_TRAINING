#include<iostream>
#define Square(x) x*x 
// not safe coz macro just text replacement not even check the type no scope no debugging
int main(){

    int result = Square(2+3);
    std::cout<<"this is the wrong ans: "<<result<<std::endl;
    return 0;
}


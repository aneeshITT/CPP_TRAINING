#include<iostream>

extern "C" int add(int , int );

int main(){

    std::cout<<"this is the addition : "<<add(2,3)<<std::endl;
    return 0;
}
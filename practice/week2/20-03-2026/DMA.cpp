#include<iostream>
// dynamic memory allocation practice !!!!!!!! 

int main(){

    int x =20;

    int *ptr = new int ;
    *ptr = 10;
    

    std::cout<<"heap memory allocation address : "<<ptr<<std::endl;
    std::cout<<"heap memory value: " <<*ptr<<std::endl; 

    std::cout<<"the x's address store in stack is : "<< &x <<std::endl;
    std::cout<<"the x's value that store in stack: "<<x<<std::endl;

    delete ptr;
    ptr = nullptr;

    if(ptr != nullptr){
        std::cout<<"the value of ptr is: "<<*ptr<<std::endl;
    }
    else {
        std::cout<<"the value after deleting ptr is null "<<std::endl;
    }
    return 0;
}
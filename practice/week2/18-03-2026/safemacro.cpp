#include<iostream>
#define PRINT_INF 

int main(){

    #ifdef PRINT_INF  //ifdef preprocessor directive ;;
    std::cout<<" this condition is declared above";
    #endif

    #ifdef PRINT_BOB
    std::cout<<"this condition is not decleared above";
    #endif

    return 0;
}
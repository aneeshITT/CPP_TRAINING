#include<iostream>
#include<climits>

int main(){
    
    static_assert(sizeof(int)>=4, "int must be at least 4 bytes");
    std::cout<<"this program is safe to run on this platform"<<std::endl;

    return 0;
}
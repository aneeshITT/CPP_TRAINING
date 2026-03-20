#include<iostream>
#include<dlfcn.h>

int main(){

    void* handle = dlopen("../dynamic2/libmath.so", RTLD_LAZY);

    if(!handle){
        
        std::cout<<dlerror()<<std::endl;
        return 1;

    }

    int (*add) (int, int );
    add = (int (*)(int , int)) dlsym(handle, "add");

    std::cout<<"the addition is : "<<add(2,3)<<std::endl;
    dlclose(handle);

    return 0;
}
// 1D array allocation in the heap memory------------------>>>>>

#include<iostream>

int main(){

    int n;
    std::cout<<"Enter the number of size"<<std::endl;
    std::cin>>n;

    int *arr = new int[n]; // memory allocate in the heap

        //input yha lia heap main 
    for(int i = 0; i<n; i++){
        std::cout<<"enter the input: "<<std::endl;
        std::cin>>arr[i];
    }

    // heap memory ka output 
    std::cout<<"arrya of output : "<<std::endl;
    for(int i=0; i<n; i++){
        std::cout<< arr[i]<<std::endl;
    }

    
    delete [] arr;

    return 0;
}
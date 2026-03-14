#include<iostream>
#include<string>
#include<cstring>


// How a float value stored in memory !!

void inttobinary(unsigned int data){

    for(int i=31; i>=0; i--){
        std::cout << ((data >> i) & 1);
    }
    std::cout<<"\n" << std::endl;
}



int main(void){

    unsigned int data;

    float fval= 10.75;

    memcpy(&data, &fval, sizeof(float));

    inttobinary(data);

    return 0;
}

#include<iostream>
#include<string>
#include<cstring>


// How a float value stored in memory !!

// void inttobinary(unsigned int data){

//     for(int i=31; i>=0; i--){
//         std::cout << ((data >> i) & 1);
//     }
//     std::cout<<"\n" << std::endl;
// }



// int main(void){

//     unsigned int data;

//     float fval= 10.75;

//     memcpy(&data, &fval, sizeof(float));

//     inttobinary(data);

//     return 0;
// }


// checking double value in binary format in the memory

// void inttobinary(unsigned long long data){


//     for(int i=63; i>=0; i--){
//         std::cout << ((data >> i) & 1);
//     }
//     std::cout<<"\n" << std::endl;
// }



// int main(void){

//     unsigned long long data;

//     double fval= 14.455;

//     memcpy(&data, &fval, sizeof(double));

//     inttobinary(data);

//     return 0;
// }

//////////////////pointer and address in c++

// int main (){

//     int a =20;

//     int *p = &a;

//     std::cout<<"the value of a is : "<< a << std::endl;
//     std::cout<<"the value of p is : "<< *p << std::endl;
//     std::cout<<"the address of a is : "<< p << std::endl;
//     return 0;

// }


///////////////////reference variable in c++ orginal value changes same memory ||  call by value copy created take memory extra 


// void change(int &x){
//     std::cout<<"the value of x is : "<< x << std::endl;
//     std::cout<<"the address of x is : "<< &x << std::endl;
// }
// int main(){

//     int s =10;
//     change(s);

//     std::cout<<"the value of s is : "<< s << std::endl;
//     std::cout<<"the address of s is : "<< &s << std::endl;
//     return 0;



// }


//reference by pointer

void change(int *x ){

    *x =100;
    std::cout<<"the value of x is : "<< *x << std::endl;
    std::cout<<"the address of x is : "<< x << std::endl;
}

int main(){

    int s =10;
    change(&s);

    std::cout<<"the value of s is : "<< s << std::endl;
    std::cout<<"the address of s is : "<< &s << std::endl;

    return 0;

}

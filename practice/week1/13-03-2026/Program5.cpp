#include<iostream>





//if statement example 1
// int main(){

//   int x = 10;

//   if(x<5){
//     std::cout<<"x is less than 5"<<std::endl;
//   }
//   else{
//     std::cout<<"x is greater then 5"<<std::endl;
//   }
//   return 0;


    
// }

//if statement example 2

// int main(){

//     int x=0; // int x{}; uniform intialization set zero to x
//     std::cout<<"enter the value"<<std::endl;
//     std::cin>>x;

//     if(x==0){
//         std::cout<<" x equal to  0"<<std::endl;
//     }
//     if(x!=0){
//         std::cout<<"x value is not equal to 0"<<std::endl;
//     }
//     return 0;
// }

//if else statement example 1

/// @brief to increase the readability of the code we can use if else statement instead of multiple if statements
/// 
// int main(){

//     int x {};
//     std::cout<<"enter the number: "<<std::endl;

//     std::cin>>x;
//     if(x==0){
//        std::cout<<"the number is equal to 0"<<std::endl;
//     }
//     else{
//         std::cout<<"the number is not equal to 0"<<std::endl;
//     }
//     return 0;
// }

// if else chaining example 1

// int main(){
//     int x{};
//     std::cout<<"enter the number: "<<std::endl;
//     std::cin>>x;
//     if(x==0){
//         std::cout<<"the number is equal to 0"<<std::endl;
//     }
//     else if(x<0){
//         std::cout<<"the number is negative"<<std::endl;
//     }
//     else if(x>0){
//         std::cout<<"the number is positive"<<std::endl;
//     }
//     return 0;
// }

//switch statement example 1

// int printsomething(bool x){
//     switch (x)
//     {
//     case 1:
//         std::cout<<"one"<<std::endl;
//         break;
    
//     default:
//         std::cout<<"number is not between 1 and 3"<<std::endl;
//         break;
//     }
//     return 0;

// }


// int main(){
//     bool x = true;
//     std::cout<<"enter the number: "<<std::endl;
//     std::cin>>x;
//     printsomething(x);

//     return 0;
// }


//switch statement example 2

// int main(){

   //int x =0;
//    char x ='a';

//    //int x = 97;

//     switch(x) {

//         case 1 + 2:
//         //std::cout<<"this is 3 "<<std::endl;

//         case 3 +1 :
//        // std::cout<<"this is 4 "<<std::endl;
      
//         case 5:
//        // std::cout<<"this is 5"<<std::endl;

//        case 'a':
//           std::cout<<"this is 97  "<<std::endl;

//         case 'b':
//         std::cout<<"this is b  "<<std::endl;
//         break;

//         default:
//         //std::cout<<"number is not here"<<std::endl;
//         std::cout<<"fall through"<<std::endl;
//         break;


// }

// return 0;
// }


// int main()
// {
// int x  = 3;
// {
//     switch (x)
//     {
//     case 1:
//         std::cout << "One";
//         break;

//     case 2:
//         std::cout << "Two";
//         break;

//     case 3:
//         std::cout << "Three \n"; 
//         return 0;

//     default:
//         std::cout << "Unknown";
//         break;
//     }

//     std::cout << " out of switch!";
// }

// }
////////////////////////////////////////////////////Doubt initialization and assignment 

// int main(){
//     int x =1;

//     switch (1)
//     {

//     case 1:
//         //int a {5};
//        //  a = 5;
//        int a ;
//        a=5;
//         std::cout<<"this is 1 "<<std::endl;
//         break;
//     case 2:

//         a =6;
//         std::cout<<"this is 2 "<<std::endl;
//         break;  


//     default:
//         std::cout<<"number is not here"<<std::endl;
//         break;
//     }

//     return 0 ;
// }


int main(){

int x =5;
std::cout<<x<<std::endl;
std::cout<<" address of x:  "<< &x <<std::endl;



int &ref = x;

std::cout<<"x's reference "<<ref<<std::endl;
ref = 10;

std::cout<<"x after changing reference : value of x: "<<x<<std::endl;


int arr[5] {1,2,3,4,5};

for(const int &x: arr){
    std::cout<<"inside the loop "<<x<<std::endl;


    return 0 ;



}
}
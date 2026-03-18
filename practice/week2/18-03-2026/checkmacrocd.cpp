// #include<iostream>

// #define foo 9

// int main(){

//     #ifdef foo // not this foo becomes 9 because it's a part of separate preprocessor directive
//     std::cout<<"this foo becomes : 9: : "<<foo<<std::endl;
//     #endif
//     return 0;
// }

#include <iostream>

void foo()
{
#define MY_NAME "Aneesh"
}

int main()
{
	std::cout << "My name is: " << MY_NAME << '\n';

	return 0;
}
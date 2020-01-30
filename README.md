# Std-Vector-Functionality_C0x
In this repo you can find some operations with std::vector


Example:

#include "Functionality_C0x.h"
#include <iostream>

template<int N>
struct Factorial
{
	enum { value = N * Factorial<N - 1>::value };
};

template<>
struct Factorial<0>
{
	enum { value = 1 };
};


int main() {

	std::cout << Factorial<5>::value << std::endl; // prints 120

	std::vector<double> vec;
	using T = typename std::decay<decltype(*vec.begin())>::type;
	std::vector<T> vec_1;
	vec_1.push_back(1.3);


	ns_Functionality::il_SetIndexTab(10);
	std::cout << ns_Functionality::il_GetIndexTab();
	
	_STD_VECTOR_DOUBLE prova;
	prova.push_back(10);
	prova.push_back(11);
	double ciao = ns_Functionality::il_GetMean<double>(prova);
	ciao = ns_Functionality::il_GetSum<double>(prova);
	ciao = ns_Functionality::il_GetProduct<double>(prova, prova);
	_STD_VECTOR_DOUBLE pciao;
	pciao = ns_Functionality::il_GetSumByElement<double>(prova, prova);
	pciao = ns_Functionality::il_GetMinusByElement<double>(prova, prova);

	return 0;
}

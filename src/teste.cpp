#include <iostream>
#include <string>
#include "include/list.hpp"
using namespace sc;

int main(void){
	list<std::string> in;
	in.push_front("oi");
	in.push_front("oii");
	in.push_front("israel");
	
	std::cout << in.back() << std::endl;
	std::cout << in.front() << std::endl;
	return 0;
}
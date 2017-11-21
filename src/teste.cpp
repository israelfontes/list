#include <iostream>
#include <string>
#include "../include/list.hpp"
using namespace sc;
using namespace std;
int main(void){
	list<std::string> in;
	in.push_front("one");
	in.push_front("two");
	in.push_front("three");
	auto it = in.begin();
	
	cout << *(--it) << endl;

	in.pop_back();
	in.pop_front();
	std::cout << in.back() << std::endl;
	std::cout << in.front() << std::endl;
	cout << in.size() << endl;
	return 0;
}
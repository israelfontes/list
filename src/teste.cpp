#include <iostream>
#include <string>
#include "../include/list.hpp"
using namespace sc;
using namespace std;
int main(void){
	
	list<std::string> in;
	in.push_back("12");
	in.push_back("123");
	in.insert(in.begin(), "1234");
	for( auto it = in.begin(); it != in.end(); ++it){
		cout << (*it)->data << endl;
	}

	list<string> out;
	
	out = in;
	out.assign("55555");
	//cout << (*out.erase( ++out.cbegin() ))->data << endl;
	for( auto it = out.begin(); it != out.end(); ++it){
		cout << (*it)->data << endl;
	}
	return 0;
}
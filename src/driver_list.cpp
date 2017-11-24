#include <iostream>
#include <string>
#include "list.hpp"

using namespace sc;
using std::cout;
using std::endl;
using std::string;

void print_list(string label, list<int> * list ){
	cout << label << ": {";
	for(auto it(list->begin()); it != --list->end(); ++it) cout << (*it)->data << ", "; /// Operadores --, ++ e != da classe iterator
	cout << (*list->end())->data;
	cout << "}" << endl;
}

int main(){
	
	list<int> list_1; /// Construtor padrão
	list<int> list_2(9); /// Construtor a partir de quantidade de nós
	list<int> list_3(list_2); /// Construtor cópia

	for(int i(0u); i < 9; ++i) list_1.push_back(i); /// Inserindo atrás da lista

	list_3 = list_1; /// Copiando listas
	print_list( "Lista 3", &list_3);
	cout << "Tamanho da lista 3: " << list_3.size() << endl; /// Mostrando tamanho da lista

	if(list_1.empty()) cout << "Lista 1 vazia." << endl; /// Verificando se a lista está vazia

	if( list_3.front() < 7) list_3.pop_front(); /// Deleta ultimo nó
	if( list_3.back() > 7) list_3.pop_back(); /// Deleta primeiro nó

	cout << "Ultimo elemento da lista 3: " << list_3.front() << endl; 
	cout << "Primeiro elemento da lista 3: " << list_3.back() << endl;

	list_3.insert(list_3.begin(), 122); /// Insere elemento após o primeiro nó
	list_1.erase( list_1.begin(), --list_1.end() ); /// Apaga o conjunto de nós do inicio ao fim da lista
	print_list("Lista 1", &list_1);

	cout << "Tamanho da lista 1:" << list_1.size() << endl;

	cout << "Procurar o valor 7 na lista 3: " << (*list_3.find(7))->data << endl;

	list_1 = list_3;
	if(list_1 == list_3) cout << "Lista 1 e Lista 3 são iguais" << endl;

	list_2.assign(99);
	print_list( "Lista 2: ", &list_2);
	if(list_1 != list_2) cout << "Lista 1 e Lista 2 são diferentes" << endl;

	return 0;
}

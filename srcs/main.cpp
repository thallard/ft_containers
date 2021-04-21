#include "List.hpp"
#include <list>
#include <iterator>
int main()
{
	ft::List<int> newList(4, 100);
	std::cout << "Iterator: " << std::endl;
	newList.resize(2);
	std::cout<< "size: " << newList.size() << " -- max_size: " << newList.max_size() << std::endl;
	
std::cout << "\n\n";
	std::cout << "begin: "<< *(--newList.begin()) << std::endl;


	ft::List<int>::iterator it = newList.begin();
	ft::List<int>::iterator itend = newList.end();

	newList.push_front(999);

	newList.push_back(666);

	//newList.reverse();
	
	while (it != itend)
	{
		std::cout << *it << std::endl;
		it++;
	}
	std::cout << "end: " << *newList.end() << std::endl;


	std::cout << "\nReverse_Iterator: " << std::endl;
	ft::List<int>::reverse_iterator roui = newList.rbegin();
	ft::List<int>::reverse_iterator rbase = roui.base();
	std::cout << "roui: " <<  *roui << " rbase: " << *rbase << std::endl;

	std::cout << newList.front() << " " << newList.back() << std::endl;


	std::cout << "Real: " << std::endl;
	std::list<int> realList(4, 100);
	realList.resize(2);

	std::cout<< "size: " << realList.size() << " -- max_size: " << realList.max_size() << std::endl;

	std::cout << *(--realList.begin()) << std::endl;


	std::list<int>::iterator oui = realList.begin();
	std::list<int>::iterator non = realList.end();
	realList.push_front(999);
	realList.push_back(666);
	realList.reverse();



	
	while (oui != non)
	{
		std::cout << *oui << std::endl;
		oui++;
	}
	std::cout << *realList.end() << std::endl;
	// std::list<int>::reverse_iterator rnon = realList.rbegin();
	// std::list<int>::reverse_iterator rnon2 = rnon[2];
	// std::cout << *rnon2 << std::endl;
}
#include "List.hpp"
#include <list>
#include <iterator>
int main()
{
	ft::List<int> newList(4, 100);
	
	ft::Element<int> *node = newList.getNode();

	for (unsigned int i = 0; i < 6; i++)
	{
		std::cout << node->_content << std::endl;
		node = node->_next;
	}
	std::cout << newList.front() << " " << newList.back() << std::endl;
	std::list<int> realList(4, 100);
	std::cout << *(--realList.begin()) << std::endl;
	std::list<int>::iterator oui = realList.begin();
	std::list<int>::iterator non = realList.end();
	while (oui != non)
	{
		std::cout << *oui << std::endl;
		oui++;
	}
	std::cout << *realList.end() << std::endl;
}
#include "List.hpp"
#include <list>
#include <iterator>
int main()
{
	ft::List<int> newList(4, 100);
	std::cout << "Iterator: " << std::endl;

	ft::List<int>::iterator itend = newList.end();

	for (ft::List<int>::iterator it = newList.begin(); it != itend; it++)
		std::cout << *it << std::endl;

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
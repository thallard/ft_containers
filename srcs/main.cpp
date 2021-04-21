#include "List.hpp"
#include <list>
#include <iterator>

bool not_single_digit (const int& value) { return (value>9); }

bool abso_equal(const int &a, const int &b) { return (a == b ? true : a == -b ? true : false); }

int main()
{
	ft::List<int> newList(4, 100);
	std::cout << "Iterator: " << std::endl;
	newList.resize(2);
	std::cout<< "size: " << newList.size() << " -- max_size: " << newList.max_size() << std::endl;
	
std::cout << "\n\n";




	newList.push_front(999);

	newList.push_back(666);
	//newList.pop_back();
	//newList.pop_front();
	std::cout << "\e[35mSize depuis begin de fill: "<< *(--newList.begin()) << std::endl;
	//newList.reverse();
	
	ft::List<int>::iterator it = newList.begin();
	ft::List<int>::iterator itend = newList.end();
	ft::List<int> range(it, itend);
	while (it != itend)
	{
		std::cout << "\e[35mContent : " << *it  << "\e[0m" <<std::endl;
		it++;
	}
		std::cout << "\e[35mEnd de la list fill : " << *newList.end() << "\e[0m\n";


	ft::List<int>::iterator ite = range.begin();
	ft::List<int>::iterator itende = range.end();
	std::cout << "\e[34mSize depuis de la list range : " << *(--range.begin()) << "\e[0m\n";
	while (ite != itende)
	{
		std::cout << "\e[34mContent : " << *ite  << "\e[0m" <<std::endl;
		ite++;
	}
	std::cout << "\e[34mEnd de la list range : " << *range.end() << "\e[0m\n";


	// std::cout << "\nReverse_Iterator: " << std::endl;
	// ft::List<int>::reverse_iterator roui = newList.rbegin();
	// ft::List<int>::reverse_iterator rbase = roui.base();
	// std::cout << "roui: " <<  *roui << " rbase: " << *rbase << std::endl;

	std::cout << newList.front() << " " << newList.back() << std::endl;


	std::cout << "Real: " << std::endl;
	std::list<int> realList(4, 100);
	realList.resize(2);

	std::cout<< "size: " << realList.size() << " -- max_size: " << realList.max_size() << std::endl;

	// std::cout << "le end " << *(++(++(++(realList.end())))) << std::endl;



	realList.push_front(999);
	realList.push_back(666);
	std::list<int>::iterator oui = realList.begin();
	std::list<int>::iterator non = realList.end();
	//realList.reverse();

std::cout <<"begin de la real :" << *(--realList.begin()) << std::endl;

	
	while (oui != non)
	{
		std::cout << *oui << std::endl;
		oui++;
	}
	std::cout <<"bite" << *oui << std::endl;
	std::cout << *realList.end() << std::endl;
	// std::list<int>::reverse_iterator rnon = realList.rbegin();
	// std::list<int>::reverse_iterator rnon2 = rnon[2];
	// std::cout << *rnon2 << std::endl;


	std::cout << "\n\n\e[96mERASE TEST OMG\n\n";


	ft::List<int> list1(5, 10);
	std::list<int> list2(5, 10);



	list1.erase(--(--list1.end()));
	list2.erase(--(--list2.end()));

	ft::List<int>::iterator it10 = list1.begin();
	ft::List<int>::iterator it20 = list1.end();
	//std::cout << *it20 << std::endl;
	while (it10 != it20)
	{
		std::cout << "\e[34mContent : " << *it10  << "\e[0m" <<std::endl;
		it10++;
	}
	
	std::list<int>::iterator it1 = list2.begin();
	std::list<int>::iterator it2 = list2.end();
	while (it1 != it2)
	{
		std::cout << "\e[35mContent : " << *it1  << "\e[0m" <<std::endl;
		it1++;
	}
	ft::List<int>::iterator fake_begin = list1.begin();
	ft::List<int>::iterator fake_end = list1.end();

	list1.erase(++(++list1.begin()), (--list1.end()));

	std::list<int>::iterator real_begin = list2.begin();
	std::list<int>::iterator real_end = list2.end();
	list2.erase(++(++list2.begin()), (--list2.end()));
		
	while (fake_begin != fake_end)
	{
		std::cout << "\e[91mContent: " << *fake_begin << std::endl;
		fake_begin++;
	}
	while (real_begin != real_end)
	{
		std::cout << "\e[92mContent: " << *real_begin << std::endl;
		real_begin++;
	}

	ft::List<int> lst1(3, 10);
	std::list<int> lst2(3, 10);

	ft::List<int>::iterator it4 = lst1.end();
	lst1.insert(lst1.end(), 45);
	ft::List<int>::iterator it3 = lst1.begin();
	while (it3 != it4)
	{
		std::cout << "\e[35mContent : " << *it3  << "\e[0m" <<std::endl;
		it3++;
	}

	std::cout << "Real Clear" << std::endl;
	real_end = lst2.end();

	lst2.clear();

	real_begin = lst2.begin();
	if (real_begin == real_end)
		std::cout << "\e[92mNo content left\e[0m" << std::endl;
	while (real_begin != real_end)
	{
		std::cout << "\e[35mContent : " << *real_begin  << "\e[0m" <<std::endl;
		real_begin++;
	}

	std::cout << "Our Clear" << std::endl;
	fake_end = lst1.end();

	lst1.clear();

	fake_begin = lst1.begin();


	if (fake_begin == fake_end)
		std::cout << "\e[92mNo content left\e[0m" << std::endl;
	while (fake_begin != fake_end)
	{
		std::cout << "\e[35mContent : " << *fake_begin  << "\e[0m" <<std::endl;
		fake_begin++;
	}
	std::cout << "\e[0m";


	std::cout << "Real Remove" << std::endl;
	std::list<int> lst4(5, 10);
	lst4.push_front(-5);
	lst4.push_front(-5);
	lst4.push_front(5);
	lst4.push_front(60);
	lst4.push_back(7);
	lst4.unique();
	lst4.unique(abso_equal);
	lst4.remove(10);
	lst4.remove_if(not_single_digit);
	lst4.push_front(9);
	lst4.sort();
	real_end = lst4.end();
	real_begin = lst4.begin();
	while (real_begin != real_end)
	{
		std::cout << "\e[35mContent : " << *real_begin  << "\e[0m" <<std::endl;
		real_begin++;
	}
	std::cout << "Our Remove" << std::endl;
	ft::List<int> lst3(5, 10);
	lst3.push_front(-5);
	lst3.push_front(-5);
	lst3.push_front(5);
	lst3.push_front(60);
	lst3.push_back(7);
	lst3.unique();
	lst3.unique(abso_equal);
	lst3.remove(10);
	lst3.remove_if(not_single_digit);
	lst3.push_front(9);
	lst3.sort();
	fake_end = lst3.end();
	fake_begin = lst3.begin();
	while (fake_begin != fake_end)
	{
		std::cout << "\e[35mContent : " << *fake_begin  << "\e[0m" <<std::endl;
		fake_begin++;
	}
}
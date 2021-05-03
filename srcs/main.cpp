#include "../includes/List.hpp"
#include "../includes/Stack.hpp"
#include "../includes/Vector.hpp"
#include "../includes/Map.hpp"
#include <list>
#include <stack>
#include <queue>
#include <iterator>
#include <vector>
#include <map>

bool not_single_digit(const int &value) { return (value > 9); }

bool abso_equal(const int &a, const int &b) { return (a == b ? true : a == -b ? true
																			  : false); }

bool mycomparison(double first, double second)
{
	return (int(first) < int(second));
}

int main()
{

/*	ft::List<int> A;
	std::list<int> B;
	ft::List<int> C;
	std::list<int> D;
	std::cout << A.size() << std::endl;
	A.push_front(8);
	B.push_front(8);
	A.push_back(6);
	B.push_back(6);
	A.push_front(27);
	B.push_front(27);

	A.sort();
	B.sort();
	ft::List<int>::iterator C_begin = A.begin();
	ft::List<int>::iterator C_end = A.end();
	std::list<int>::iterator D_begin = B.begin();
	std::list<int>::iterator D_end = B.end();
	while (C_begin != C_end)
	{
		std::cout << "my sort: " << *C_begin << std::endl;
		C_begin++;
	}
	while (D_begin != D_end)
	{
		std::cout << "your sort: " << *D_begin << std::endl;
		D_begin++;
	}
	// size_t size = 5;
	// int val = 100;
	ft::List<int> newList(3, 42);
	std::cout << "Iterator: " << std::endl;
	// ft::List<int> copy(8, 42);
	// ft::List<int>::iterator it2 = newList.begin();
	// ft::List<int>::iterator itend2 = copy.end();
	// it2++;
	// newList.insert(it2, 3, 52);
	ft::List<int> copy(newList);
	ft::List<int>::iterator cpy1 = copy.begin();
	ft::List<int>::iterator cpy2 = copy.end();

	newList.push_back(40);
	while (cpy1 != cpy2)
	{
		std::cout << "\e[91mContent : " << *cpy1 << "\e[0m" << std::endl;
		cpy1++;
	}
	// ft::List<int>::reverse_iterator rcpy1 = copy.rbegin();
	// ft::List<int>::reverse_iterator rcpy2 = copy.rend();
	// while (rcpy1 != rcpy2)
	// {
	// 	std::cout << "\e[95mReverse Content : " << *rcpy1  << "\e[0m" <<std::endl;
	// 	rcpy1++;
	// }
	std::cout << "size: " << newList.size() << " -- max_size: " << newList.max_size() << std::endl;
	// std::cout << "\n\n";

	// if (*it2 == int())
	// 	printf("oui\n");

	// newList.push_front(999);

	// newList.push_back(666);
	//newList.pop_back();
	//newList.pop_front();
	std::cout << "\e[35mSize depuis begin de fill: " << *(newList.end()) << std::endl;
	//newList.reverse();

	ft::List<int>::iterator it = newList.begin();
	ft::List<int>::iterator itend = newList.end();
	// ft::List<int> range(it, itend);
	while (it != itend)
	{
		std::cout << "\e[35mContent : " << *it << "\e[0m" << std::endl;
		it++;
	}
	std::cout << "\e[35mEnd de la list fill : " << *newList.end() << "\e[0m\n";

	// ft::List<int>::iterator ite = range.begin();
	// ft::List<int>::iterator itende = range.end();
	// std::cout << "\e[34mSize depuis de la list range : " << *(--range.begin()) << "\e[0m\n";
	// while (ite != itende)
	// {
	// 	std::cout << "\e[34mContent : " << *ite  << "\e[0m" <<std::endl;
	// 	ite++;
	// }
	// std::cout << "\e[34mEnd de la list range : " << *range.end() << "\e[0m\n";

	// std::cout << "\nReverse_Iterator: " << std::endl;
	// ft::List<int>::reverse_iterator roui = newList.rbegin();
	// ft::List<int>::reverse_iterator rbase = roui.base();
	// std::cout << "roui: " <<  *roui << " rbase: " << *rbase << std::endl;

	std::cout << newList.front() << " " << newList.back() << std::endl;

	std::cout << "Real: " << std::endl;
	std::list<int> realList(5, 100);
	// std::list<int> copy1(8, 42);
	// std::list<int>::iterator it20 = realList.begin();
	// std::list<int>::iterator itend20 = copy1.end();
	// it20++;
	// realList.insert(it20, 3, 52);
	std::cout << "size: " << realList.size() << " -- max_size: " << realList.max_size() << std::endl;

	// std::cout << "le end " << *(++(++(++(realList.end())))) << std::endl;

	// realList.push_front(999);
	// realList.push_back(666);
	std::list<int>::iterator oui = realList.begin();
	std::list<int>::iterator non = realList.end();
	//realList.reverse();

	std::cout << "begin de la real :" << *(--realList.begin()) << std::endl;

	ft::List<int> test(2, 100);
	std::list<int> test2(2, 100);
	ft::List<int> ref(5, 42);
	std::list<int> ref2(5, 42);
	// ft::List<int>::iterator ref1 = ref.begin();
	// ft::List<int>::iterator ref10 = ref.end();
	ft::List<int>::iterator test1 = test.begin();
	ft::List<int>::iterator test10 = test.end();

	// std::list<int>::iterator ref20 = ref2.begin();
	// std::list<int>::iterator ref200 = ref2.end();

	// ref20++;
	// ref20--;
	// test.insert(test.begin(), ref1, ref10);
	// test2.insert(test2.begin(), ref20, ref200);
	std::list<int>::iterator test20 = test2.begin();
	std::list<int>::iterator test200 = test2.end();

	while (test1 != test10)
	{
		std::cout << "\e[91mContent de la notre: " << *test1 << "\e[0m" << std::endl;
		test1++;
	}
	while (test20 != test200)
	{
		std::cout << "\e[34mContent de la real: " << *test20 << "\e[0m" << std::endl;
		test20++;
	}
	while (oui != non)
	{
		std::cout << "\e[92mContent : " << *oui << "\e[0m" << std::endl;
		oui++;
	}
	std::cout << "bite" << *oui << std::endl;
	std::cout << *realList.end() << std::endl;
	// std::list<int>::reverse_iterator rnon = realList.rbegin();
	// std::list<int>::reverse_iterator rnon2 = rnon[2];
	// std::cout << *rnon2 << std::endl;

	// std::cout << "\n\n\e[96mERASE TEST OMG\n\n";

	// ft::List<int> list1(5, 10);
	// std::list<int> list2(5, 10);

	// list1.erase(--(--list1.end()));
	// list2.erase(--(--list2.end()));

	// ft::List<int>::iterator it10 = list1.begin();
	// ft::List<int>::iterator it20 = list1.end();
	// //std::cout << *it20 << std::endl;
	// while (it10 != it20)
	// {
	// 	std::cout << "\e[34mContent : " << *it10  << "\e[0m" <<std::endl;
	// 	it10++;
	// }

	// std::list<int>::iterator it1 = list2.begin();
	// std::list<int>::iterator it2 = list2.end();
	// while (it1 != it2)
	// {
	// 	std::cout << "\e[35mContent : " << *it1  << "\e[0m" <<std::endl;
	// 	it1++;
	// }

	// list1.erase(++(++list1.begin()), (--list1.end()));

	// std::list<int>::iterator real_begin = list2.begin();
	// std::list<int>::iterator real_end = list2.end();
	// list2.erase(++(++list2.begin()), (--list2.end()));

	// while (fake_begin != fake_end)
	// {
	// 	std::cout << "\e[91mContent: " << *fake_begin << std::endl;
	// 	fake_begin++;
	// }
	// while (real_begin != real_end)
	// {
	// 	std::cout << "\e[92mContent: " << *real_begin << std::endl;
	// 	real_begin++;
	// }

	// ft::List<int> lst1(3, 10);
	// std::list<int> lst2(3, 10);

	// ft::List<int>::iterator it4 = lst1.end();
	// lst1.insert(lst1.end(), 45);
	// ft::List<int>::iterator it3 = lst1.begin();
	// while (it3 != it4)
	// {
	// 	std::cout << "\e[35mContent : " << *it3  << "\e[0m" <<std::endl;
	// 	it3++;
	// }

	// std::cout << "Real Clear" << std::endl;
	// real_end = lst2.end();

	// lst2.clear();

	// real_begin = lst2.begin();
	// if (real_begin == real_end)
	// 	std::cout << "\e[92mNo content left\e[0m" << std::endl;
	// while (real_begin != real_end)
	// {
	// 	std::cout << "\e[35mContent : " << *real_begin  << "\e[0m" <<std::endl;
	// 	real_begin++;
	// }

	// std::cout << "Our Clear" << std::endl;
	// fake_end = lst1.end();

	// lst1.clear();

	// fake_begin = lst1.begin();

	// if (fake_begin == fake_end)
	// 	std::cout << "\e[92mNo content left\e[0m" << std::endl;
	// while (fake_begin != fake_end)
	// {
	// 	std::cout << "\e[35mContent : " << *fake_begin  << "\e[0m" <<std::endl;
	// 	fake_begin++;
	// }
	// std::cout << "\e[0m";

	// std::cout << "Real Remove" << std::endl;
	// std::list<int> lst4(5, 10);
	// lst4.push_front(-5);
	// lst4.push_front(-5);
	// lst4.push_front(5);
	// lst4.push_front(60);
	// lst4.push_back(7);
	// lst4.unique();
	// lst4.unique(abso_equal);
	// lst4.remove(10);
	// lst4.remove_if(not_single_digit);
	// lst4.push_front(9);
	// lst4.sort();
	// real_end = lst4.end();
	// real_begin = lst4.begin();
	// while (real_begin != real_end)
	// {
	// 	std::cout << "\e[35mContent : " << *real_begin  << "\e[0m" <<std::endl;
	// 	real_begin++;
	// }
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
	lst3.push_back(2);
	lst3.sort();
	ft::List<int>::iterator fake_end = lst3.end();
	ft::List<int>::iterator fake_begin = lst3.begin();
	while (fake_begin != fake_end)
	{
		std::cout << "\e[35mContent : " << *fake_begin  << "\e[0m" <<std::endl;
		fake_begin++;
	}
	// std::cout << "Merge real" << std::endl;
	// std::list<int> first, second;

	// first.push_back (3);
	// first.push_back (5);
	// first.push_back (1);

	// second.push_back (2);
	// second.push_back (4);
	// second.push_back (6);

	// //first.sort();
	// //second.sort();

	// first.merge(second);

	// //second.push_back (0);

	// //first.merge(second, mycomparison);

	// std::cout << "first contains:";
	// for (std::list<int>::iterator it=first.begin(); it!=first.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << '\n';

	// std::cout << "Splice fake" << std::endl;
	// ft::List<int> first2(1, 3);
	// ft::List<int> second2(1, 6);

	// first2.push_back (5);
	// first2.push_back (1);

	// second2.push_back (2);
	// second2.push_back (4);

	// first2.splice(--(--first2.end()), second2);
	// std::cout << "first contains:";
	// for (ft::List<int>::iterator it=first2.begin(); it!=first2.end(); ++it)
	// 	std::cout << ' ' << *it;
	// std::cout << "\nend: " << *first2.end();
	// std::cout << std::endl;
	std::list<int> lst1(5, 100);
	std::list<int> lst2(6, 42);
	ft::List<int> ls1(5, 100);
	ft::List<int> ls2(6, 42);
	lst1.splice(--(--lst1.end()), lst2, ++lst2.begin(), --lst2.end());
	ls1.splice(--(--ls1.end()), ls2, ++ls2.begin(), --ls2.end());

	ft::List<int>::iterator it1 = ls1.begin();
	ft::List<int>::iterator end1 = ls1.end();

	ft::List<int>::iterator it2 = ls2.begin();
	ft::List<int>::iterator end2 = ls2.end();

	std::list<int>::iterator it10 = lst1.begin();
	std::list<int>::iterator end10 = lst1.end();

	std::list<int>::iterator it20 = lst2.begin();
	std::list<int>::iterator end20 = lst2.end();

	std::cout << "\e[35mTaille de la notre ls1 : " << *--ls1.begin() << "\e[0m" << std::endl;
	while (it1 != end1)
	{
		std::cout << "\e[35mContent de la notre ls1 : " << *it1 << "\e[0m" << std::endl;
		it1++;
	}
	std::cout << "\e[35mTaille de la notre ls2 : " << *--ls2.begin() << "\e[0m" << std::endl;
	while (it2 != end2)
	{
		std::cout << "\e[35mContent de la notre ls2 : " << *it2 << "\e[0m" << std::endl;
		it2++;
	}
	std::cout << "\e[35mTaille de la vraie lst1 : " << *--lst1.begin() << "\e[0m" << std::endl;
	while (it10 != end10)
	{
		std::cout << "\e[91mContent de la vraie lst1 : " << *it10 << "\e[0m" << std::endl;
		it10++;
	}
	std::cout << "\e[35mTaille de la vraie lst2 : " << *--lst2.begin() << "\e[0m" << std::endl;
	while (it20 != end20)
	{
		std::cout << "\e[91mContent de la vraie lst2 : " << *it20 << "\e[0m" << std::endl;
		it20++;
	}

	ft::Stack<int> s1;
	std::stack<int> s2;
	s1.push(20);
	s2.push(20);
	std::cout << s1.top() << " " << s2.top() << std::endl;
	s1.push(30);
	s2.push(30);
	std::cout << s1.top() << " " << s2.top() << std::endl;

	s1.pop();
	s2.pop();
	std::cout << s1.top() << " " << s2.top() << std::endl;
	s1.pop();
	s2.pop();
	// std::cout << s2.top() << " " << s2.top() << std::endl;
	std::vector<int> v1;
	ft::Vector<int> v2;
v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);

	// std::cout << v1.front() << " " << v1.max_size() << " " << v1.max_size() << std::endl;

	ft::Vector<int> test_A;
	test_A.push_back(1);
	test_A.push_back(2);
	test_A.push_back(3);
	test_A.push_back(4);
	test_A.push_back(5);
	test_A.push_back(6);

	ft::Vector<int>::iterator it_ae = test_A.begin();
	std::cout << "Regarde dans le terminal la valeur par rapport au push back au dessus :" 
			<< *it_ae << std::endl;
	// test_A.erase(it_ae);
	v1.insert(++v1.begin(),5, 42);
	it_ae++;
	it_ae++;
	test_A.insert(++test_A.begin(),5, 42);
	std::vector<int>::iterator i1 = v1.begin();
	std::vector<int>::iterator i2 = v1.end();
	while (i1 != i2)
	{
		std::cout << "Content : " << *(i1) << std::endl;
		i1++;
	}
	ft::Vector<int>::iterator it_a = test_A.begin();

	ft::Vector<int>::iterator it_b = test_A.end();
	std::cout << "size: " << test_A.size() << std::endl;
	while (it_a != it_b)
	{
		std::cout << "\e[35mContent : " << *(it_a) << "\e[0m" << std::endl;
		it_a++;
	}*/

	std::map<std::string, int> map1;
	ft::Map<std::string, int> map2;
	map1.insert(map1.begin(), std::pair<std::string, int>("oui", 42));
	ft::Map<std::string, int>::iterator it1 = map2.begin();
	// it1++;
	map2.insert(++it1, ft::pair<std::string, int>("third", 42));
	// std::map<std::string, int>::iterator it2020 = map1.begin();
	// ft::Map<std::string, int>::iterator i11 = map2.begin();
	std::cout << "value de map begin" << map1.begin()->second << std::endl;
	map2["four"];
	ft::Map<std::string, int>::reverse_iterator test = map2.rbegin();
	while (test != map2.rend())
	{
		std::cout << "\e[91mreverse: " << test->first << std::endl;
		test++;
	}
		ft::Map<std::string, int>::iterator test9 = map2.begin();
	while (test9 != map2.end())
	{
		std::cout << "\e[92mnormal: " << test9->first << std::endl;
		test9++;
	}

	std::cout << std::endl << "\e[0mFind four: ";
	ft::Map<std::string, int>::iterator test2 = map2.find("four");
	std::cout << test2->first << std::endl;

	std::cout << "Count: " << map2.count("four") << std::endl;
	std::cout << "upper_bound: " << map2.upper_bound("second")->first << std::endl;
	std::cout << "lower_bound: " << map2.lower_bound("four")->first << std::endl;

	ft::Map<std::string, int> map3;
	map3.insert(map2.begin(), map2.end());
	test9 = map3.begin();
	while (test9 != map3.end())
	{
		std::cout << "\e[92mnormal: " << test9->first << std::endl;
		test9++;
	}

	// std::vector<int> vv1(50, 10);
	// 	std::cout << vv1.capacity() << std::endl;
	// // try
	// {
	// 	std::cout << "test b: " << *it_b << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
}
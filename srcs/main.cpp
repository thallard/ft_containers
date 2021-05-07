#include "../includes/List.hpp"
#include "../includes/Stack.hpp"
#include "../includes/Queue.hpp"
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
class A
{
public:
	int oui;
	A(){};
	~A() {}
};

void list_test()
{
	std::cout << "\e[31m-------------------- LIST ---------------------\e[0m\n"
			  << std::endl;
	ft::List<int> l1(1, 42);
	std::list<int> l2(1, 42);
	std::cout << "\e[34m                                ft | std\e[0m" << std::endl;
	std::cout << "\e[34mTaille des listes depart       : " << l1.size() << " | " << l2.size() << ".\e[0m" << std::endl;
	l1.insert(l1.begin(), 4, 100);
	l2.insert(l2.begin(), 4, 100);
	std::cout << "\e[34mTaille des listes apres insert : " << l1.size() << " | " << l2.size() << ".\e[0m" << std::endl;
	l1.erase(l1.begin(), ++l1.begin());
	l2.erase(l2.begin(), ++l2.begin());
	std::cout << "\e[34mTaille des listes apres erase  : " << l1.size() << " | " << l2.size() << ".\e[0m" << std::endl
			  << std::endl;
	l1.push_front(98);
	l2.push_front(98);
	std::cout << "\e[34mTaille des listes apres push_back : " << l1.size() << " | " << l2.size() << ".\e[0m" << std::endl
			  << std::endl;
	std::cout << "\e[35mPremier element de la vraie : " << l2.front() << " et premier element de la notre : " << l1.front() << ".\e[0m" << std::endl;
	l1.push_back(1);
	l2.push_back(1);
	std::cout << "\e[35mDernier element de la vraie : " << l2.back() << " et dernier element de la notre : " << l1.back() << ".\e[0m" << std::endl;
	std::cout << std::endl;

	ft::List<int>::iterator it1 = l1.begin();
	std::list<int>::iterator it2 = l2.begin();
	while (it1 != l1.end())
		std::cout << "\e[32mContent de la notre : " << *it1++ << "\e[0m" << std::endl;
	std::cout << std::endl;
	while (it2 != l2.end())
		std::cout << "\e[93mContent de la vraie : " << *it2++ << "\e[0m" << std::endl;
	std::cout << std::endl;
	l1.sort();
	l2.sort();
	std::cout << "\e[31mApres le sort :\e[0m" << std::endl;
	it1 = l1.begin();
	it2 = l2.begin();
	while (it1 != l1.end())
		std::cout << "\e[32mContent de la notre : " << *it1++ << "\e[0m" << std::endl;
	std::cout << std::endl;
	while (it2 != l2.end())
		std::cout << "\e[93mContent de la vraie : " << *it2++ << "\e[0m" << std::endl;
	
	l1.clear();
	l2.clear();
	std::cout << "\e[34mTaille des listes apres clear : " << l1.size() << " | " << l2.size() << ".\e[0m" << std::endl;
}

void vector_test()
{
	std::cout << "\n\e[31m-------------------- VECTOR ---------------------\e[0m\n"
			  << std::endl;
	ft::Vector<double> v1(2, 42);
	std::vector<double> v2(2, 42);

	std::cout << "\e[34mTaille des vecteurs au depart : " << v1.size() << " | " << v2.size() << ".\e[0m" << std::endl;
	v1.insert(v1.begin(), 4, 100);
	v2.insert(v2.begin(), 4, 100);
	std::cout << "\e[34mTaille des vecteurs apres insert : " << v1.size() << " | " << v2.size() << ".\e[0m" << std::endl;
	v1.push_back(1);
	v2.push_back(1);
	std::cout << "\e[34mTaille des listes apres push_back : " << v1.size() << " | " << v2.size() << ".\e[0m" << std::endl
			  << std::endl;
	std::cout << "\e[35mPremier element de la vraie : " << v2.front() << " et premier element de la notre : " << v1.front() << ".\e[0m" << std::endl;
	std::cout << "\e[35mDernier element de la vraie : " << v2.back() << " et dernier element de la notre : " << v1.back() << ".\e[0m" << std::endl;
	std::cout << std::endl;

	ft::Vector<double>::iterator it1 = v1.begin();
	std::vector<double>::iterator it2 = v2.begin();
	while (it1 != v1.end())
		std::cout << "\e[95mContent de la notre : " << *it1++ << "\e[0m" << std::endl;
	std::cout << std::endl;
	while (it2 != v2.end())
		std::cout << "\e[94mContent de la vraie : " << *it2++ << "\e[0m" << std::endl;
	std::cout << std::endl;

	v1.clear();
	v2.clear();
	std::cout << "\e[34mTaille des listes apres clear : " << v1.size() << " | " << v2.size() << ".\e[0m" << std::endl;
}

void queue_test()
{
	std::cout << "\n\e[31m-------------------- QUEUE ---------------------\e[0m\n"
			  << std::endl;
	ft::Queue<unsigned long long> q1;
	std::queue<unsigned long long> q2;

	q1.push(42);
	q2.push(42);
	std::cout << "\e[34mTaille des vecteurs apres push : " << q1.size() << " | " << q2.size() << ".\e[0m" << std::endl;
	q1.push(20);
	q2.push(20);
	std::cout << "\e[34mTaille des vecteurs apres push : " << q1.size() << " | " << q2.size() << ".\e[0m" << std::endl;
	std::cout << "\e[35mPremier element de la vraie    : " << q2.front() << " et premier element de la notre : " << q1.front() << ".\e[0m" << std::endl;
	std::cout << "\e[35mDernier element de la vraie    : " << q2.back() << " et dernier element de la notre : " << q1.back() << ".\e[0m" << std::endl;
	q1.pop();
	q2.pop();
	std::cout << "\e[34mTaille des vecteurs apres pop  : " << q1.size() << " | " << q2.size() << ".\e[0m" << std::endl;
	std::cout << "\e[35mPremier element de la vraie    : " << q2.front() << " et premier element de la notre : " << q1.front() << ".\e[0m" << std::endl;
	q1.pop();
	q2.pop();
	std::cout << "\e[34mTaille des vecteurs apres pop  : " << q1.size() << " | " << q2.size() << ".\e[0m" << std::endl;
	std::cout << "\e[34mLes queues sont empty ? Nous   : " << q1.empty() << " | La vraie : " << q2.empty() << ".\e[0m" << std::endl;
}

void stack_test()
{
	std::cout << "\n\e[31m-------------------- STACK ---------------------\e[0m\n"
			  << std::endl;
	ft::Stack<unsigned long long> s1;
	std::stack<unsigned long long> s2;

	s1.push(42);
	s2.push(42);
	std::cout << "\e[34mTaille des vecteurs apres push : " << s1.size() << " | " << s2.size() << ".\e[0m" << std::endl;
	std::cout << "\e[35mDernier element de la vraie    : " << s2.top() << " et dernier element de la notre : " << s1.top() << ".\e[0m" << std::endl;
	s1.push(20);
	s2.push(20);
	std::cout << "\e[34mTaille des vecteurs apres push : " << s1.size() << " | " << s2.size() << ".\e[0m" << std::endl;
	std::cout << "\e[35mDernier element de la vraie    : " << s2.top() << " et dernier element de la notre : " << s1.top() << ".\e[0m" << std::endl;
	s1.pop();
	s2.pop();
	std::cout << "\e[34mTaille des vecteurs apres pop  : " << s1.size() << " | " << s2.size() << ".\e[0m" << std::endl;
	s1.pop();
	s2.pop();
	std::cout << "\e[34mTaille des vecteurs apres pop  : " << s1.size() << " | " << s2.size() << ".\e[0m" << std::endl;
	std::cout << "\e[34mLes queues sont empty ? Nous   : " << s1.empty() << " | La vraie : " << s2.empty() << ".\e[0m" << std::endl;
}

void map_test()
{
	std::cout << "\n\e[31m-------------------- MAP ---------------------\e[0m\n"
			  << std::endl;
	ft::Map<unsigned short int, std::string> m1;
	std::map<unsigned short int, std::string> m2;
	std::cout << "\e[34m                                         ft | std\e[0m" << std::endl;
	std::cout << "\e[34mTaille des maps depart                  : " << m1.size() << " | " << m2.size() << ".\e[0m" << std::endl;
	ft::pair<unsigned short int, std::string> p10(1, "one");
	std::pair<unsigned short int, std::string> p20(1, "one");
	m1.insert(p10);
	m2.insert(p20);
	std::cout << "\e[34mTaille des maps apres insert            : " << m1.size() << " | " << m2.size() << ".\e[0m" << std::endl;
	ft::pair<unsigned short int, std::string> p11(0, "zero");
	std::pair<unsigned short int, std::string> p21(0, "zero");
	m1.insert(m1.begin(), p11);
	m2.insert(m2.begin(), p21);
	std::cout << "\e[34mTaille des maps apres insert            : " << m1.size() << " | " << m2.size() << ".\e[0m" << std::endl;
	ft::Map<unsigned short int, std::string> m15;
	std::map<unsigned short int, std::string> m25;
	m15.insert(m1.begin(), ++(++m1.begin()));
	m25.insert(m2.begin(), ++(++m2.begin()));
	std::cout << "\e[34mNew map insert double iterator          : " << m15.size() << " | " << m25.size() << ".\e[0m" << std::endl << std::endl;

	std::cout << "\e[95mNotre Find(0) : " << m15.find(0)->second << "\e[0m" << std::endl;
	std::cout << "\e[94mLeur  Find(0) : " << m25.find(0)->second << "\e[0m" << std::endl;
	std::cout << "\e[95mNotre Find(1) : " << m1.find(1)->second << "\e[0m" << std::endl;
	std::cout << "\e[94mLeur  Find(1) : " << m2.find(1)->second << "\e[0m" << std::endl << std::endl;;

	std::cout << "\e[95mNotre  Count(1) : " << m2.count(1) << "\e[0m" << std::endl;
	std::cout << "\e[94mLeur  Count(1) : " << m2.count(1) << "\e[0m" << std::endl << std::endl;

	std::cout << "\e[95mNotre lower_bound(0) : " << m15.lower_bound(0)->second << "\e[0m" << std::endl;
	std::cout << "\e[94mLeur  lower_bound(0) : " << m25.lower_bound(0)->second << "\e[0m" << std::endl;
	std::cout << "\e[95mNotre upper_bound(0) : " << m1.upper_bound(0)->second << "\e[0m" << std::endl;
	std::cout << "\e[94mLeur  upper_bound(0) : " << m2.upper_bound(0)->second << "\e[0m" << std::endl<< std::endl;
	
	m15.erase(m15.begin());
	m25.erase(m25.begin());
	std::cout << "\e[34mSize after erase          : " << m15.size() << " | " << m25.size() << ".\e[0m" << std::endl;
	m1.clear();
	m2.clear();
	std::cout << "\e[34mSize after clear          : " << m1.size() << " | " << m2.size() << ".\e[0m" << std::endl << std::endl;

	std::cout << "\e[34mSize before swap          : \e[95m" << m1.size() << " | " << m15.size() << " \e[34m-- \e[94m" << m2.size() << " | " << m25.size() << ".\e[0m" << std::endl;

	m1.swap(m15);
	m2.swap(m25);
	std::cout << "\e[34mSize after swap           : \e[95m" << m1.size() << " | " << m15.size() << " \e[34m-- \e[94m" << m2.size() << " | " << m25.size() << ".\e[0m" << std::endl << std::endl;
}

int main()
{
	list_test();
	vector_test();
	queue_test();
	stack_test();
	map_test();
}
#include <string>
#include <iostream>
#include <stack>
#include "mutantstack.hpp"

int						main(void)
{
	MutantStack<int>	stack;

	stack.push(1);
	stack.push(3);

	std::cout << stack.top() << std::endl;

	stack.pop();

	std::cout << stack.size() << std::endl;

	stack.push(5);
	stack.push(12);
	stack.push(737);
	stack.push(0);

	MutantStack<int>::iterator	it = stack.begin();
	MutantStack<int>::iterator	ite = stack.end();

	++it;
	--it;
	std::cout << "Mutant stack content: " << std::endl; 
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << "Duplicated stack content: " << std::endl; 
	std::stack<int>				s(stack);
	for (int i = 0; i < 5; i++)
	{
		std::cout << s.top() << std::endl;
		s.pop();
	}

	return (0);
}
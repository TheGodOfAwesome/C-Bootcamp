#include "span.hpp"

int main(void) {
	Span sp = Span(10);
	sp.addNumber(-1);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	sp.addNumber(-1);
	sp.addNumber(13);
	sp.addNumber(7);
	sp.addNumber(19);
	sp.addNumber(21);

	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl;
}
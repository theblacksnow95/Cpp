#include "RPN.hpp"

RPN::RPN()
{
}

RPN::RPN(std::string args)
{
	if (args.empty()){
		std::cout << RED << "Error: empty args" << RST << std::endl;
		return ;
	}
	fillStack(args);
}

RPN::RPN(const RPN& other): _stack(other._stack)
{
	std::cout << "RPN Copy constructor called" << std::endl;
}

RPN& RPN::operator=(const RPN& other)
{
	
	if (this != &other)
	{
		_stack = other._stack;
	}
	std::cout << "RPN Copy assignment opreator called" << std::endl;
	return (*this);
}

RPN::~RPN()
{
}

int	pop(std::stack<int>& stack)
{
	if (stack.empty())
		throw RPN::excOperands();
	int	val = stack.top();
	stack.pop();
	return (val);
}


const char* RPN::excOperands::what() const throw()
{
	return ERROPERANDS;
}


bool	validArg(std::string str)
{
	if (str.find_first_not_of("1234567890-+*/ ") != str.npos){
		std::cerr << RED << "Error: invalid args" << RST << std::endl;
		return (false);
	}
	int count = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (isdigit(str[i]))
			count++;
	}
	return (true);
}

void	RPN::fillStack(const std::string& str)
{
	if (!validArg(str))
		return ;
	 for (size_t i = 0; i < str.size(); i++) {
		if (isdigit(str[i])){
			
			_stack.push(str[i] - '0');
		}
		else  if (str[i] != ' ') {
			if (_stack.size() < 2){
				std::cerr << RED << "Error: invalid args" << RST << std::endl;
				return ;
			}
			int right = pop(_stack);
			int left = pop(_stack); 
			
			switch (str[i])
			{
			case '+':
				_stack.push(left + right);
				break;
			case '-':
				_stack.push(left - right);
				break;
			case '*':
				_stack.push(left * right);
				break;
			case '/':
				if (right == 0){
					std::cout << RED << "Error: zero division" << RST << std::endl;
					return ;
				}
				_stack.push(left / right);
				break;
			default:
				break;
			}
		}
	}
	if (_stack.size() != 1 ){
		std::cerr << RED << "Error: Invalid args" << RST << std::endl;
		return ;
	}
	std::cerr << GRN << "Result: " << _stack.top() << RST << std::endl;
}

# include <iostream>
# include <string>

int main(int ac, char **av)
{
	if (ac != 1)
	{
		for (int i = 1; i <= ac - 1; i++)
		{
			std::string s = av[i];
			int	 len = s.length();
			for (int i = 0; i < len; i++)
			{
				if (s[i] < 97 || s[i] > 122)
					continue;
				s[i] = s[i] - 32;
			}
			std::cout << s;
			if (i < ac - 1)
				std::cout << ' ';
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
}

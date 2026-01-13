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
				if (!isalpha(s[i]))
					continue;
				s[i] = toupper(s[i]);
			}
			std::cout << s;
		}
		std::cout << std::endl;
	}
	else
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	}
}

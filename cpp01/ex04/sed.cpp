#include "sed.hpp"

int	sed(std::string& fileName, std::string s1, std::string s2)
{
	std::ifstream	inFile;
	std::string		buff;
	
	inFile.open(fileName.c_str());
	if (inFile.fail())
		return (std::cout << RED << "Error: opening the file." << RST << std::endl, 1);
	std::ofstream	outFile((fileName + ".replace").c_str());
	if (outFile.fail())
		return (std::cout << RED << "Error: creating the file." << RST << std::endl, 1);
	if (s1.empty())
	{
		
		if (s2.empty())
			std::cout << RED << "Error: Strings must not be empty." << RST << std::endl;
		if (s1.empty())
			std::cout << YLL << "No changes applied copy created." << RST << std::endl;
		while (getline(inFile, buff))
			outFile << buff << std::endl;
		return (1);
	}
	int found = 0;
	while (getline(inFile, buff))
	{
		int oldPos = buff.find(s1);
		if (oldPos < 0)
		{
			outFile << buff << std::endl;
			continue;
		}
		while(buff.find(s1, oldPos) != buff.npos)
		{
			std::string firstChunk = buff.substr(0, oldPos);
			std::string secondChunk = buff.substr(oldPos + s1.size(), buff.size());
			firstChunk.append(s2).append(secondChunk);
			oldPos = firstChunk.find(s1, oldPos + s2.size());
			buff = firstChunk;
			found++;
		}
			outFile << buff << std::endl;
	}
	if (found == 0)
		std::cout << YLL << "Word not found." << RST << std::endl;
	else
		std::cout << "String replaced: " << found << " times." << std::endl;
	outFile.close();
	inFile.close();
	return(0);
}

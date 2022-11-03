#include "map_tester.hpp"

template <typename T>
std::string	printPair(const T &iterator, bool nl = true, std::ostream &o = std::cout)
{
	o << "key: " << iterator->first << " | value: " << iterator->second;
	if (nl)
		o << std::endl;
	return ("");
}

template <typename T_MAP>
void	printSize(T_MAP const &mp,std::string filename, bool print_content = 1)
{
	std::ofstream out(filename.c_str());
	out << "size: " << mp.size() << std::endl;
	out << "max_size: " << mp.max_size() << std::endl;
	if (print_content)
	{
		typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
		out << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			out << "- " << printPair(it, false, out) << std::endl;
	}
	out << "###############################################" << std::endl;
}

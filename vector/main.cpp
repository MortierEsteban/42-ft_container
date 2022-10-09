#include <iostream>
#include "vector.hpp"
#include <vector>

int main()
{
{
  		ft::vector<int> myvector;
		ft::vector<int>::iterator  tmp;
  // set some values (from 1 to 10)
//   try
//   {
// 	myvector.reserve(50);
// 	std::cout <<  "capacity = "<<myvector.capacity() << std::endl;
//   }
//   catch(const std::exception& e)
//   {
// 	std::cerr << e.what() << '\n';
//   }
// 	std::cout <<  "capacity = "<<myvector.capacity() << std::endl;

  for (int i=1; i<=10; i++) myvector.push_back(i);

//   // erase the 6th element
 	tmp = myvector.erase (myvector.begin() + 5);
	std::cout << *tmp << std::endl;
  // erase the first 3 elements:
 	tmp = myvector.erase (myvector.begin() +3 ,myvector.end() - 5 );
	std::cout << *tmp << std::endl;

//   std::cout << "myvector contains:";
  for (unsigned i=0; i<myvector.size(); ++i)
    std::cout << ' ' << myvector[i];
  std::cout << '\n';

//   return 0;
}
	return (1);
}
#include "easyfind.hpp"

int main()
{
   std::vector<int>  a;

   for (int i = 0; i < 10; ++i)
   {
      a.push_back(i * 10);
   }

   for (int i = 0; i < 100; ++i)
      easyfind(a, i);

   return 0;
}
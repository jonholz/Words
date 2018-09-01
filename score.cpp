#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
   std::ifstream in("/usr/share/dict/words");
   if (!in.is_open())
   {
      std::cerr << "Could not open input file" << std::endl;
      return -1;
   }
   std::ofstream out("cpp100");
   if (!out.is_open())
   {
      std::cerr << "Could not open output file" << std::endl;
      in.close();
      return -2;
   }
   int t = 0;
   std::string l;
   while(getline(in,l))
   {
      int sum = 0;
      #ifdef DEBUG
      std::cout << l << std::endl;
      #endif
      for (int i = 0; i < l.length(); i++)
      {
         if (isupper(l[i]) || (l[i] == 39))
         {
            sum = 0;
            #ifdef DEBUG
            std::cout << "Found uppercase or \"'\"" << std::endl;
            #endif
            break;
         }
         sum += tolower(l[i]) - 96;
         #ifdef DEBUG
         std::cout << l[i] << " : " << sum << std::endl;
         #endif
      }
      if (sum == 100)
      {
         out << l << std::endl;
         t++;
      }
   }
   std::cout << t << std::endl;
   out.close();
   in.close();
   return 0;
}

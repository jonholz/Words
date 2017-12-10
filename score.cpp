#include <iostream>
#include <fstream>
#include <string>

int main(void)
{
   std::ifstream in("/usr/share/dict/words");
   if (in.is_open())
   {
      std::ofstream out("cpp100");
      if (out.is_open())
      {
         int t = 0;
         std::string l;
         while(getline(in,l))
         {
            int sum = 0;
            //std::cout << l << std::endl;
            for (int i = 0; i < l.length(); i++)
            {
               if (isupper(l[i]) || (l[i] == 39))
               {
                  sum = 0;
                  break;
               }
               sum += tolower(l[i]) - 96;
               //std::cout << l[i] << " : " << sum << std::endl;
            }
            if (sum == 100)
            {
               out << l << std::endl;
               t++;
            }
         }
         std::cout << t << std::endl;
         out.close();
      }
      in.close();
   }
   return 0;
}

#include "HashFunc.h"
#include "HashSet.h"
#include <cmath>

using namespace std;

/**
 * This hash algorithm is based on work by Peter J. Weinberger of AT&T Bell Labs. 
 * The book Compilers (Principles, Techniques and Tools) by Aho, Sethi and Ulman, 
 * recommends the use of hash functions that employ the hashing methodology 
 * found in this particular algorithm.
 * found also at http://www.partow.net/programming/hashfunctions/#APHashFunction 
 */
unsigned int HashA(const std::string& s)
{
   unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
   unsigned int ThreeQuarters     = (unsigned int)((BitsInUnsignedInt  * 3) / 4);
   unsigned int OneEighth         = (unsigned int)(BitsInUnsignedInt / 8);
   unsigned int HighBits          = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
   unsigned int hash              = 0;
   unsigned int test              = 0;

   for(std::size_t i = 0; i < s.length(); i++)
   {
      hash = (hash << OneEighth) + s[i];

      if((test = hash & HighBits)  != 0)
      {
         hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
      }
   }

   return hash;
}

/**
 * JavaHash
 * Given by TAs in Bone lab
 */
unsigned int HashB(const std::string& s)
{
    unsigned int seed = 131;
    unsigned int result = 0;

    for (const char c : s)
    {
        result *= seed;
        result += (unsigned int)c;
    }
    return result;

}

/**
 * A bitwise hash function written by Justin Sobel
 * found at http://www.partow.net/programming/hashfunctions/#APHashFunction 
 */
unsigned int HashC(const std::string& s)
{
   unsigned int hash = 1315423911;

   for(std::size_t i = 0; i < s.length(); i++)
   {
      hash ^= ((hash << 5) + s[i] + (hash >> 2));
   }

   return hash;
}

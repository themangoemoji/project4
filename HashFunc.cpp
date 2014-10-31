#include "HashFunc.h"
#include "HashSet.h"
#include <cmath>

using namespace std;

/**
 * "Data Structures and Algorithms in C++ -- 4th Edition
 *  Hashing with Buckets - pg 579
 */
unsigned int HashA(const std::string& s)
{
    unsigned int poop = 0; unsigned int pack;
    //exclude trailing blanks
    int i = 0, j = 0, slength = 0;
    for (int len = 0; len != s.length(); len++)
    {
        for(pack = 0, j = 0; ; j++, i++)
        {
            pack |= (unsigned long) s[i];
            if (j == 3 || i == slength - 1)
            {
                i++;
                break;
            }
            pack <<= 8;
        }
        poop ^= pack;
    }
    return poop;
}

/**
 * JavaHash
 */
unsigned int HashB(const std::string& s)
{
    unsigned int seed = 31;
    unsigned int result = 0;

    for (const char c : s)
    {
        result *= seed;
        result += (unsigned int)c;
    }
    return result;

}

/**
 * An algorithm produced by Arash Partow. 
 * found at http://www.partow.net/programming/hashfunctions/#APHashFunction 
 */
unsigned int HashC(const std::string& s)
{
   unsigned int hash = 0xAAAAAAAA;

   for(std::size_t i = 0; i < s.length(); i++)
   {
      hash ^= ((i & 1) == 0) ? (  (hash <<  7) ^ s[i] * (hash >> 3)) :
                               (~((hash << 11) + (s[i] ^ (hash >> 5))));
   }

   return hash;
}

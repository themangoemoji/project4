#include "HashFunc.h"
#include "HashSet.h"

using namespace std;

/**
 * Put information about this hash function here
 */
unsigned int HashA(const std::string& s)
{
	// TODO
  int seed = 131;
  unsigned long hash = 0;
  for (int i = 0; i < s.length(); i++)
  {
      hash = (hash * seed) + s[i];
  }
  return (hash % seed);
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
 * Put information about this hash function here
 */
unsigned int HashC(const std::string& s)
{
	// TODO
	return 0;
}

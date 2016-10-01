/* This assignment originated at UC Riverside.*/

#include <string>
#include "hash.h"

using std::string;

/*
////////////////////////////////////////////////////////////////////////////
It involves multiplication i.e hash * seed so it is fast.It provides higher
distribution range of the keys.

Reference : http://www.partow.net/programming/hashfunctions/
Note: Hash function was taken from last time's assignment
///////////////////////////////////////////////////////////////////////////
*/

int
Hash::hf ( string ins ) {

   unsigned int seed = 131; // 31 131 1313 13131 131313 etc..
   unsigned int hash = 0;

   for(std::size_t i = 0; i < ins .length(); i++)
   {
      hash = (hash * seed) + ins [i];
   }

   return hash% HASH_TABLE_SIZE;

}


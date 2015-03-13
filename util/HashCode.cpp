#include "util/HashCode.h"

const int HASH_SEED = 5381;
const int HASH_MULT = 33;
const int HASH_MASK = unsigned(-1)>>1; // all one save for msb

int hashCode(bool key)
{
	return (int)key;
}

int hashCode(char key)
{
	return key;
}

int hashCode(double key)
{
	char* byte = (char*)&key;
	unsigned hash = HASH_SEED;
	for(int i=0;i<(int)sizeof(double);i++)
		hash = HASH_MULT*hash + (int)*byte++;
	return hash & HASH_MASK;
}

int hashCode(float key)
{
	char* byte = (char*)&key;
	unsigned hash = HASH_SEED;
	for(int i=0;i<(int)sizeof(float);i++)
		hash = HASH_MULT*hash + (int)*byte++;
	return hash & HASH_MASK;
}

int hashCode(int key)
{
	return key & HASH_MASK;
}

int hashCode(long key)
{
	return (int)key & HASH_MASK;
}

int hashCode(const char* str) 
{
    unsigned hash = HASH_SEED;
    for (int i = 0; str && str[i] != 0; i++)
	    hash = HASH_MULT*hash + str[i];
    return int(hash & HASH_MASK);
}

int hashCode(const std::string& str) 
{
	unsigned hash = HASH_SEED;
	int n = str.length();
	for (int i = 0; i < n; i++)
	    hash = HASH_MULT*hash + str[i];
    return int(hash & HASH_MASK);
}

int hashCode(void* key) 
{
	return hashCode(reinterpret_cast<long>(key));
}

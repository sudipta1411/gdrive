#include "util/HashMap.h"
#include "util/HashCode.h"

template<typename Key,typename Value>
void HashMap<Key,Value> :: createBuckets(int nBuckets)
{
	this->nBuckets = (nBuckets==0) ? 1 : nBuckets;
	buckets = std::vector<Cell*>();
	buckets.reserve(this->nBuckets);
	this->nEntries = 0;
}

template<typename Key,typename Value>
void HashMap<Key,Value> :: deleteBuckets(std::vector<Cell*>& bucketToDel)
{
	for(int i=0;i<bucketToDel.size();i++)
	{
		Cell* cell = bucketToDel[i];
		while(!cell)
		{
			Cell* nextCell = cell->next;
			delete cell;
			cell = nextCell;
		}
		bucketToDel[i] = NULL;
	}
}

template<typename Key,typename Value>
HashMap<Key,Value> :: HashMap()
{
	createBuckets(INITIAL_BUCKET_COUNT);
}

template<typename Key,typename Value>
HashMap<Key,Value> :: ~HashMap()
{
	deleteBuckets(buckets);
}

template<typename Key,typename Value>
void HashMap<Key,Value> :: put(const Key& key,const Value& value)
{
	(*this)[key] = value;
}

template<typename Key,typename Value>
Value HashMap<Key,Value> :: get(const Key& key) const
{
	Cell* cell = findCell(hashCode(key) % nBuckets,key);
	if(cell == NULL)
		return Value();
	return cell->_value;
}

template<typename Key,typename Value>
void HashMap<Key,Value> :: clear()
{
	deleteBuckets(buckets);
	nEntries = 0;
}

template<typename Key,typename Value>
bool HashMap<Key,Value> :: isEmpty() const
{
	return size() == 0;
}

template<typename Key,typename Value>
int HashMap<Key,Value> :: size() const
{
	return nEntries;
}

template<typename Key,typename Value>
bool HashMap<Key,Value> :: hasKey(const Key& key) const
{
	return findCell(hashCode(key)%nBuckets,key) != NULL;
}

template<typename Key,typename Value>
Value& HashMap<Key,Value> :: operator [](const Key& key)
{
	int bucketHash = hashCode(key) % nBuckets;
	Cell* cell = findCell(bucketHash,key);
	if(cell == NULL)
	{
		cell = new Cell;
		cell->_key = key;
		cell->_value = Value();
		cell->next = buckets[bucketHash];
		buckets[bucketHash] = cell;
		nEntries++;
	}
	return cell->_value;
}

template<typename Key,typename Value>
Value HashMap<Key,Value> :: operator [](const Key& key) const
{
	return get(key);
}


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
void HashMap<Key,Value> :: rehash()
{
	std::vector<Cell*> oldBuckets = buckets;
	createBuckets(oldBuckets.size()*2 + 1);
	for(int i=0;i<oldBuckets.size();i++)
	{
		for(Cell *cell = oldBuckets[i];cell != NULL;cell = cell->next)
			put(cell->_key,cell->_value);
	}
	deleteBuckets(oldBuckets);
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

template<typename Key,typename Value>
bool HashMap<Key,Value> :: remove(const Key& key)
{
	int bucketHash = hashCode(key) % nBuckets;
	Cell *parent = NULL;
	Cell *cell = findCell(bucketHash,key,parent);
	if(cell != NULL)
	{
		if(parent == NULL)
			buckets[bucketHash] = cell->next;
		else
			parent->next = cell->next;
		delete cell;
		nEntries--;
	}
	return true;
}

template<typename Key,typename Value>
std::vector<Key> HashMap<Key,Value> :: keys() const
{
	std::vector<Key> keys;
	for(int i=0;i<buckets.size();i++)
	{
		for(Cell *cell = buckets[i];cell != NULL;cell=cell->next)
			keys.add(cell->_key);
	}
	return keys;
}

template<typename Key,typename Value>
std::vector<Value> HashMap<Key,Value> :: values() const
{
	std::vector<Value> values;
	for(int i=0;i<buckets.size();i++)
	{
		for(Cell *cell = buckets[i];cell != NULL;cell=cell->next)
			values.add(cell->_value);
	}
	return values;
}

template<typename Key,typename Value>
void HashMap<Key,Value> :: putAll(const HashMap& map)
{
	std::vector<Key> keys = map.keys();
	for(int i=0;i<keys.size();i++)
	{
		put(keys[i],map.get(keys[i]));
	}
}


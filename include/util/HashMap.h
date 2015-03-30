#ifndef __HASHMAP_H__
#define __HASHMAP_H__
/*A JAVA like hashmap implementaion*/

#include <vector>
#include <string>
#include "util/HashCode.h"

template<typename Key,typename Value>
class HashMap
{
	private:
		static const int INITIAL_BUCKET_COUNT = 101;
		static const int MAX_LOAD_PERCENTAGE = 70;
		struct Cell
		{
			Key _key;
			Value _value;
			Cell* next;
		};

		std::vector<Cell*> buckets;
		int nBuckets;
		int nEntries;

		void createBuckets(int nBuckets);
		void deleteBuckets(std::vector<Cell*>& bucketToDel);
		void rehash();

		Cell* findCell(int bucketHash,const Key& key) const
		{
			Cell *parent = NULL;
			return findCell(bucketHash,key,parent);
		}

		Cell* findCell(int bucketHash,const Key& key,Cell* parent) const
		{
			parent = NULL;
			Cell* cell = buckets[bucketHash];
			while(cell != NULL && key != cell->_key)
			{
				parent = cell;
				cell = cell->next;
			}
			return cell;
		}

	public:
		HashMap();
		virtual ~HashMap();
		void put(const Key& key,const Value& value);
		Value get(const Key& key) const;
		void clear();
		bool isEmpty() const;
		bool hasKey(const Key& key) const;
		int size() const;
		std::vector<Key> keys() const;
		void putAll(const HashMap& map);
		bool remove(const Key& key);
		//std::string stringify() const;
		std::vector<Value> values() const;
		//bool equals(const HashMap& map) const;

		Value& operator [](const Key& key);
		Value operator [](const Key& key) const;

};

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
	for(unsigned i=0;i<bucketToDel.size();i++)
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
	for(unsigned i=0;i<oldBuckets.size();i++)
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
        if(nEntries > nBuckets * MAX_LOAD_PERCENTAGE / 100.0)
        {
            rehash();
	        bucketHash = hashCode(key) % nBuckets;
        }
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
	for(unsigned i=0;i<buckets.size();i++)
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
	for(unsigned i=0;i<buckets.size();i++)
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
	for(unsigned i=0;i<keys.size();i++)
	{
		put(keys[i],map.get(keys[i]));
	}
}

#endif /*__HASHMAP_H__*/

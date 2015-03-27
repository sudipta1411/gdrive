#ifndef __HASHMAP_H__
#define __HASHMAP_H__
/*A JAVA like hashmap implementaion*/

#include <vector>
#include <string>

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

		Cell* findCell(int bucketHash,const Key& key)
		{
			Cell *parent = NULL;
			return findCell(bucketHash,key,parent);
		}

		Cell* findCell(int bucketHash,const Key& key,Cell* parent)
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
#endif /*__HASHMAP_H__*/

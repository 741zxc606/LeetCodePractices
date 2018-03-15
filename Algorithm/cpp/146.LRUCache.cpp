/*
* 146.LRU Cache
*
* Design and implement a data structure for Least Recently Used(LRU) cache.
* It should support the following operations:get and put.
* get(key) - Get the value (will always be positive) of the key if the key exists in the cache,otherwise return -1.
*
* put(key,value) - Set or insert the value if the key is not already present.When the cache reached its capacity,it should invalidate the
* least recently used item before inserting a new item.
*
* Follow up:
* Could you do both operations in O(1) time complexity?
*
* Example:
*
* LRUCache cache = new LRUCache(2 * capacity * );
*
* cache.put(1,1);
* cache.put(2,2);
* cache.get(1);      //returns 1
* cache.put(3,3);    //evicts key 2
* cache.get(2);      //returns -1 (not found)
* cache.put(4,4);    //evicts key 1
* cache.get(1);      //returns -1 (not found)
* cache.get(3);      //returns 3
* cache.get(4);      //returns 4
*/

#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <map>
#include <list>
#include <unordered_map>
using namespace std;

class Node {
public:
	int key;
	int value;
	Node *next, *prev;
	Node(int k, int v) { key = k; value = v; next = prev = NULL; }
};

//the following double linked list seems a bit commplicated.
class DoubleLinkedList {
private:
	Node *pHead, *pTail;
	int size;

public:
	DoubleLinkedList()
	{
		pHead = pTail = NULL;
		size = 0;
	}

	~DoubleLinkedList()
	{
		while (pHead != NULL)
		{
			Node *p = pHead;
			pHead = pHead->next;
			delete p;
		}
	}

	int Size() const
	{
		return size;
	}

	Node* NewAtBegin(int key, int value)
	{
		Node *n = new Node(key, value);
		return AddAtBegin(n);
	}

	Node* NewAtEnd(int key, int value)
	{
		Node *n = new Node(key, value);
		return AddAtEnd(n);
	}

	Node* AddAtBegin(Node* n)
	{
		size++;

		if (pHead == NULL)
		{
			pHead = pTail = n;
			return n;
		}

		n->next = pHead;
		n->prev = NULL;
		pHead->prev = n;
		pHead = n;
		return n;
	}

	Node* AddAtEnd(Node* n)
	{
		size++;

		if (pHead == NULL)
		{
			pHead = pTail = n;
			return n;
		}

		pTail->next = n;
		n->prev = pTail;
		n->next = NULL;
		pTail = n;
	}

	void Unlink(Node* n)
	{
		Node* before = n->prev;
		Node* after = n->next;

		if (before)
		{
			before->next = after;
		}

		if (after)
		{
			after->prev = before;
		}

		if (pHead == n)
		{
			pHead = pHead->next;
		}
		else if (pTail == n)
		{
			pTail = pTail->prev;
		}

		size--;
	}

	void Delete(Node* n)
	{
		Unlink(n);
		delete(n);
	}

	void TakeToBegin(Node* n)
	{
		Unlink(n);
		AddAtBegin(n);
	}

	Node* GetTailNode()
	{
		return pTail;
	}

	void DeleteLast()
	{
		Delete(pTail);
	}

	void Print()
	{
		Node* p = pHead;
		while (p != NULL)
		{
			cout << "(" << p->key << "," << p->value << ")";
		}
		cout << endl;
	}
};

class LRUCache {
	size_t m_capacity;
	unordered_map<int, list<pair<int, int>>::iterator>m_map;//m_map_iter->first:key,m_map_iter->second:list iterator;
	list<pair<int, int>>m_list;//m_list_iter->first:key,m_list_iter->second:value;

private:
	//cacheList - store the data
	DoubleLinkedList cacheList;
	//cacheMap - index the data for searching
	map<int, Node*>cacheMap;
	//the max capacity of cache
	int capacity;

public:
	LRUCache(int capacity) : capa_(capacity) {
	}

	void print()
	{
		cacheList.Print();
	}

	int get(int key) {
		if (map_.find(key) != map_.end()) {
			// It key exists, update it.
			const auto value = map_[key]->second;
			update(key, value);
			return value;
		}
		else {
			return -1;
		}
	}

	void put(int key, int value) {
		// If cache is full while inserting, remove the last one.
		if (map_.find(key) == map_.end() && list_.size() == capa_) {
			auto del = list_.back(); list_.pop_back();
			map_.erase(del.first);
		}
		update(key, value);
	}

private:
	list<pair<int, int>> list_; // key, value
	unordered_map<int, list<pair<int, int>>::iterator> map_; // key, list iterator
	int capa_;

	// Update (key, iterator of (key, value)) pair
	void update(int key, int value) {
		auto it = map_.find(key);
		if (it != map_.end()) {
			list_.erase(it->second);
		}
		list_.emplace_front(key, value);
		map_[key] = list_.begin();
	}
};

int main(int argc, char** argv)
{
	srand(time(0));

	int capacity = 5;
	int test_loop_times = 10;
	if (argc > 1)
	{
		capacity = atoi(argv[1]);
	}
	if (argc > 2)
	{
		test_loop_times = atoi(argv[1]);
	}

	LRUCache cache(capacity);

	int v;
	for (int i = 0; i < test_loop_times; i++)
	{
		v = i;
		cout << "put" << v << ":";
		cache.put(v, v);
		cache.print();

		v = rand() % capacity;
		cout << "get" << v << ":" << cache.get(v);
		cache.print();

		cout << endl;
	}
	return 0;
}

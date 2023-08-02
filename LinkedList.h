#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include "Node.h"
#include <string>

class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void Insert(int key, const std::string& value);
	void Append(int key, const std::string& value);
	
	Node* RemoveHead();
	Node* RemoveTail();
	Node* RemoveNode(int key);

	Node* GetHead() const;
	Node* GetTail() const;
	Node* GetNode(int key) const;

	int Count() const;
	bool IsEmpty() const;
	void Clear();

	std::string ToString() const;

private:
	int m_Count;

	Node* m_Head;
	Node* m_Tail;
};

#endif //  __LINKED_LIST_H__
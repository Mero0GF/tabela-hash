#ifndef __NODE_H__
#define __NODE_H__

#include <string>

class Node
{
public:
	Node(int key, const std::string& value, Node* next = nullptr);
	~Node();

	int GetKey() const;

	std::string GetValue() const;
	void SetValue(const std::string& value);

	Node* GetNext() const;
	void SetNext(Node* next);

private:
	int m_Key;
	std::string m_Value;

	Node* m_Next;
};

#endif // __NODE_H__
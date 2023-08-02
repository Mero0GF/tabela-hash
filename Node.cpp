#include "Node.h"

Node::Node(int key, const std::string& value, Node* next)
	: m_Key(key)
	, m_Value(value)
	, m_Next(next)
{
}

Node::~Node()
{
	m_Next = nullptr;
}

int Node::GetKey() const
{
	return m_Key;
}

std::string Node::GetValue() const
{
	return m_Value;
}

void Node::SetValue(const std::string& value)
{
	m_Value = value;
}

Node* Node::GetNext() const
{
	return m_Next;
}

void Node::SetNext(Node* next)
{
	m_Next = next;
}
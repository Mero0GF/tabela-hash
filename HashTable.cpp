#include "HashTable.h"
#include <sstream>
#include <iostream>

HashTable::HashTable()
	: HashTable(DEFAULT_SIZE)
{
}

HashTable::HashTable(int size)
	: m_Size(size)
{
	m_Table = new LinkedList[m_Size];
}

HashTable::~HashTable()
{
	delete[] m_Table;
	m_Table = nullptr;
}

std::string HashTable::Search(int key) const
{
	int hashKey = HashFunction(key);

	const Node* node = m_Table[hashKey].GetNode(key);
	if (node)
		return node->GetValue();

	return "";
}

HashTable::InsertResult HashTable::Insert(int key, const std::string& value)
{
	int hashKey = HashFunction(key);
	InsertResult result = m_Table[hashKey].IsEmpty() ? InsertResult::WithoutCollision : InsertResult::WithCollision;

	Node* node = m_Table[hashKey].GetNode(key);
	if (node)
	{
		node->SetValue(value);
		result = InsertResult::Updated;
	}
	else
	{
		m_Table[hashKey].Append(key, value);
	}

	return result;
}

bool HashTable::Remove(int key)
{
	int hashKey = HashFunction(key);

	Node* node = m_Table[hashKey].RemoveNode(key);
	if (node)
	{
		delete node;
		node = nullptr;

		return true;
	}

	return false;
}

bool HashTable::IsEmpty() const
{
	bool isEmpty = true;

	for (int i = 0; i < m_Size; ++i)
	{
		isEmpty &= m_Table[i].IsEmpty();
	}

	return isEmpty;
}

std::string HashTable::ToString() const
{
	std::ostringstream oss;

	for (int i = 0; i < m_Size; ++i)
		oss << "[" << i << "] " << m_Table[i].ToString() << '\n';

	return oss.str();
}

int HashTable::GetDigits(int key) const{
  std::string value,aux;
  char s[3];
  aux = std::to_string(key);
  s[0] = aux[0];
  s[1] = aux[2];
  s[2] = aux[4];
  int new_key = std::atoi(s);
  return new_key;
}

int HashTable::QuadraticMethod(int key) const{
  std::string aux;
  char s[4];
  key = key*key;
  aux = std::to_string(key);
  s[0] = aux[1];
  s[1] = aux[2];
  s[2] = aux[3];
  s[3] = aux[4];
  int new_key = std::atoi(s);
  return new_key;
}

int HashTable::DivisionMethod(int key) const{
  int new_key = key % 11;
  return new_key;
}

int HashTable::HashFunction(int key) const
{
  int new_key = GetDigits(key);
  std::cout << "\nExtracted key from GetDigits() function(1°,3° and 5° digit):" << new_key << "\n";
  new_key = QuadraticMethod(new_key);
  std::cout << "\nExtracted key from QuadraticMethod() function:" << new_key << "\n";
  new_key = DivisionMethod(new_key);
  std::cout << "\nExtracted key from DivisionMethod() function:" << new_key << "\n";
	return new_key;
}
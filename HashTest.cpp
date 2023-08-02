//#define CHECK_FOR_MEMORY_LEAKS

// Caue Souza - 42144914
// Thiago Leandro Liporace - 42128481
// Lucas Goulart de Farias Meres - 42127459

#ifdef CHECK_FOR_MEMORY_LEAKS
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#endif // #ifdef CHECK_FOR_MEMORY_LEAKS
#include <string>
#include <iostream>
#include "HashTable.h"

void PrintIsEmpty(const HashTable* hashTable)
{
	std::cout << "Hash table is" << (hashTable->IsEmpty() ? " " : " not ") << "empty.\n";
}

void PrintSearch(const HashTable* hashTable, int key)
{
	std::cout << "Search value for key " << key << ": ";

	std::string value = hashTable->Search(key);
	std::cout << (value == "" ? "<Search returned empty value>" : value) << '\n';
}

void PrintInsert(HashTable* hashTable, int key, const std::string& value)
{
	std::cout << "Insert(" << key << ", " << value << "): ";

	HashTable::InsertResult result = hashTable->Insert(key, value);
	if (result == HashTable::InsertResult::WithCollision)
		std::cout << "with collision!\n";
	else if (result == HashTable::InsertResult::WithoutCollision)
		std::cout << "no collision.\n";
	else if (result == HashTable::InsertResult::Updated)
		std::cout << "value updated.\n";
}

void PrintRemove(HashTable* hashTable, int key)
{
	std::cout << "Remove(" << key << "): ";

	bool result = hashTable->Remove(key);
	std::cout << (result ? "removed!" : "key not found.") << '\n';
}


int main()
{
#ifdef CHECK_FOR_MEMORY_LEAKS
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif // #ifdef CHECK_FOR_MEMORY_LEAKS

	std::cout << "*** HASH TABLE (SEPARATE CHAINING) ***\n";

	HashTable hashTable(11);
	PrintIsEmpty(&hashTable);

	// PrintInsert(&hashTable, 50078, "BANCO DE DADOS");
	// PrintInsert(&hashTable, 50327, "ESTRUTURA DE DADOS I");
	// PrintInsert(&hashTable, 50720, "MODELAGEM MATEMATICA I");
	// PrintInsert(&hashTable, 50782, "ORGANIZACAO DE COMPUTADORES");
	// PrintInsert(&hashTable, 50898, "PROJETO E ANALISE DE ALGORITMOS I");

	// PrintInsert(&hashTable, 50013, "ALGORITMOS NUMERICOS");
	// PrintInsert(&hashTable, 50329, "ESTRUTURA DE DADOS II");
	PrintInsert(&hashTable, 50721, "MODELAGEM MATEMATICA II");
	PrintInsert(&hashTable, 50897, "PROJETO DE SOFTWARE");
	// PrintInsert(&hashTable, 50899, "PROJETO E ANALISE DE ALGORITMOS II");
	PrintInsert(&hashTable, 51032, "SISTEMAS OPERACIONAIS");
  std::cout << "\n\n\n";

	int key = 51032;
	// PrintSearch(&hashTable, key);
	// PrintRemove(&hashTable, key);
	// PrintSearch(&hashTable, key);
	// PrintInsert(&hashTable, key, "ESTRUTURA DE DADOS II");
	// PrintInsert(&hashTable, key, "Estrutura de Dados II");
  

	std::cout << hashTable.ToString();
}

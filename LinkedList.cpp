//https://stackoverflow.com/questions/14544539/linked-lists-in-c
//Domingos Soares do Carmo Neto - 32032889
//C�ssio Luis Junqueira Mellem Filho - 32089694
#include "LinkedList.h"
#include <iostream>

LinkedList* Create()
{
	LinkedList* newList = new LinkedList
	{
		0, nullptr, nullptr
	};
	return newList;
}

void Destroy(LinkedList* list)
{
	Clear(list);
	delete list;
}

void InsertCome�o(LinkedList* list, int elem)
{
	Node* node = new Node;
	node->data = elem;
	node->next = list->come�o;
	if (IsEmpty(list))
	{
		list->fim = node;
	}
	list->come�o = node;
	list->count++;

}


void InsertFim(LinkedList* list, int elem)
{
	Node* node = new Node;
	node->data = elem;
	node->next = nullptr;
	if (IsEmpty(list))
	{
		list->come�o = node;
		list->fim = node;
	}
	else
	{
		list->fim->next = node;
		list->fim = node;
	}
	list->count++;

}

Node* RemoveCome�o(LinkedList* list)
{
	Node* toRemove = list->come�o;
	if (list->come�o == list->fim)
	{
		list->come�o = nullptr;
		list->fim = nullptr;
	}
	else
	{
		list->come�o = list->come�o->next;
	}
	list->count--;
	return toRemove;
}

Node* RemoveFim(LinkedList* list)
{
	if (list->come�o == list->fim)
	{
		return RemoveCome�o(list);
	}
	Node* toRemove = list->come�o;
	Node* previous = nullptr;
	while (toRemove != list->fim)
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}
	previous->next = nullptr;
	list->fim = previous;
	list->count--;
	return toRemove;
}

Node* RemoveNode(LinkedList* list, int elem)
{
	Node* toRemove = list->come�o;
	Node* previous = nullptr;
	while (toRemove != nullptr && toRemove->data != elem)
	{
		previous = toRemove;
		toRemove = toRemove->next;
	}
	if (toRemove == nullptr)
		return nullptr;
	else if (toRemove == list->come�o)
		return RemoveCome�o(list);
	else if (toRemove == list->fim)
		return RemoveFim(list);
	else
	{
		previous->next = toRemove->next;
		list->count--;
		toRemove->next = nullptr;
		return toRemove;
	}
}

Node* GetCome�o(LinkedList* list)
{
	return list->come�o;
}

Node* GetFim(LinkedList* list)
{
	return list->fim;
}

Node* GetNode(const LinkedList* list, int elem)
{
	Node* node = list->come�o;
	while (node != nullptr)
	{
		if (node->data == elem)
		{
			return node;
		}
		node = node->next;
	}
	return nullptr;
}

int Count(LinkedList* list)
{
	return list->count;
}

bool IsEmpty(const LinkedList* list)
{
	return (list->come�o == nullptr) && (list->fim == nullptr);
}

bool Clear(LinkedList* list)
{
	while (!IsEmpty(list))
	{
		RemoveFim(list);
	}
	return IsEmpty(list);
}

void DestroyNode(Node* node)
{
	delete node;
}
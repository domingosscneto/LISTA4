//https://stackoverflow.com/questions/14544539/linked-lists-in-c
//Domingos Soares do Carmo Neto - 32032889
//Cássio Luis Junqueira Mellem Filho - 32089694
#ifndef __LinkedList__
#define __LinkedList__

struct Node
{
    int data;
    Node* next;
};

struct LinkedList
{
    int count;
    Node* começo;
    Node* fim;
};

LinkedList* Create();

void Destroy(LinkedList* list);

void InsertComeço(LinkedList* list, int elem);

void InsertFim(LinkedList* list, int elem);

Node* RemoveComeço(LinkedList* list);

Node* RemoveFim(LinkedList* list);

Node* RemoveNode(LinkedList* list, int elem);

Node* GetComeço(LinkedList* list);

Node* GetFim(LinkedList* list);

Node* GetNode(const LinkedList* list, int elem);

int Count(LinkedList* list);

bool IsEmpty(const LinkedList* list);

bool Clear(LinkedList* list);

void DestroyNode(Node* node);

#endif // !__LinkedList__

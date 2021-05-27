//https://stackoverflow.com/questions/14544539/linked-lists-in-c
//Domingos Soares do Carmo Neto - 32032889
//Cássio Luis Junqueira Mellem Filho - 32089694
// main.cpp
#include <iostream>
#include <clocale>
#include "LinkedList.h"
using namespace std;
void Print(const LinkedList* list)
{
    struct Node* ptr;
    ptr = list->começo;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
void PrintListInfo(const LinkedList* list)
{
    if (IsEmpty(list))
    {
        cout << "\n" << "Lista vazia!\n";
    }
    else
    {
        cout << "Lista: ";
        Print(list);
    }
}
int main()
{
    setlocale(LC_ALL, "pt_BR");
    cout << " Lista Ligada/Encadeada (Linked List) \n";
    LinkedList* list = Create();
    PrintListInfo(list);
    InsertComeço(list, 1);
    InsertComeço(list, 2);
    InsertComeço(list, 3);
    InsertFim(list, 4);
    InsertFim(list, 5);
    InsertFim(list, 6);
    PrintListInfo(list);
    Clear(list);
    PrintListInfo(list);
    InsertComeço(list, 77);
    InsertFim(list, 88);
    InsertComeço(list, 99);
    InsertFim(list, 3);
    InsertComeço(list, 2);
    InsertFim(list, 1);
    InsertComeço(list, 0);
    PrintListInfo(list);
    Node* temp = RemoveNode(list, 3);
    cout << "\n" << "Nó removido: " << temp->data << '\n';
    DestroyNode(temp);
    PrintListInfo(list);
    temp = RemoveComeço(list);
    cout << "\n" << "Nó removido: " << temp->data << '\n';
    DestroyNode(temp);
    PrintListInfo(list);
    temp = RemoveFim(list);
    cout << "\n" << "Nó removido: " << temp->data << '\n';
    DestroyNode(temp);
    PrintListInfo(list);
    Destroy(list);
    cout << "\n" << "Fim.\n";
}
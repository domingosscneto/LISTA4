//https://stackoverflow.com/questions/14544539/linked-lists-in-c
//Domingos Soares do Carmo Neto - 32032889
//C�ssio Luis Junqueira Mellem Filho - 32089694
// main.cpp
#include <iostream>
#include <clocale>
#include "LinkedList.h"
using namespace std;
void Print(const LinkedList* list)
{
    struct Node* ptr;
    ptr = list->come�o;
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
    InsertCome�o(list, 1);
    InsertCome�o(list, 2);
    InsertCome�o(list, 3);
    InsertFim(list, 4);
    InsertFim(list, 5);
    InsertFim(list, 6);
    PrintListInfo(list);
    Clear(list);
    PrintListInfo(list);
    InsertCome�o(list, 77);
    InsertFim(list, 88);
    InsertCome�o(list, 99);
    InsertFim(list, 3);
    InsertCome�o(list, 2);
    InsertFim(list, 1);
    InsertCome�o(list, 0);
    PrintListInfo(list);
    Node* temp = RemoveNode(list, 3);
    cout << "\n" << "N� removido: " << temp->data << '\n';
    DestroyNode(temp);
    PrintListInfo(list);
    temp = RemoveCome�o(list);
    cout << "\n" << "N� removido: " << temp->data << '\n';
    DestroyNode(temp);
    PrintListInfo(list);
    temp = RemoveFim(list);
    cout << "\n" << "N� removido: " << temp->data << '\n';
    DestroyNode(temp);
    PrintListInfo(list);
    Destroy(list);
    cout << "\n" << "Fim.\n";
}
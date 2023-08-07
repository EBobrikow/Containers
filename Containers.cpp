// Containers.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>

#include "CustomVector.h"
#include "CustomVector.cpp"

#include "CustomList.h"
#include "CustomList.cpp"

#include "CustomDeque.h"
#include "CustomDeque.cpp"

#include "CustomMap.h"
#include "CustomMap.cpp"

#include "CustomStack.h"
#include "CustomStack.cpp"

using namespace std;

int main()
{
    cout << "Stack ===============================" << endl;
    CustomStack<int> cStack = CustomStack<int>();

    cStack.Push(10);
    cStack.Push(56);
    cStack.Push(895);
    cStack.Push(1062);

    int size = cStack.Num();
    for (int i = 0; i < size; i++)
    {
        cout << cStack.Top() << endl;
        cStack.Pop();
    }
    cStack.Clear();
    
    cout << "Map ===============================" << endl;
    CustomMap<int, string> cMap = CustomMap<int, string>();

    cMap.Add(1,"Apple");
    cMap.Add(4, "Pear");
    cMap.Add(10, "Banana");
    cMap.Add(2, "Melon");
    cMap.Add(1, "Pineapple");

    for (auto val : cMap)
    {
        cout << val.key << " " << val.value << endl;
    }

    for (CustomMap<int, string>::iterator it = cMap.begin(); it != cMap.end(); ++it)
    {
        CustomMap<int, string>::TPair tmp = *it;
        cout << tmp.key << " " << tmp.value << endl;
    }
    cMap.Clear();

    cout << "Deque ===============================" << endl;
    CustomDeque<int> cDeq = CustomDeque<int>();
    for (int i = 0; i < 10; i+=2)
    {
        cDeq.PushBack(i+1);
        cDeq.PushFront(i);
    }

    for (int i = 0; i < cDeq.Num(); i++)
    {
        cout << cDeq[i] << endl;
    }

    for (CustomDeque<int>::iterator it = cDeq.begin(); it != cDeq.end(); ++it)
    {
        cout << *it << endl;;
    }
    cDeq.Clear();

    cout << "Vector ===============================" << endl;
    CustomVector<int> cVec = CustomVector<int>();
    CustomVector<int> c2Vec = CustomVector<int>();
    for (int i = 10; i >0; i--)
    {
       c2Vec.Add(i);
    }
    cVec = c2Vec;
    for (CustomVector<int>::iterator it = c2Vec.begin(); it != c2Vec.end(); ++it)
    {
        cout << *it << endl;
    }

    for (auto val : c2Vec)
    {
        cout << val << endl;
    }
    cVec.Clear();
    c2Vec.Clear();

    cout << "List ===============================" << endl;
    CustomList<int> cList = CustomList<int>();

    cList.AddToEnd(32);
    cList.AddToEnd(4);
    cList.AddToEnd(1);
    cList.AddToStart(23);
    cList.AddToStart(74);
    cList.AddToStart(156);

    for (CustomList<int>::iterator it = cList.begin(); it != cList.end(); ++it)
    {
        cout << *it << endl;
    }

    CustomList<int>::Node* tmp = cList.begin().ptr;
    while (tmp != nullptr)
    {
        cout << tmp->Data << endl;
        tmp = tmp->next;
    }
   
    cList.Clear();



    cout << "Print" << endl;
    system("Pause");
    return 0;
}


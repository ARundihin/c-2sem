#include <iostream>
#include "List.h"
#include <clocale>

using namespace std;

int main()
{
    List<char> L1;
    List<char> L2;
    List<char> L;
    int s1, s2;
    char a;

    cout << "Enter size of L1" << endl;
    cin >> s1;
    cout << "Enter L1" << endl;

    for (int i = 0; i < s1; i++)
    {
        cin >> a;
        L1.addElement(a);
    }

    cout << "Enter size of L2" << endl;
    cin >> s2;
    cout << "Enter L2" << endl;

    for (int i = 0; i < s2; i++)
    {
        cin >> a;
        L2.addElement(a);
    }

    Node* cur1 = L1.GetHead();
    Node* cur2 = L2.GetHead();
    bool o = true;

    while (cur1 != nullptr)
    {
        char k = cur1->data;

        while (cur2 != nullptr)
        {
            if (cur2->data == k)
            {
                o = false;
            }

            cur2 = cur2->next;
        }

        if (o)
        {
            L.pushFront(k);
        }

        o = true;
        cur2 = L2.GetHead();
        cur1 = cur1->next;
    }

    cur1 = L1.GetHead();
    cur2 = L2.GetHead();

    while (cur2 != nullptr)
    {
        char k = cur2->data;

        while (cur1 != nullptr)
        {
            if (cur1->data == k)
            {
                o = false;
            }

            cur1 = cur1->next;
        }

        if (o)
        {
            L.pushFront(k);
        }

        o = true;
        cur1 = L1.GetHead();
        cur2 = cur2->next;
    }

    L.Print();

    return 0;
}

//void CreateListL(List<char>&& L1, List<char>&& L2, List<char>&& L)
//{
//    Node* cur1 = L1.GetHead();
//    Node* cur2 = L2.GetHead();
//    bool o = true;
//
//    while (cur1 != nullptr)
//    {
//        char k = cur1->data;
//
//        while (cur2 != nullptr )
//        {
//            if (cur2->data == k)
//            {
//                o = false;
//            }
//
//            cur2 = cur2->next;
//        }
//
//        if (o)
//        {
//            L.pushFront(k);
//        }
//
//        o = true;
//        cur2 = L2.GetHead();
//        cur1 = cur1->next;
//    }
//
//    cur1 = L1.GetHead();
//    cur2 = L2.GetHead();
//
//    while (cur2 != nullptr)
//    {
//        char k = cur2->data;
//
//        while (cur1 != nullptr)
//        {
//            if (cur1->data == k)
//            {
//                o = false;
//            }
//
//            cur1 = cur1->next;
//        }
//
//        if (o)
//        {
//            L.pushFront(k);
//        }
//
//        o = true;
//        cur1 = L1.GetHead();
//        cur2 = cur2->next;
//    }
//
//    L.Print();
//}

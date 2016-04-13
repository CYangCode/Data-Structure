#include <iostream>
#include <list>

using namespace std;

class Elem
{
private:
    int size;
    int * array;
public:
    Elem(int _size = 0)
    {
        this->size = _size;
        array = new int[size];
    }

    int getSize()const
    {
        return this->size;
    }

    void insert(int pos, int num)
    {
        if (pos > (size++)) return;
        int * temp = new int[size];
        for (int i = 0; i < size - 1; ++i)
        {
            temp[i] = array[i];
        }
        array = temp;
        for (int i = size - 1; i >= pos; --i)
        {
            array[i] = array[i - 1];
        }
        array[pos] = num;
    }

    void print()
    {
        for (int i = 0; i < size; ++i)
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }
};

int permutation(Elem elem, int size)
{
    if (elem.getSize() == size)
    {
        elem.print();
        return 1;
    }
    else
    {
        int count = 0;
        for (int i = 0; i < elem.getSize() + 1; ++i)
        {
            Elem temp = elem;
            temp.insert(i, temp.getSize() + 1);
            count += permutation(temp, size);
        }
        return count;
    }
}

int permutation(list<int> list, int size)
{
    if (size == list.size())
    {
        for (int i: list)
        {
            cout << i << " ";
        }
        cout << endl;
        return 1;
    }
//    for (auto ite = list.iterator(); ite) {
//        list.insert()
//    }
}
int main()
{
    list<int> list1;
    for (int i = 0; i < 5; ++i)
    {
        list1.push_back(i);
    }
    for (auto ite = list1.begin(); ite != list1.end(); ++ite)
    {
        list<int>  list2 = list1;
        list2.insert(ite, 5);
        for (list<int>::iterator ite = list2.begin(); ite != list2.end(); ++ite)
        {
            cout << *ite << " ";
        }
        cout << endl;
    }

    for (int i: list1)
    {
        cout << i << " ";
    }
    cout << endl;
    cout << endl;
}

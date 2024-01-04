// Implementation of List using array

#include <iostream>
using namespace std;

class List
{
public:
    int *A;
    int size;
    int length;

    List(int size)
    {
        this->size = size;
        A = new int[size];
        length = 0;
    }
    void Display();
    void Append(int x);
    void Insert(int index, int x);
    int Delete(int index);
    int BinarySearch(int key);
};

void List::Display()
{
    for (int i = 0; i < length; i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void List::Append(int x)
{
    if (length < size)
    {
        A[length++] = x;
    }
}

void List::Insert(int index, int x)
{
    if (index >= 0 && index <= length)
    {
        for (int i = length; i > index; i--)
        {
            A[i] = A[i - 1];
        }
        A[index] = x;
        length++;
    }
}

int List::Delete(int index)
{
    int x = 0;
    if (index >= 0 && index < length)
    {
        x = A[index];
        for (int i = index; i < length - 1; i++)
        {
            A[i] = A[i + 1];
        }
        length--;
        return x;
    }
    return 0;
}

int List::BinarySearch(int key)
{
    int l, mid, h;
    l = 0;
    h = length - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;
        if (key == A[mid])
        {
            return mid;
        }
        else if (key < A[mid])
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}

int main()
{
    List l(10);

    l.Append(10);
    l.Append(20);
    l.Append(30);
    l.Append(40);
    l.Append(50);

    l.Display();

    l.Insert(3, 25);

    l.Display();

    cout << l.Delete(3) << endl;

    l.Display();

    cout << l.BinarySearch(40) << endl;

    return 0;
}

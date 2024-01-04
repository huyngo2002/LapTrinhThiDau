#include <bits/stdc++.h>
using namespace std;
template <class T>
class DLinkedList
{
public:
    class Iterator; //forward declaration
    class Node;     //forward declaration
protected:
    Node *head;
    Node *tail;
    int count;
public:
    DLinkedList() : head(NULL), tail(NULL), count(0) {};
    ~DLinkedList();
    void add(const T &e);
    void add(int index, const T &e);
    T removeAt(int index);
    bool removeItem(const T &item);
    bool empty();
    int size();
    void clear();
    T get(int index);
    void set(int index, const T &e);
    int indexOf(const T &item);
    bool contains(const T &item);
    string toString();
    Iterator begin()
    {
        return Iterator(this, true);
    }
    Iterator end()
    {
        return Iterator(this, false);
    }
public:
    class Node
    {
    private:
        T data;
        Node *next;
        Node *previous;
        friend class DLinkedList<T>;

        Iterator begin()
        {
            return Iterator(this, true);
        }
        Iterator end()
        {
            return Iterator(this, false);
        }

    public:
        Node()
        {
            this->previous = NULL;
            this->next = NULL;
        }

        Node(const T &data)
        {
            this->data = data;
            this->previous = NULL;
            this->next = NULL;
        }
    };
    class Iterator
    {
    private:
        DLinkedList<T> *pList;
        Node *current;
        int index; // is the index of current in pList
    public:
        Iterator(DLinkedList<T> *pList, bool begin);
        Iterator &operator=(const Iterator &iterator);
        void set(const T &e);
        T &operator*();
        bool operator!=(const Iterator &iterator);
        void remove();

        // Prefix ++ overload
        Iterator &operator++();

        // Postfix ++ overload
        Iterator operator++(int);
    };
};
/*
 * TODO: Implement class Iterator's method
 * Note: method remove is different from SLinkedList, which is the advantage of DLinkedList
 */
template <class T>
DLinkedList<T>::Iterator::Iterator(DLinkedList<T> *pList, bool begin)
{
    this->pList = pList;
    if (begin)
    {
        current = pList->head;
        index = 0;
    }
    else
    {
        current = nullptr;
        index = pList->size();
    }
}

template <class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator=(const DLinkedList<T>::Iterator &iterator)
{
    this->pList = iterator.pList;
    this->current = iterator.current;
    this->index = iterator.index;
    return *this;
}

template <class T>
void DLinkedList<T>::Iterator::set(const T &e)
{
    if (current)
    {
        current->data = e;
    }
}

template<class T>
T& DLinkedList<T>::Iterator::operator*()
{
    if (current)
    {
        return current->data;
    }
    // Handle case where current is nullptr
    throw std::out_of_range("Iterator is out of range");
}

template<class T>
void DLinkedList<T>::Iterator::remove()
{
    /*
    * TODO: delete Node in pList which Node* current point to.
    *       After that, Node* current point to the node before the node just deleted.
    *       If we remove first node of pList, Node* current point to nullptr.
    *       Then we use operator ++, Node* current will point to the head of pList.
    */
    /*
    if (current)
    {
        Node *nextNode = current->next;
        Node *prevNode = current->previous;

        if (prevNode)
        {
            prevNode->next = nextNode;
        }
        else
        {
            pList->head = nextNode;
        }

        if (nextNode)
        {
            nextNode->previous = prevNode;
        }
        else
        {
            pList->tail = prevNode;
        }

        delete current;
        current = prevNode;
        pList->count--;
    }
    */
    /*
    if (current == nullptr || this->pList->head == nullptr
        || this->index < 0 || this->index >= this->pList->size())
        throw std::out_of_range("Segmentation fault!");
    Node* pDelete;
    if (this->index == 0)
    {
        pDelete = this->pList->head;
        this->current = nullptr;
        this->index = -1;
    }
    else
    {
        Node* prev = this->pList->head;
        for (int i = 1; i < this->index; i++)
        {
            if (prev->next == nullptr) break;
            prev = prev->next;
        }
        pDelete = prev->next;
        if (pDelete) prev->next = pDelete->next;
        if (this->index == this->pList->size() - 1)
            this->pList->tail = prev;
        this->current = prev;
        this->index = this->index - 1;
    }
    delete pDelete;
    */
    /*
    if (current == nullptr) throw std::out_of_range("Segmentation fault!");
    if (index == 0)
    {
        current = nullptr;
        index--;
        pList->removeAt(0);
        return;
    }
    current = current->previous;
    pList->removeAt(index);
    index--;
    */
    if (current == nullptr)
    {
        throw std::out_of_range("Iterator is out of range");
    }

    Node* nextNode = current->next;
    Node* prevNode = current->previous;

    if (prevNode)
    {
        prevNode->next = nextNode;
    }
    else
    {
        pList->head = nextNode;
    }

    if (nextNode)
    {
        nextNode->previous = prevNode;
    }
    else
    {
        pList->tail = prevNode;
    }

    delete current;
    current = prevNode;
    pList->count--;
}

template<class T>
bool DLinkedList<T>::Iterator::operator!=(const DLinkedList::Iterator &iterator)
{
    //return index != iterator.index;
    if (this->current == iterator.current && this->index == iterator.index) return false;
    return true;
}

template<class T>
typename DLinkedList<T>::Iterator& DLinkedList<T>::Iterator::operator++()
{
    if (current)
    {
        current = current->next;
        index++;
    }
    return *this;
}

template<class T>
typename DLinkedList<T>::Iterator DLinkedList<T>::Iterator::operator++(int)
{
    Iterator old = *this;
    ++(*this);  // Call the prefix increment operator
    return old;
}
template<class T>
T DLinkedList<T>::get(int index)
{
    /* Give the data of the element at given index in the list. */
    if (index < 0 || index >= count)
    {
        throw out_of_range("Index out of range");
    }

    Node* current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    return current->data;

}

template <class T>
void DLinkedList<T>::set(int index, const T& e)
{
    /* Assign new value for element at given index in the list */
    if (index < 0 || index >= count)
    {
        throw out_of_range("Index out of range");
    }

    Node* current = head;
    for (int i = 0; i < index; i++)
    {
        current = current->next;
    }
    current->data = e;
}

template<class T>
bool DLinkedList<T>::empty()
{
    /* Check if the list is empty or not. */
    return count == 0;
}

template<class T>
int DLinkedList<T>::indexOf(const T& item)
{
    /* Return the first index wheter item appears in list, otherwise return -1 */
    Node* current = head;
    for (int index = 0; index < count; index++)
    {
        if (current->data == item)
        {
            return index;
        }
        current = current->next;
    }
    return -1;
}

template<class T>
bool DLinkedList<T>::contains(const T& item)
{
    /* Check if item appears in the list */
    return indexOf(item) != -1;
}
template <class T>
void DLinkedList<T>::add(const T& e)
{
    /* Insert an element into the end of the list. */
    Node* newNode = new Node(e);
    if (head == nullptr)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    count++;
}

template<class T>
void DLinkedList<T>::add(int index, const T& e)
{
    /* Insert an element into the list at given index. */
    if (index < 0 || index > count)
    {
        throw out_of_range("Index out of range");
    }

    Node* newNode = new Node(e);
    if (index == 0)
    {
        newNode->next = head;
        head = newNode;
        if (count == 0)
        {
            tail = newNode;
        }
        else
        {
            newNode->next->previous = newNode;
        }
    }
    else if (index == count)
    {
        tail->next = newNode;
        newNode->previous = tail;
        tail = newNode;
    }
    else
    {
        Node* current = head;
        for (int i = 0; i < index - 1; i++)
        {
            current = current->next;
        }
        newNode->next = current->next;
        newNode->previous = current;
        current->next->previous = newNode;
        current->next = newNode;
    }
    count++;
}

template<class T>
int DLinkedList<T>::size()
{
    /* Return the length (size) of list */
    return count;
    return 0;
}
template <class T>
DLinkedList<T>::~DLinkedList()
{
    // Implement the destructor here
    clear(); // You can call the clear() function to deallocate all the nodes in the list
}
template <class T>
void DLinkedList<T>::clear()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *next = current->next;
        delete current;
        current = next;
    }
    head = tail = nullptr;
    count = 0;
}
template<class T>
T DLinkedList<T>::removeAt(int index)
{
    T e;
    Node* temp = head;
    int counting = 0;
    while (counting < (index - 1))
    {
        temp = temp->next;
    }
    if (index == 0)
    {
        temp = temp->next;
        head = temp;
    }
    else
    {
        e = temp->next->data;
        temp->next = temp->next->next;
    }
    return e;
}
int main()
{
    DLinkedList<int> list;
    int size = 10;
    for (int idx = 0; idx < size; idx++)
    {
        list.add(idx);
    }

    DLinkedList<int>::Iterator it = list.begin();

    while (it != list.end())
    {
        it.remove();
        it++;

    }
    it = list.begin();
    while (it != list.end())
    {
        cout << *it << " |";
        //it.remove();
        it++;

    }
    //cout << list.toString();
    return 0;
}

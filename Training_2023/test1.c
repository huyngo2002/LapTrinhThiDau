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

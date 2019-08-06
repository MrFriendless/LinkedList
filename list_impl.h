//========= _iterator ==================================
template <class T>
T& _iterator<T>::operator* ()
{
    return _node->value;
}

template <class T>
bool _iterator<T>::operator!= (const _iterator<T>& arg)
{
    if (_node != arg._node)
        return true;
    return false;
}

template <class T>
_iterator<T> _iterator<T>::operator++ (int)
{
    _iterator<T> tmp = *this;
    _node = _node->next_node;
    return tmp;
}

template <class T>
_iterator<T> _iterator<T>::operator-- (int)
{
    _iterator<T> tmp = *this;
    _node = _node->previous_node;
    return tmp;
}

template <class T>
_iterator<T>& _iterator<T>::operator++ ()
{
    _node = _node->next_node;
    return *this;
}

//====================================================

//=========== List ===================================
template <class T>
List<T>::List()
{
    end_node = new Node<T>;
    first_node = end_node;
    last_node = end_node;
    _size = 0;
}

template <class T>
void List<T>::add(T arg)
{
    _size++;
    Node<T> * tmpNode = last_node;
    last_node = new Node<T>;
    if (tmpNode != end_node) {
        tmpNode->next_node = last_node;
        last_node->previous_node = tmpNode;
    } else {
        last_node->previous_node = end_node;
        first_node = last_node;
        end_node->next_node = last_node;
    }
    last_node->value = arg;
    last_node->next_node = end_node;
    end_node->previous_node = last_node;
}

template <class T>
void List<T>::remove(_iterator<T>& arg)
{
    _size--;
    if (first_node == last_node) {
        first_node = end_node;
        last_node = end_node;
    } else {
        if (arg._node == first_node)
            first_node = arg._node->next_node;
        if (arg._node == last_node)
            last_node = arg._node->previous_node;
    }
    arg._node->previous_node->next_node = arg._node->next_node;
    arg._node->next_node->previous_node = arg._node->previous_node;
    delete arg._node;
}

template <class T>
int List<T>::size()
{
    return _size;
}

template <class T>
_iterator<T> List<T>::begin()
{
    return iterator(first_node);
}

template <class T>
_iterator<T> List<T>::end()
{
    return iterator(end_node);
}

template <class T>
_iterator<T> List<T>::last()
{
    return iterator(last_node);
}

template <class T>
List<T>::~List()
{
    last_node = first_node;
    while (last_node != end_node) {
        Node<T> * tmpNode = last_node->next_node;
        delete last_node;
        last_node = tmpNode;
    }
    delete end_node;
}

//================================================

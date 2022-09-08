#pragma once

// Construct
template <typename T>
Stack<T>::Stack() : _size(0), _head(nullptr) {}

template <typename T>
Stack<T>::Stack(std::initializer_list<value_type> const &items) : _size(0), _head(nullptr) {
    for (auto it = items.begin(); it != items.end(); it++) {
        this->push(*it);
    }
}

template <typename T>
Stack<T>::Stack(const Stack &s) : _size(0), _head(nullptr) {
    if (this != &s && s._size) {
        Node<T> *bufferNode = s._head;

        while (bufferNode->getPastElement()) {
            push(bufferNode->getData());
            bufferNode = bufferNode->getPastElement();
        }

        push(bufferNode->getData());
        reverse();
    }
}

template <typename T>
void Stack<T>::reverse() {
    if (_size) {
        Node<T> *previousNode, *currentNode, *nextNode;
        currentNode = _head;
        previousNode = _head;
        currentNode = currentNode->getPastElement();
        previousNode->setPastElement(nullptr);

        while (currentNode != nullptr) {
            nextNode = currentNode->getPastElement();
            currentNode->setPastElement(previousNode);
            previousNode = currentNode;
            currentNode = nextNode;
        }

        _head = previousNode;
    }
}

template <typename T>
Stack<T>::Stack(Stack &&s) : _size(0), _head(nullptr) {
    if (this != &s) {
        std::swap(_size, s._size);
        std::swap(_head, s._head);
    }
}

//  Destructor
template <typename T>
Stack<T>::~Stack() {
    while (_head) {
        this->pop();
    }
}

//  Methods
template <typename T>
void Stack<T>::push(const_reference value) {
    if (_size > max_size()) {
        throw std::out_of_range("Can`t push! Stack is full");
    }

    Node<T> *bufferNode = new Node<T>(value);

    if (_size) {
        bufferNode->setPastElement(_head);
    }

    setRoot(bufferNode);
    _size++;
}

template <typename T>
typename Stack<T>::const_reference Stack<T>::top() {
    if (!_size) {
        throw std::out_of_range("Stack is empty");
    }

    return this->_head->Node<T>::getData();
}

template <typename T>
T Stack<T>::pop() {
    if (!_size) {
        throw std::out_of_range("Can`t pop! Stack is empty");
    }

    Node<T> *buffer = _head->getPastElement();
    T popData = _head->getNodeData();
    delete _head;
    this->setRoot(buffer);
    _size--;
    return popData;
}

template <typename T>
bool Stack<T>::empty() {
    return _size == 0;
}

template <typename T>
typename Stack<T>::size_type Stack<T>::size() {
    return _size;
}

template <class T>
void Stack<T>::setRoot(Node<T> *element) {
    this->_head = element;
}

template <class T>
void Stack<T>::swap(Stack<T> &other) {
    if (this != &other) {
        std::swap(_head, other._head);
        std::swap(other._size, _size);
    }
}

//  Overload
template <class T>
Stack<T> &Stack<T>::operator=(Stack<T> &&s) {
    if (this != &s) {
        while (_head) {
            pop();
        }

        std::swap(_size, s._size);
        std::swap(_head, s._head);
    }

    return *this;
}

template <class T>
template <typename... Args>
void Stack<T>::emplace_front(Args &&... args) {
    const size_type sizeArgs = sizeof...(Args);
    value_type argsArray[sizeArgs] = {args...};

    for (size_type i = 0; i < sizeArgs; ++i) {
        push(argsArray[i]);
    }
}

template <typename T>
typename Stack<T>::size_type Stack<T>::max_size() {
    return std::numeric_limits<size_t>::max() / (sizeof(Node<T>));
}

template <typename T>
T Stack<T>::peek() {
    return _head->getNodeData();
}

template <typename T>
void Stack<T>::init() {
    *this = new Stack<T>();
}

// Construct
template <typename T>
Queue<T>::Queue() : _size(0), _head(nullptr), _tail(nullptr) {}

template <typename T>
Queue<T>::Queue(std::initializer_list<value_type> const &items) : _size(0), _head(nullptr), _tail(nullptr) {
    for (auto it = items.begin(); it != items.end(); it++) {
        this->push(*it);
    }
}

template <typename T>
Queue<T>::Queue(const Queue &s) : _size(0), _head(nullptr), _tail(nullptr) {
    if (this != &s && s._size) {
        _size = 0;
        Node<T> *bufferNode = s._head;

        while (bufferNode->getPastElement()) {
            push(bufferNode->getData());
            bufferNode = bufferNode->getPastElement();
        }

        push(bufferNode->getData());
        setTail(bufferNode);
        reverse();
    }
}

template <typename T>
void Queue<T>::reverse() {
    if (_size) {
        _tail = _head;
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
Queue<T>::Queue(Queue &&s) : _size(0), _head(nullptr), _tail(nullptr) {
    if (this != &s) {
        std::swap(_size, s._size);
        std::swap(_head, s._head);
        std::swap(_tail, s._tail);
    }
}

//  Destructor
template <typename T>
Queue<T>::~Queue() {
    while (_head) {
        this->pop();
    }
}

template <typename T>
void Queue<T>::push(const T &value) {
    if (_size > max_size()) {
        throw std::out_of_range("Can`t push! Queue is full");
    }

    Node<T> *bufferNode = new Node<T>(value);

    if (_size) {
        _tail->setPastElement(bufferNode);
    }

    setTail(bufferNode);

    if (!_size) {
        setRoot(bufferNode);
    }

    _size++;
}

template <typename T>
typename Queue<T>::const_reference Queue<T>::front() {
    if (!_size) {
        throw std::out_of_range("Queue is empty");
    }

    return this->_head->Node<T>::getData();
}

template <typename T>
typename Queue<T>::const_reference Queue<T>::back() {
    if (!_size) {
        throw std::out_of_range("Queue is empty");
    }

    return this->_tail->Node<T>::getData();
}

template <typename T>
T Queue<T>::pop() {
    if (!_size) {
        throw std::out_of_range("Queue is empty");
    }

    Node<T> *buffer = _head->getPastElement();
    T popData = _head->getNodeData();
    delete _head;
    this->setRoot(buffer);

    _size--;
    return popData;
}

template <typename T>
bool Queue<T>::empty() {
    return _size == 0;
}

template <typename T>
typename Queue<T>::size_type Queue<T>::size() {
    return _size;
}

template <class T>
void Queue<T>::setRoot(Node<T> *element) {
    this->_head = element;
}

template <class T>
void Queue<T>::setTail(Node<T> *element) {
    this->_tail = element;
}

template <class T>
Queue<T> &Queue<T>::operator=(Queue<T> &&s) {
    if (this != &s) {
        while (_head) {
            pop();
        }

        std::swap(_size, s._size);
        std::swap(_head, s._head);
        std::swap(_tail, s._tail);
    }

    return *this;
}

template <class T>
void Queue<T>::swap(Queue<T> &other) {
    if (this != &other) {
        std::swap(_head, other._head);
        std::swap(_tail, other._tail);
        std::swap(_size, other._size);
    }
}

template <class T>
template <typename... Args>
void Queue<T>::emplace_back(Args &&... args) {
    const size_type sizeArgs = sizeof...(Args);
    value_type argsArray[sizeArgs] = {args...};

    for (size_type i = 0; i < sizeArgs; ++i) {
        push(argsArray[i]);
    }
}

template <typename T>
typename Queue<T>::size_type Queue<T>::max_size() {
    return (std::numeric_limits<size_type>::max() / (sizeof(Node<T>))) / 2;
}

template <typename T>
T Queue<T>::peek() {
    return _head->getNodeData();
}

template <typename T>
void Queue<T>::init() {
    *this = new Queue<T>();
}

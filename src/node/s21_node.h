#pragma once

#include <iostream>

template <class T>
class Node {
public:
    explicit Node(const T &value);
    Node(Node<T> const &other);
    Node(Node<T> &&other);
    ~Node();
    Node<T> &operator=(Node<T> const &other);
    Node<T> &operator=(Node<T> &&other);

    const T &getData();
    void setPastElement(Node *element);
    Node *getPastElement();
    T getNodeData();

private:
    Node<T> *_pastElement;
    T _data;
    void clean();
};

#include "s21_node.inl"

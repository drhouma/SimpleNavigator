#pragma once

#include <iostream>
#include <limits>

#include "../node/s21_node.h"

template <class T>
class Stack {
public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using size_type = size_t;

private:
    size_t _size;
    Node<T> *_head;

    void setRoot(Node<T> *element);
    void reverse();
    size_type max_size();

public:
    Stack();
    explicit Stack(std::initializer_list<value_type> const &items);
    explicit Stack(const Stack &s);
    explicit Stack(Stack &&s);
    ~Stack();

    Stack &operator=(Node<T> const &other);
    Stack &operator=(Node<T> &&other);

    void init();
    void push(const_reference value);
    value_type pop();
    value_type peek();

    const_reference top();
    bool empty();
    size_type size();
    void swap(Stack<T> &other);
    Stack<value_type> &operator=(Stack<T> &&s);
    template <typename... Args>
    void emplace_front(Args &&...args);
};

#include "s21_stack.inl"

#pragma once

#include <iostream>
#include <limits>

#include "../node/s21_node.h"

template <class T>
class Queue {
public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using size_type = size_t;

private:
    size_t _size;
    Node<T> *_head;
    Node<T> *_tail;

    void setRoot(Node<T> *element);
    void setTail(Node<T> *element);
    void reverse();
    size_type max_size();

public:
    Queue();
    explicit Queue(std::initializer_list<value_type> const &items);
    explicit Queue(const Queue &s);
    explicit Queue(Queue &&s);
    ~Queue();

    Queue &operator=(Node<T> const &other);
    Queue &operator=(Node<T> &&other);

    void init();
    void push(const_reference value);
    value_type peek();
    value_type pop();

    const_reference front();
    const_reference back();
    bool empty();
    size_type size();
    void swap(Queue<T> &other);
    Queue<value_type> &operator=(Queue<T> &&s);
    template <typename... Args>
    void emplace_back(Args &&... args);
};

#include "s21_queue.inl"

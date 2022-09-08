/**
 * @file    breadth_first_search.cpp
 * @authors telvina<at>student.21-school.ru
 * @authors sreanna<at>student.21-school.ru
 * @authors jmadie<at>student.21-school.ru
 * @date    04/09/22
 */

#include "s21_graph_algorithms.h"

auto GraphAlgorithms::breadthFirstSearch(Graph &graph, int startVertex) -> std::vector<int> {
    if (startVertex < 1 || startVertex > graph.size()) {
        throw std::invalid_argument("Incorrect starting vertex");
    }

    std::vector<int> bfsResult;
    std::vector<bool> visitedVertex(graph.size());
    Queue<int> vertexStack;

    visitedVertex[startVertex - 1] = true;
    vertexStack.push(startVertex - 1);

    while (!vertexStack.empty()) {
        bfsResult.push_back(vertexStack.peek() + 1);
        int current = vertexStack.pop();

        for (int i = 0; i < graph.size(); i++) {
            if (graph(current, i) && !visitedVertex[i]) {
                vertexStack.push(i);
                visitedVertex[i] = true;
            }
        }
    }

    return bfsResult;
}

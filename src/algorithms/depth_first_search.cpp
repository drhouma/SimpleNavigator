/**
 * @file    depth_first_search.cpp
 * @authors telvina<at>student.21-school.ru
 * @authors sreanna<at>student.21-school.ru
 * @authors jmadie<at>student.21-school.ru
 * @date    04/09/22
 */

#include "s21_graph_algorithms.h"

auto GraphAlgorithms::depthFirstSearch(Graph &graph, int startVertex) -> std::vector<int> {
    if (startVertex < 1 || startVertex > graph.size()) {
        throw std::invalid_argument("incorrect starting vertex");
    }

    std::vector<int> dfsResult;
    std::vector<bool> visitedVertex(graph.size());
    Stack<int> vertexStack;
    visitedVertex[startVertex - 1] = true;
    vertexStack.push(startVertex - 1);

    while (!vertexStack.empty()) {
        dfsResult.push_back(vertexStack.peek() + 1);
        int current = vertexStack.pop();

        for (int i = graph.size() - 1; i >= 0; i--) {
            if (graph(current, i) && !visitedVertex[i]) {
                vertexStack.push(i);
                visitedVertex[i] = true;
            }
        }
    }

    return dfsResult;
}

/**
 * @file    floyd_warshall_algorithm.cpp
 * @authors telvina<at>student.21-school.ru
 * @authors sreanna<at>student.21-school.ru
 * @authors jmadie<at>student.21-school.ru
 * @date    04/09/22
 */

#include "s21_graph_algorithms.h"

auto GraphAlgorithms::getShortestPathsBetweenAllVertices(Graph &graph) -> Matrix<int> {
    Matrix<int> shortestPath(graph.adjacencyMatrix());

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            if (shortestPath(i, j) == 0 && i != j) shortestPath(i, j) = std::numeric_limits<int>::max();
        }
    }

    for (int i = 0; i < graph.size(); i++) {
        for (int j = 0; j < graph.size(); j++) {
            for (int k = 0; k < graph.size(); k++) {
                shortestPath(j, k) = std::min(shortestPath(j, k), (shortestPath(j, i) + shortestPath(i, k)));
            }
        }
    }

    return shortestPath;
}

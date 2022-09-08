/**
 * @file    prim_algorithm.cpp
 * @authors telvina<at>student.21-school.ru
 * @authors sreanna<at>student.21-school.ru
 * @authors jmadie<at>student.21-school.ru
 * @date    04/09/22
 */

#include <limits>
#include <vector>

#include "s21_graph_algorithms.h"

auto GraphAlgorithms::getLeastSpanningTree(Graph& graph) -> Matrix<int> {
    auto setMinimalEdge = [&graph](Matrix<int>& spanningTree, std::vector<bool>& selectedEdges) {
        int row{0};
        int col{0};
        int min{std::numeric_limits<int>::max()};
        auto matrix = graph.adjacencyMatrix();
        for (int i{0}; i < matrix.rows(); ++i) {
            if (selectedEdges[i]) {
                for (int j{0}; j < matrix.cols(); ++j) {
                    if (!selectedEdges[j] && matrix(i, j) != 0 && min > matrix(i, j)) {
                        min = matrix(i, j);
                        row = i;
                        col = j;
                    }
                }
            }
        }
        selectedEdges[col] = true;
        spanningTree(row, col) = matrix(row, col);
    };
    std::vector<bool> selectedEdges{};
    Matrix<int> spanningTree{graph.size(), graph.size()};
    selectedEdges.push_back(true);
    for (int i{1}; i < graph.size(); ++i) {
        selectedEdges.push_back(false);
    }
    int edgesPassed{1};
    auto matrix = graph.adjacencyMatrix();
    while (edgesPassed < graph.size()) {
        setMinimalEdge(spanningTree, selectedEdges);
        ++edgesPassed;
    }
    return spanningTree;
}
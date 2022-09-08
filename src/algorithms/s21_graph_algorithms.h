/**
 * @file    s21_graph_algorithms.h
 * @authors telvina<at>student.21-school.ru
 * @authors sreanna<at>student.21-school.ru
 * @authors jmadie<at>student.21-school.ru
 * @date    04/09/22
 */

#pragma once

#include <limits>
#include <set>
#include <vector>

#include "../graph/s21_graph.h"
#include "../queue/s21_queue.h"
#include "../stack/s21_stack.h"

/**
 * @class GraphAlgorithms
 * @brief This class holds the methods of algorithms on graphs
 */

struct TspResult {
    std::vector<int> vertices;
    double distance;
    TspResult() : distance(0) {}
};

class GraphAlgorithms {
private:
    static auto addVertexPath(Graph &graph, int &index, int markVertexWeigth, Matrix<int> &dijkstraMatrix,
                              int path[], std::set<int> &visitedVertex, int dijkstraMatrixIndex) -> void;
    static auto addFirstVertexPath(Graph &graph, int startVertex, Matrix<int> &dijkstraMatrix, int path[],
                                   std::set<int> &visitedVertex) -> void;

public:
    static auto depthFirstSearch(Graph &graph, int startVertex) -> std::vector<int>;
    static auto breadthFirstSearch(Graph &graph, int startVertex) -> std::vector<int>;
    static auto getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2) -> int;
    static auto getShortestPathsBetweenAllVertices(Graph &graph) -> Matrix<int>;
    static auto getLeastSpanningTree(Graph &graph) -> Matrix<int>;
    static auto solveTravelingSalesmanProblem(Graph &graph) -> TspResult;
};

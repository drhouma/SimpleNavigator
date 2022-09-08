/**
 * @file    dijkstra_algorithm.cpp
 * @authors telvina<at>student.21-school.ru
 * @authors sreanna<at>student.21-school.ru
 * @authors jmadie<at>student.21-school.ru
 * @date    04/09/22
 */

#include "s21_graph_algorithms.h"

auto GraphAlgorithms::getShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2) -> int {
    if (vertex1 > graph.size() || vertex2 > graph.size() || vertex1 < 1 || vertex2 < 1) {
        throw std::invalid_argument("incorrect input vertexes");
    }

    std::set<int> visitedVertex;
    int path[graph.size()];
    Matrix<int> dijkstraMatrix(graph.size(), graph.size());

    addFirstVertexPath(graph, vertex1, dijkstraMatrix, path, visitedVertex);

    int lastVisitedVertex = vertex1 - 1;

    for (int i = 1; i < graph.size(); i++) {
        if (lastVisitedVertex == vertex2 - 1) {
            return path[vertex2 - 1];
        }

        addVertexPath(graph, lastVisitedVertex, path[lastVisitedVertex], dijkstraMatrix, path, visitedVertex,
                      i - 1);
    }

    return path[vertex2 - 1];
}

void GraphAlgorithms::addFirstVertexPath(Graph &graph, int startVertex, Matrix<int> &dijkstraMatrix,
                                         int path[], std::set<int> &visitedVertex) {
    for (int i = 0; i < graph.size(); i++) {
        if (i == startVertex - 1) {
            dijkstraMatrix(i, 0) = 0;
            visitedVertex.insert(i);
            path[i] = 0;
        } else {
            dijkstraMatrix(i, 0) = std::numeric_limits<int>::max();
        }
    }
}

void GraphAlgorithms::addVertexPath(Graph &graph, int &index, int markVertexWeigth,
                                    Matrix<int> &dijkstraMatrix, int path[], std::set<int> &visitedVertex,
                                    int dijkstraMatrixIndex) {
    std::pair<int, int> min = {std::numeric_limits<int>::max(), std::numeric_limits<int>::max()};

    for (int i = 0; i < graph.size(); i++) {
        if (!visitedVertex.count(i)) {
            if (graph(index, i) != 0) {
                dijkstraMatrix(i, dijkstraMatrixIndex + 1) =
                    std::min(dijkstraMatrix(i, dijkstraMatrixIndex), markVertexWeigth + graph(index, i));
                if (min.second > dijkstraMatrix(i, dijkstraMatrixIndex + 1))
                    min = {i, dijkstraMatrix(i, dijkstraMatrixIndex + 1)};
            } else {
                dijkstraMatrix(i, dijkstraMatrixIndex + 1) = dijkstraMatrix(i, dijkstraMatrixIndex);
                if (min.second > dijkstraMatrix(i, dijkstraMatrixIndex + 1))
                    min = {i, dijkstraMatrix(i, dijkstraMatrixIndex + 1)};
            }
        }
    }

    path[min.first] = min.second;
    visitedVertex.insert(min.first);
    index = min.first;
}

/**
 * @file    console_interface.h
 * @authors telvina<at>student.21-school.ru
 * @authors sreanna<at>student.21-school.ru
 * @authors jmadie<at>student.21-school.ru
 * @date    04/09/22
 */

#pragma once

#include "../algorithms/s21_graph_algorithms.h"
#include "../graph/s21_graph.h"

/**
 * @class ConsoleInterface
 * @brief Implements simple interface in cmd
 */

class ConsoleInterface {
private:
    Graph m_graph = Graph(10);
    bool m_isCorrectGraphLoad = false;

    auto mainMenuItem() -> int;
    auto loadGraph() -> void;
    auto viewBFS() -> void;
    auto viewDFS() -> void;
    auto viewDijkstra() -> void;
    auto viewFloydWarshall() -> void;
    auto viewSpanningTree() -> void;
    auto ViewTSPViaAntColony() -> void;
    auto printVector(const std::vector<int> data) -> void;
    auto printMatrix(const Matrix<int> matrix) -> void;
    auto printError(const std::string error) -> void;
    auto checkLoad() -> void;

public:
    ConsoleInterface() {}
    ~ConsoleInterface() {}

    auto viewMainMenu() -> void;
};

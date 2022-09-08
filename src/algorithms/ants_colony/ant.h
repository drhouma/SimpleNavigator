#ifndef S21_ANT_H
#define S21_ANT_H
#include <vector>

#include "../../graph/s21_graph.h"
#include "common_funcs.h"

class Ant {
public:
    Ant(size_t vertex);
    Ant() = delete;

    auto FindPath(Graph& graph, Matrix<double>& feromons) -> void;

    [[nodiscard]] auto GetPath() -> std::vector<int>&;
    auto CanMove(Graph& graph) -> bool;

private:
    int vertex_{-1};
    /// alpha_ - множитель привлекательости пути, beta_ - множитель феромона
    double alpha_{2}, beta_{1};
    std::vector<int> visitedVertices_;
    std::vector<int> possibleWays_;
};
#endif

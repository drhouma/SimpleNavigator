#ifndef S21_ANTS_COLONY_H
#define S21_ANTS_COLONY_H
#include <cmath>

#include "../s21_graph_algorithms.h"
#include "ant.h"
#include "common_funcs.h"

class AntsColony {
public:
    AntsColony() = delete;
    AntsColony(Graph& graph);

public:
    auto GenerateAnts(int allAnts) -> void;
    auto FindPaths() -> void;
    auto UpdateFeromon() -> void;
    auto UpdateResult(TspResult& res) -> void;

private:
    auto CalculatePathCost(std::vector<int>& path) -> int;

    double pheromonRemains_ = 0.75;

    Graph& graph_;
    Matrix<double> pheromons_;
    std::vector<Ant> ants_;
    int allVertex_{-1};
    int averageRouteLen_;
};

#endif

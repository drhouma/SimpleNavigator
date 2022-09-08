#include "./ants_colony/ants_colony.h"
#include "./s21_graph_algorithms.h"

auto GraphAlgorithms::solveTravelingSalesmanProblem(Graph& graph) -> TspResult {
    int antsNumber = graph.size();
    int CountWithoutUpgrade = 30, maxCount = 50;

    AntsColony colony(graph);
    TspResult prevRes, res;
    prevRes.distance = INFINITY;
    res.distance = INFINITY;

    while (CountWithoutUpgrade) {
        colony.GenerateAnts(antsNumber);
        colony.FindPaths();
        colony.UpdateFeromon();
        colony.UpdateResult(res);

        if (res.distance == prevRes.distance) {
            CountWithoutUpgrade--;
        } else {
            prevRes = res;
            CountWithoutUpgrade = maxCount;
        }
    }
    return res;
}
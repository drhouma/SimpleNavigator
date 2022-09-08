/**
 * @file    tests.cpp
 * @authors telvina<at>student.21-school.ru
 * @authors sreanna<at>student.21-school.ru
 * @authors jmadie<at>student.21-school.ru
 * @date    04/09/22
 */

#include <gtest/gtest.h>

#include "../algorithms/s21_graph_algorithms.h"

TEST(graph, test1) {
    Graph graph = Graph(10);
    ASSERT_THROW(graph.loadGraphFromFile("files/12345678.txt"), std::runtime_error);
}

TEST(bfsTest, test1) {
    Graph graph = Graph(10);
    graph.loadGraphFromFile("files/graph.txt");
    std::vector<int> expectedData = {3, 5, 1, 4, 2};
    ASSERT_EQ(expectedData, GraphAlgorithms::breadthFirstSearch(graph, 3));
}

TEST(bfsTest, test2) {
    Graph graph = Graph(10);
    graph.loadGraphFromFile("files/graph11.txt");
    std::vector<int> expectedData = {8, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11};
    ASSERT_EQ(expectedData, GraphAlgorithms::breadthFirstSearch(graph, 8));
}

TEST(bfsTest, test3) {
    Graph graph = Graph(10);
    graph.loadGraphFromFile("files/graph11.txt");
    ASSERT_THROW(GraphAlgorithms::breadthFirstSearch(graph, 12), std::invalid_argument);
}

TEST(bfsTest, test4) {
    Graph graph = Graph(10);
    graph.loadGraphFromFile("files/graph11.txt");
    ASSERT_THROW(GraphAlgorithms::breadthFirstSearch(graph, 0), std::invalid_argument);
}

TEST(dfsTest, test1) {
    Graph graph = Graph(10);
    graph.loadGraphFromFile("files/graph.txt");
    std::vector<int> expectedData = {3, 5, 1, 2, 4};
    ASSERT_EQ(expectedData, GraphAlgorithms::depthFirstSearch(graph, 3));
}

TEST(dfsTest, test2) {
    Graph graph = Graph(10);
    graph.loadGraphFromFile("files/graph11.txt");
    std::vector<int> expectedData = {8, 1, 2, 3, 4, 5, 6, 7, 9, 10, 11};
    ASSERT_EQ(expectedData, GraphAlgorithms::depthFirstSearch(graph, 8));
}

TEST(dfsTest, test3) {
    Graph graph = Graph(10);
    graph.loadGraphFromFile("files/graph11.txt");
    ASSERT_THROW(GraphAlgorithms::depthFirstSearch(graph, 12), std::invalid_argument);
}

TEST(dfsTest, test4) {
    Graph graph = Graph(10);
    graph.loadGraphFromFile("files/graph11.txt");
    ASSERT_THROW(GraphAlgorithms::depthFirstSearch(graph, 0), std::invalid_argument);
}

TEST(dijkstraTest, test1) {
    Graph graph = Graph(10);
    graph.loadGraphFromFile("files/graph.txt");
    ASSERT_EQ(0, GraphAlgorithms::getShortestPathBetweenVertices(graph, 3, 3));
}

TEST(dijkstraTest, test2) {
    Graph graph = Graph(10);
    graph.loadGraphFromFile("files/graph.txt");
    ASSERT_EQ(8, GraphAlgorithms::getShortestPathBetweenVertices(graph, 1, 5));
}

TEST(dijkstraTest, test3) {
    Graph graph = Graph(10);
    graph.loadGraphFromFile("files/graph.txt");
    ASSERT_THROW(GraphAlgorithms::getShortestPathBetweenVertices(graph, 0, 3), std::invalid_argument);
}

TEST(dijkstraTest, test4) {
    Graph graph = Graph(10);
    graph.loadGraphFromFile("files/graph11.txt");
    ASSERT_THROW(GraphAlgorithms::getShortestPathBetweenVertices(graph, 15, 12), std::invalid_argument);
}

TEST(floydTest, test1) {
    Graph graph = Graph(10);
    graph.loadGraphFromFile("files/graph1.txt");
    Matrix<int> result = GraphAlgorithms::getShortestPathsBetweenAllVertices(graph);

    ASSERT_EQ(0, result(0, 0));
    ASSERT_EQ(8, result(0, 1));
    ASSERT_EQ(3, result(0, 2));
    ASSERT_EQ(3, result(1, 0));
    ASSERT_EQ(0, result(1, 1));
    ASSERT_EQ(4, result(1, 2));
    ASSERT_EQ(4, result(2, 0));
    ASSERT_EQ(9, result(2, 1));
    ASSERT_EQ(0, result(2, 2));
}

TEST(TSP_ant, test1) {
    Graph graph{5};
    graph.loadGraphFromFile("files/tspGraphTest.txt");
    TspResult res = GraphAlgorithms::solveTravelingSalesmanProblem(graph);
    ASSERT_TRUE(res.distance <= 257);
}

TEST(TSP_ant, test2) {
    Graph graph{5};
    graph.loadGraphFromFile("files/tspGraph.txt");
    TspResult res = GraphAlgorithms::solveTravelingSalesmanProblem(graph);
    ASSERT_TRUE(res.distance <= 16);
}

TEST(TSP_ant, test3) {
    Graph graph{5};
    graph.loadGraphFromFile("files/1");
    TspResult res = GraphAlgorithms::solveTravelingSalesmanProblem(graph);
    ASSERT_TRUE(std::isinf(res.distance));
}

TEST(prim, test1) {
    Graph graph{10};
    graph.loadGraphFromFile("files/graph11.txt");
    auto result = GraphAlgorithms::getLeastSpanningTree(graph);
    int length{0};
    for (int i{0}; i < result.rows(); ++i) {
        for (int j{0}; j < result.cols(); ++j) {
            length += result(i, j);
        }
    }
    ASSERT_EQ(length, 150);
    ASSERT_EQ(result(0, 7), 12);
    ASSERT_EQ(result(0, 8), 4);
    ASSERT_EQ(result(1, 6), 72);
    ASSERT_EQ(result(2, 10), 13);
    ASSERT_EQ(result(3, 5), 12);
    ASSERT_EQ(result(4, 3), 4);
    ASSERT_EQ(result(5, 9), 3);
    ASSERT_EQ(result(7, 2), 9);
    ASSERT_EQ(result(7, 4), 9);
    ASSERT_EQ(result(10, 1), 12);
}

auto main(int argc, char **argv) -> int {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

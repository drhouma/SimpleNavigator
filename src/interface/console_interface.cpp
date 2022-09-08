/**
 * @file    console_interface.cpp
 * @authors telvina<at>student.21-school.ru
 * @authors sreanna<at>student.21-school.ru
 * @authors jmadie<at>student.21-school.ru
 * @date    04/09/22
 */

#include "console_interface.h"

#include <cstdlib>
#include <exception>
#include <iostream>

int ConsoleInterface::mainMenuItem() {
    std::cin.exceptions(std::ios_base::failbit);
    int action;
    std::cout << " __________________________________________________________\n"
              << "|                                                         |\n"
              << "|                     Сhoose action:                      |\n"
              << "|                                                         |\n"
              << "| 1. Load graph from file                                 |\n"
              << "| 2. Traversal in breadth                                 |\n"
              << "| 3. Traversal in depth                                   |\n"
              << "| 4. Shortest path between two vertices                   |\n"
              << "| 5. Shortest paths between all pairs of vertices         |\n"
              << "| 6. Minimal spanning tree                                |\n"
              << "| 7. Salesman problem                                     |\n"
              << "|                                                         |\n"
              << "| 0. Exit                                                 |\n"
              << "|_________________________________________________________|\n"
              << std::endl
              << ">>> ";

    std::cin >> action;

    return action;
}

auto ConsoleInterface::loadGraph() -> void {
    try {
        std::cout << "\nEnter file path:" << std::endl << ">>> ";
        std::string path;
        std::cin >> path;
        m_graph.loadGraphFromFile(path);
        m_isCorrectGraphLoad = true;
        std::cout << "\nDownload successful!\n";
        system("read REPLY");
        system("clear");
    } catch (std::exception &e) {
        printError(e.what());
    }
}

auto ConsoleInterface::viewBFS() -> void {
    try {
        std::cout << "\nEnter starting vertex\n"
                  << ">>> ";

        int vertex;
        std::cin >> vertex;
        printVector(GraphAlgorithms::breadthFirstSearch(m_graph, vertex));
    } catch (std::exception &e) {
        printError(e.what());
    }
}

auto ConsoleInterface::viewDFS() -> void {
    try {
        std::cout << "\nEnter starting vertex\n"
                  << ">>> ";

        int vertex;
        std::cin >> vertex;
        printVector(GraphAlgorithms::depthFirstSearch(m_graph, vertex));
    } catch (std::exception &e) {
        printError(e.what());
    }
}

auto ConsoleInterface::viewDijkstra() -> void {
    try {
        std::cout << "\nEnter starting vertex\n"
                  << ">>> ";

        int vertex1;
        std::cin >> vertex1;

        std::cout << "\nEnter ending vertex\n"
                  << ">>> ";

        int vertex2;
        std::cin >> vertex2;

        int path = GraphAlgorithms::getShortestPathBetweenVertices(m_graph, vertex1, vertex2);

        std::cout << "Shortest path between vertices: " << path << std::endl;
        system("read REPLY");
        system("clear");
    } catch (std::exception &e) {
        printError(e.what());
    }
}

auto ConsoleInterface::printVector(const std::vector<int> data) -> void {
    std::cout << std::endl;
    for (auto it = data.begin(); it != data.end(); ++it) {
        if (*it == data.back()) {
            std::cout << *it << std::endl;
            break;
        }

        std::cout << *it << "-> ";
    }

    system("read REPLY");
    system("clear");
}

auto ConsoleInterface::printError(const std::string error) -> void {
    std::cout << "\nError! " << error << std::endl;
    system("read REPLY");
    system("clear");
}

auto ConsoleInterface::viewFloydWarshall() -> void {
    std::cout << "\nShortest paths between all pairs of vertices:\n" << std::endl;
    GraphAlgorithms::getShortestPathsBetweenAllVertices(m_graph).print();
    system("read REPLY");
    system("clear");
}

auto ConsoleInterface::ViewTSPViaAntColony() -> void {
    try {
        TspResult res = GraphAlgorithms::solveTravelingSalesmanProblem(m_graph);
        std::cout << "\nShortest path with all vertices in:\n";
        for (auto elem : res.vertices) {
            std::cout << elem + 1 << ' ';
        }
        std::cout << "\n";
        std::cout << "Shortest path length: " << res.distance << '\n';
        system("read REPLY");
        system("clear");
    } catch (std::exception &e) {
        printError(e.what());
    }
}

auto ConsoleInterface::viewSpanningTree() -> void {
    std::cout << "\nLeast spanning tree:\n";
    GraphAlgorithms::getLeastSpanningTree(m_graph).print();
    system("read REPLY");
    system("clear");
}

void ConsoleInterface::viewMainMenu() {
    try {
        system("clear");

        while (true) {
            std::cin.exceptions(std::ios_base::failbit);
            int action = mainMenuItem();
            switch (action) {
                case 1:
                    loadGraph();
                    break;
                case 2:
                    checkLoad();
                    viewBFS();
                    break;
                case 3:
                    checkLoad();
                    viewDFS();
                    break;
                case 4:
                    checkLoad();
                    viewDijkstra();
                    break;
                case 5:
                    checkLoad();
                    viewFloydWarshall();
                    break;
                case 6:
                    checkLoad();
                    viewSpanningTree();
                    break;
                case 7:
                    checkLoad();
                    ViewTSPViaAntColony();
                    break;
                case 0:
                    system("clear");
                    exit(EXIT_SUCCESS);
                    break;
                default:
                    std::cout << "Choose the correct action" << std::endl;
                    system("read REPLY");
                    viewMainMenu();
                    break;
            }
        }

        system("clear");
    } catch (std::exception &e) {
        std::cout << "\n Check the correctness of the input" << std::endl;
        std::cin.clear();
        std::cin.ignore(10, '\n');
        system("read REPLY");
        viewMainMenu();
    }
}

auto ConsoleInterface::checkLoad() -> void {
    if (!m_isCorrectGraphLoad) {
        std::cout << "\nGraph not loaded\n";
        system("read REPLY");
        viewMainMenu();
    }
}

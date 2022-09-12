Проект реализовали:

https://github.com/sav1nbrave4code

https://github.com/drhouma

jmadie

### SimpleNavigator

Моя часть заключалась в реализации [муравьиного алгоритма](https://ru.wikipedia.org/wiki/%D0%9C%D1%83%D1%80%D0%B0%D0%B2%D1%8C%D0%B8%D0%BD%D1%8B%D0%B9_%D0%B0%D0%BB%D0%B3%D0%BE%D1%80%D0%B8%D1%82%D0%BC) для решения задачи [коммивояжера](https://ru.wikipedia.org/wiki/%D0%97%D0%B0%D0%B4%D0%B0%D1%87%D0%B0_%D0%BA%D0%BE%D0%BC%D0%BC%D0%B8%D0%B2%D0%BE%D1%8F%D0%B6%D1%91%D1%80%D0%B0) 

Также реализованы несколько алгоритмов поиска пути в графе __src/algorithms/*__ , и сама структура графа __src/graph/*__

Алгоритмы поиска пути:
  1. *Обход графа в глубину и в ширину* __src/algorithms/depth_first_search.cpp /src/algorithms/breadth_first_search.cpp__
  2. *Поиск кратчайших путей в графе* __src/algorithms/floyd_warshall_algorithm.cpp__
  3. *Поиск минимального остовного дерева* __src/algorithms/prim_algorithm.cpp__
  4. *Задача коммивояжера*  __src/algorithms/ants_colony/*__, __src/algorithms/travelling_salesman_problem.cpp__
  5. *Алгоритм дейкстры для поиска пути между двумя вершинами* __src/algorithms/dijkstra_algorithm.cpp__

Для удобства также был написан пользовательский интерфейс, для компиляции написан makefile (в src)

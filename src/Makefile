.PHONY: all, clean, tests, s21_graph_algorithms.a, run, clean_libs, clang, gcov_report
XX=g++
FLAGS= -Wall -Wextra -Werror -Wno-reorder -std=c++17
TEST_FLAGS= -lgtest -lgtest_main -lpthread
CFLAGS= -fprofile-arcs -ftest-coverage
FILES= graph/s21_graph.cpp \
	   algorithms/dijkstra_algorithm.cpp \
	   algorithms/depth_first_search.cpp \
	   algorithms/breadth_first_search.cpp \
	   algorithms/floyd_warshall_algorithm.cpp \
	   algorithms/prim_algorithm.cpp \
	   algorithms/travelling_salesman_problem.cpp \
	   algorithms/ants_colony/ant.cpp \
	   algorithms/ants_colony/ants_colony.cpp \
	   algorithms/ants_colony/common_funcs.cpp \

all: clean s21_graph_algorithms.a run

s21_graph_algorithms.a: clean_libs
	$(XX) -c $(FILES)
	ar rcs s21_graph_algorithms.a *.o
	ranlib $@
	cp $@ lib$@

run: clean
ifeq ($(OS), Linux)
	$(XX) $(FLAGS) main.cpp interface/console_interface.cpp libs21_graph_algorithms.a -o interface.o
else
	$(XX) $(FLAGS) main.cpp interface/console_interface.cpp s21_graph_algorithms.a -o interface.o
endif
	./interface.o

clean:
	rm -rf *.o *.out *.cfg *.gch *.dSYM *.gcda *.gcno *.info *.html .clang-format report

clean_libs:
	rm -rf *.a

clang:
	cp ../materials/linters/.clang-format .clang-format
	clang-format -n *.cpp */*.cpp */*.h */*.inl */*/*.cpp */*/*.h 

tests: clean
	$(XX) $(LDFLAGS) $(FLAGS) tests/tests.cpp $(FILES) -lstdc++ $(TEST_FLAGS) -o test.o
	./test.o

gcov_report: clean
	$(XX) $(FLAGS) $(CFLAGS) $(FILES) tests/tests.cpp -lstdc++ $(TEST_FLAGS) -o test.o
	./test.o
	lcov --no-external -c -d . -o tests.info
	genhtml tests.info -o report
ifeq ($(OS), Linux)
	xdg-open report/index.html
else
	open report/index.html
endif

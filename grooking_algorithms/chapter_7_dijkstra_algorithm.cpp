#include <iostream>
#include <chapter_7_dijkstra.h>

void example()
{
    Graph graph;
    graph.create_node("START", e_list({Edge("A", 6), Edge("B", 2)}));
    graph.create_node("A", e_list({Edge("FIN", 1)}));
    graph.create_node("B", e_list({Edge("A", 3), Edge("FIN", 5)}));
    graph.create_node("FIN", e_list({}));

    std::list<string> result;
    graph.shortest_path("START", "FIN", result);
    print(result);
}

int main()
{
    example();
    return 0;
}
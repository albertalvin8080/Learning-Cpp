#include <iostream>
// #include <chapter_7_dijkstra.h>
#include <chapter_7_dijkstra_v2.h>

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

void ex_7_1_A()
{
    Graph graph;
    graph.create_node("START", {Edge("TL", 5), Edge("BL", 2)});
    graph.create_node("TL", {Edge("TR", 4), Edge("BR", 2)});
    // graph.create_node("BL", {Edge("TL", 8), Edge("BR", 7)});
    /*
    This one below makes TL to be placed two times inside the min_heap 
        (TL:5 and then TL:4, which is smaller), but since we're using a `processed` 
        table, only TL:4 will be processed.
    If BL and TL had the same cost and from BL to TL costed 0, it would still be ok 
        since we're using `new_cost < costs[dst]` for adding or not inside the min_heap.
        Note that it's exactly for this reason that Dijkstra`s algorithm doesn't work for
        negative weighted graphs.
    */
    graph.create_node("BL", {Edge("TL", 2), Edge("BR", 7)});
    graph.create_node("TR", {Edge("FINISH", 3), Edge("BR", 6)});
    graph.create_node("BR", {Edge("FINISH", 1)});
    graph.create_node("FINISH", {});

    std::list<string> result;
    graph.shortest_path("START", "FINISH", result);
    print(result);
}

void ex_7_1_B()
{
    Graph graph;
    graph.create_node("START", {Edge("TL", 10)});
    graph.create_node("TL", {Edge("TR", 20)});
    graph.create_node("TR", {Edge("FINISH", 30), Edge("BOTTOM", 1)});
    graph.create_node("BOTTOM", {Edge("TL", 1)});
    graph.create_node("FINISH", {});

    std::list<string> result;
    graph.shortest_path("START", "FINISH", result);
    print(result);
}

void ex_7_1_C()
{
    Graph graph;
    graph.create_node("START", {Edge("TOP", 2), Edge("BL", 2)});
    graph.create_node("TOP", {Edge("FINISH", 2), Edge("BR", 2)});
    graph.create_node("BL", {Edge("TOP", 2)});
    // Dijkstra's algorithms only works for `directed asyclic weighted graphs`, so putting a negative weight here is just for exemplification.
    graph.create_node("BR", {Edge("BL", -1), Edge("FINISH", 2)});
    graph.create_node("FINISH", {});

    std::list<string> result;
    graph.shortest_path("START", "FINISH", result);
    print(result);
}

int main()
{
    // example();
    ex_7_1_A();
    // ex_7_1_B();
    // ex_7_1_C();
    return 0;
}
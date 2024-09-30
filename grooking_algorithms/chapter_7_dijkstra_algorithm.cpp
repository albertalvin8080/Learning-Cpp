#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <limits>

using string = std::string;
const int INFINITY = std::numeric_limits<int>::max();

template <class K, class V>
void print_map(const std::unordered_map<K, V> map)
{
    for (const auto &pair : map)
    {
        std::cout << "Key: " << pair.first << ", Value: " << pair.second << std::endl;
    }
}

class Edge
{
private:
    const string dst;
    int weight;

public:
    Edge() {}
    Edge(const string &dst, const int &weight) : dst(dst), weight(weight) {}

    bool operator>(const Edge &other) const
    {
        return weight > other.weight; // For a min-heap
    }

    friend class Node;
    friend class Graph;
};

using e_list = std::list<Edge>;
class Node
{
private:
    const string identifier;
    e_list neighbors;

public:
    Node() {}
    Node(const string &identifier) : identifier(identifier) {}
    Node(const string &identifier, const e_list &temp) : identifier(identifier), neighbors(temp) {}

    friend class Graph;
};

class Graph
{
private:
    std::unordered_map<string, Node> nodes_map;

public:
    Graph() {}
    void create_node(const string &identifier, const e_list &temp)
    {
        Node node(identifier, temp);
        nodes_map.emplace(identifier, node);
    }

    std::unordered_map<string, int> generate_costs_table(const string &src)
    {
        const Node node = nodes_map[src];
        std::unordered_map<string, int> costs;

        // places INFINITY for every node which is not directly reachable from `src`
        for (const auto &pair : nodes_map)
        {
            // pair.first = identifier
            // pair.second = node (unecessary)
            costs.emplace(pair.first, INFINITY);
        }

        for (const Edge &edge : node.neighbors)
        {
            costs[edge.dst] = edge.weight;
        }

        return costs;
    }

    void shortest_path(const string &src, const string &dst, std::list<string> &result)
    {
        std::unordered_map<string, string> parent;
        std::unordered_map<string, int> costs = generate_costs_table(src);
        std::unordered_set<string> processed;

        print_map(costs);

        // std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> pq;

        // while()
        // {

        // }
    }
};

void example()
{
    Graph graph;
    graph.create_node("START", e_list({Edge("A", 6), Edge("B", 2)}));
    graph.create_node("A", e_list({Edge("FIN", 1)}));
    graph.create_node("B", e_list({Edge("A", 3), Edge("FIN", 5)}));
    graph.create_node("FIN", e_list({}));

    std::list<string> result;
    graph.shortest_path("START", "FIN", result);
}

int main()
{
    example();
    return 0;
}
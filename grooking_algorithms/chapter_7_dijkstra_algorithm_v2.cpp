#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>
#include <limits>

using string = std::string;
const int INFINITY = std::numeric_limits<int>::max();

class Edge
{
private:
    string dst;
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
    string identifier;
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

    std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> generate_costs_table(const string &src)
    {
        const Node node = nodes_map[src];
        std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> costs;

        // places INFINITY for every node which is not directly reachable from `src`
        for (const auto &pair : nodes_map)
        {
            // pair.first = identifier
            // pair.second = node (unecessary)
            costs.emplace(Edge(pair.first, INFINITY));
        }

        // places the nodes which are directly reachable
        for (const Edge &edge : node.neighbors)
        {
            costs.push(Edge(edge.dst, edge.weight));
        }

        return costs;
    }

    void print_pqueue(std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> copy_pqueue)
    {
        while (!copy_pqueue.empty())
        {
            Edge edge = copy_pqueue.top();
            std::cout << "Edge: " << edge.dst << ", Weight: " << edge.weight << std::endl;
            copy_pqueue.pop();
        }
    }

    // UNFINISHED
    void shortest_path(const string &src, const string &dst, std::list<string> &result)
    {
        std::unordered_map<string, string> parent;
        std::priority_queue<Edge, std::vector<Edge>, std::greater<Edge>> costs = generate_costs_table(src);
        std::unordered_set<string> processed;

        print_pqueue(costs);

        while (!costs.empty())
        {
            const Edge& edge = costs.top();
            const int& cost = edge.weight;
            const string& identifier = edge.dst;
            costs.pop();
            // Continues if the current_node has already been processed or scheduled for processing
            if(processed.find(identifier) != processed.end()) continue;

            const Node& node = nodes_map[identifier];
            for(const Edge& edge : node.neighbors)
            {
                const int new_cost = cost + edge.weight;
            }
            processed.emplace(node);
            costs.emplace();
        }
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
#ifndef __DIJKSTRA_H_
#define __DIJKSTRA_H_

#include <iostream>
#include <list>
#include <queue>
#include <limits>
#include <unordered_map>
#include <unordered_set>

using string = std::string;
const int &INFINITY = std::numeric_limits<int>::max();

void print(std::list<string> to_print)
{
    // for (const string &str : to_print)
    //     std::cout << str << "->";
    // std::cout << std::endl;

    auto it = to_print.begin();
    while (true)
    {
        std::cout << *it;
        ++it;
        if (it == to_print.end())
            break;
        std::cout << " -> ";
    }
    std::cout << std::endl;
}

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

    std::unordered_map<string, int> generate_costs_table(const string &src)
    {
        std::unordered_map<string, int> costs;

        // PREVIOUSLY: places INFINITY for every node which is not directly reachable from `src`.
        // *NOW*: places INFINITY for every node.
        for (const auto &pair : nodes_map)
        {
            // pair.first = identifier
            // pair.second = node (unecessary)
            costs.emplace(pair.first, INFINITY);
        }

        /*
        This part becomes unecessary since it will be automatically created in 
        the first iteration of the while() inside shortest_path().
        */
        // const Node& node = nodes_map[src];
        // for (const Edge &edge : node.neighbors)
        // {
        //     costs[edge.dst] = edge.weight;
        // }

        return costs;
    }

    // O(n logn)
    void shortest_path(const string &src, const string &dst, std::list<string> &result)
    {
        std::unordered_map<string, string> parent;
        std::unordered_map<string, int> costs = generate_costs_table(src);
        std::unordered_set<string> processed;

        print_map(costs);

        std::priority_queue<
            std::pair<int, string>,
            std::vector<std::pair<int, string>>,
            std::greater<std::pair<int, string>>>
            min_heap;

        min_heap.emplace(0, src);
        costs[src] = 0; // The cost for src needs to be 0 because it will be added to its neighbors in the first iteration of the while().

        while (!min_heap.empty())
        {
            auto [current_cost, node_identifier] = min_heap.top();
            min_heap.pop();

            // Node already processed
            if (processed.find(node_identifier) != processed.end())
                continue;
            else // Being processed now
                processed.emplace(node_identifier);

            // Stop early if we reached our destination (not a good idea)
            // if (node_identifier == dst)
            //     break;

            const Node &node = nodes_map[node_identifier];
            for (const Edge &edge : node.neighbors)
            {
                const string &dst = edge.dst;
                const int &new_cost = current_cost + edge.weight;
                if (new_cost < costs[dst])
                {
                    costs[dst] = new_cost;
                    parent[dst] = node_identifier;
                    min_heap.emplace(new_cost, dst);
                }
            }
        }

        string current = dst;
        while (current != src)
        {
            result.push_front(current + "(" + std::to_string(costs[current]) + ")");
            current = parent[current];
        }
        result.push_front(src);
    }
};

#endif
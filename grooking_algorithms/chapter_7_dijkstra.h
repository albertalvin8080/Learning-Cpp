#ifndef __DIJKSTRA_H_
#define __DIJKSTRA_H_

#include <iostream>
#include <list>
#include <queue>
#include <limits>
#include <unordered_map>
#include <unordered_set>

using string = std::string;
const int& INFINITY = std::numeric_limits<int>::max();

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

    string get_lowest_cost_identifier(
        const std::unordered_map<string, int> &costs,
        const std::unordered_set<string> &processed)
    {
        string identifier = "";
        int lowest_cost = INFINITY;

        for(const auto& pair : costs)
        {
            // pair.second == `weight`
            // pair.first == `dst` node
            if(pair.second < lowest_cost && processed.find(pair.first) == processed.end())
            {
                identifier = pair.first;
                lowest_cost = pair.second;
            }
        }

        return identifier;
    }

    void shortest_path(const string &src, const string &dst, std::list<string> &result)
    {
        std::unordered_map<string, string> parent;
        std::unordered_map<string, int> costs = generate_costs_table(src);
        std::unordered_set<string> processed;

        print_map(costs);

        string node_identifier = get_lowest_cost_identifier(costs, processed);
        parent[node_identifier] = src;
        
        while (!node_identifier.empty())
        {
            const int& cost = costs[node_identifier];
            const Node& node = nodes_map[node_identifier];
            for(const Edge& edge : node.neighbors)
            {
                const string& dst = edge.dst;
                const int new_cost = cost + edge.weight;
                // If the cost previously stored for reaching the node `dst` is greater than the new_cost
                if(costs[dst] > new_cost)
                {
                    costs[dst] = new_cost;
                    parent[dst] = node.identifier;
                }
            }
            processed.emplace(node_identifier);
            node_identifier = get_lowest_cost_identifier(costs, processed);
        }

        string current = dst;
        while(current != src)
        {
            result.push_front(current + "(" + std::to_string(costs[current]) + ")");
            current = parent[current];
        }
        result.push_front(src);
    }
};

#endif
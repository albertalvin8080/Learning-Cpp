#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <queue>

class Node
{
public:
    const std::string identifier;
    std::list<std::string> neighboors;
    Node(const std::string &identifier, const std::list<std::string> &neighboors) : identifier(identifier), neighboors(neighboors)
    {
    }
};

class Graph
{
private:
    std::unordered_map<std::string, Node> nodes_map;

public:
    void create_node(const std::string &identifier, const std::list<std::string> &neighboors)
    {
        Node node(identifier, neighboors);
        nodes_map.emplace(identifier, node);
    }

    std::list<std::string> breadth_first_search(
        const std::string &src_identifier,
        const std::string &target_identifier,
        std::list<std::string> &result)
    {
        const Node src_node = nodes_map[src_identifier];
        std::queue<Node> to_visit;
        to_visit.push(src_node);

        std::unordered_map<std::string, std::string> visited;
        visited[src_identifier] = ""; // mark the src node as visited

        while (!to_visit.empty())
        {
            Node front = to_visit.front();
            to_visit.pop();
            for (const std::string &neighboor_name : front.neighboors)
            {
                const Node node = nodes_map[neighboor_name];
                // found the path to the target
                if (node.identifier == target_identifier)
                {
                    std::string current = target_identifier;
                    while (current != src_identifier)
                    {
                        result.push_front(current);
                        current = visited[current];
                    }
                    // push_front will create a reverse list in the end of everything (from src to target).
                    result.push_front(src_identifier); // Add src at the front.
                    return result;
                }
                // checks if the node has already been visited or maked to be visited.
                auto it = visited.find(node.identifier);
                if (it == visited.end())
                {
                    to_visit.push(node);
                    // this line basically says: we reach `node` from `front`.
                    visited.emplace(node.identifier, front.identifier);
                }
            }
        }

        return result; // returns the same list if the path hasn't been found.
    }
};

int main()
{
    Graph graph;
    graph.create_node("YOU", std::list<std::string>({"BOB", "ALICE", "CLAIRE"}));
    graph.create_node("BOB", std::list<std::string>({"ANUJ", "PEGGY"}));

    std::list<std::string> result;

    return 0;
}
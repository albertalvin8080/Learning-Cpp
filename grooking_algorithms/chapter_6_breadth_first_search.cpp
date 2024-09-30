#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>

using string = std::string;

class Node
{
public:
    const string identifier;
    std::list<string> neighboors;
    Node(const string &identifier, const std::list<string> &neighboors) : identifier(identifier), neighboors(neighboors) {}
    Node() {} // needed because unordered_map uses it for the operator[]
};

class Graph
{
private:
    std::unordered_map<string, Node> nodes_map;

public:
    void create_node(const string &identifier, const std::list<string> &neighboors)
    {
        Node node(identifier, neighboors);
        nodes_map.emplace(identifier, node);
    }

    void breadth_first_search(
        const string &src_identifier,
        const string &target_identifier,
        std::list<string> &result)
    {
        const Node src_node = nodes_map[src_identifier];
        std::queue<Node> to_visit;
        to_visit.push(src_node);

        std::unordered_map<string, string> visited;
        visited[src_identifier] = ""; // mark the src node as visited

        while (!to_visit.empty())
        {
            Node front = to_visit.front();
            to_visit.pop();
            for (const string &neighboor_name : front.neighboors)
            {
                const Node node = nodes_map[neighboor_name];
                // checks if the node has already been visited or maked to be visited.
                auto it = visited.find(node.identifier);
                if (it == visited.end())
                {
                    to_visit.push(node);
                    // this line basically says: we reach `node` from `front`.
                    visited.emplace(node.identifier, front.identifier);
                }

                // found the path to the target.
                // this needs to be placed after inserting into the visited<> map.
                if (node.identifier == target_identifier)
                {
                    string current = target_identifier;
                    while (current != src_identifier)
                    {
                        result.push_front(current);
                        current = visited[current];
                    }
                    // push_front will create a reverse list in the end of everything (from src to target).
                    result.push_front(src_identifier); // Add src at the front.
                    return;
                }
            }
        }
        // does nothing with std::list<string> result
    }
};

int main()
{
    Graph graph;
    graph.create_node("YOU", std::list<string>({"BOB", "ALICE", "CLAIRE"}));
    graph.create_node("BOB", std::list<string>({"ANUJ", "PEGGY"}));
    graph.create_node("ALICE", std::list<string>({"PEGGY"}));
    graph.create_node("ANUJ", std::list<string>());
    graph.create_node("PEGGY", std::list<string>());
    graph.create_node("CLAIRE", std::list<string>({"THOM", "JONNY"}));
    graph.create_node("THOM", std::list<string>());
    graph.create_node("JONNY", std::list<string>());

    std::list<string> result;
    // graph.breadth_first_search("YOU", "ALICE", result);
    // graph.breadth_first_search("YOU", "THOM", result);
    graph.breadth_first_search("YOU", "ANUJ", result);

    for (const string &str : result)
        std::cout << str << std::endl;

    return 0;
}
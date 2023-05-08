#include <vector>
#include "Node.h"
#include "Head.h"

class Cluster
{
private:
    Head head;
    std::vector<Node> nodes;

public:
    Cluster(Head head)
    {
        this->head = head;
    }

    Head getHead()
    {
        return head;
    }

    void setHead(Head head)
    {
        this->head = head;
    }

    std::vector<Node> getNodes()
    {
        return nodes;
    }

    void addNode(Node node)
    {
        nodes.push_back(node);
    }

    void removeNode(Node node)
    {
        for (int i = 0; i < nodes.size(); i++)
        {
            if (nodes[i].getId() == node.getId())
            {
                nodes.erase(nodes.begin() + i);
                break;
            }
        }
    }

    bool operator==(Cluster other) const
    {
        return head == other.head && nodes == other.nodes;
    }
};

// Define the fitness function
double fitness(vector<Cluster> clusters)
{
    double fitness = 0.0;

    // Objective 1: Minimize distance between cluster heads and nodes
    double obj1 = 0.0;
    for (Cluster c : clusters)
    {
        for (Node n : c.getNodes())
        {
            obj1 += distance(c.getHead(), n);
        }
    }
    fitness += 0.4 * obj1;

    // Objective 2: Maximize the number of nodes in each cluster
    double obj2 = 0.0;
    for (Cluster c : clusters)
    {
        obj2 += c.getNodes().size();
    }
    fitness += 0.3 * obj2;

    // Objective 3: Maximize the fault tolerance of cluster heads
    double obj3 = 0.0;
    for (Cluster c : clusters)
    {
        obj3 += c.getHead().getFaultTolerance();
    }
    fitness += 0.3 * obj3;

    return fitness;
}

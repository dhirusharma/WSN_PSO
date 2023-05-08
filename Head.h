#include "Node.h"

class Head : public Node
{
private:
    int clusterId;

public:
    Head(int id, double x, double y, int clusterId) : Node(id, x, y)
    {
        this->clusterId = clusterId;
    }

    int getClusterId()
    {
        return clusterId;
    }

    void setClusterId(int clusterId)
    {
        this->clusterId = clusterId;
    }

    bool operator==(Head other) const
    {
        return Node::operator==(other) && clusterId == other.clusterId;
    }
};

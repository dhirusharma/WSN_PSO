class Node
{
private:
    int id;
    double x;
    double y;

public:
    Node(int id, double x, double y)
    {
        this->id = id;
        this->x = x;
        this->y = y;
    }

    int getId()
    {
        return id;
    }

    double getX()
    {
        return x;
    }

    double getY()
    {
        return y;
    }

    bool operator==(Node other) const
    {
        return id == other.id && x == other.x && y == other.y;
    }
};

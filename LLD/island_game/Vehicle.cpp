class Connection
{
public:
    virtual int getStartIsland() = 0;

    virtual int getEndIsland() = 0;

    virtual bool canTraverse() = 0;
};

class RoadwayConnection : Connection
{
public:
    int getStartIsland()
    {
    }

    int getEndIsland()
    {
    }

    bool canTraverse()
    {
    }
};

class WaterwayConnection : Connection
{
public:
    int getStartIsland()
    {
    }

    int getEndIsland()
    {
    }

    bool canTraverse()
    {
    }
};

class Vehicle
{
public:
    virtual void traverse(Connection connection) = 0;
};

class Car : Vehicle
{
private:
    int weight;

public:
    Car(int _weight)
    {
        weight = _weight;
    }

    void traverse(Connection connection)
    {
    }
};
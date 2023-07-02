class Connection
{
public:
    virtual int getStartIsland() = 0;

    virtual int getEndIsland() = 0;

    virtual bool canTraverse() = 0;
};
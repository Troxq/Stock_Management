#include <iostream>

using namespace std;

class base
{
    public:
    void fm()
    {
        cout << "Base fm" << endl;
    }
};

class deriver:public base
{
    public:
    void fm()
    {
        cout << "deriver fm" << endl;
    }
};

int main()
{
    base *pb;
    deriver obj, *pd;

    pb = &obj;
    pd = &obj;

    pb->fm();
    pb->base::fm();
    //pb->deriver::fm();

    pd->fm();
    pd->base::fm();
    pd->deriver::fm();
}
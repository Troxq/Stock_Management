#include <unistd.h>
// #include "OrderFormatHEADLL.h"
using namespace std;
// class 

class sendOrderFormatManager : public OrderFormatHEADLL
{
private:
    int numberContainer;

public:
    sendOrderFormatManager(int);
    // display();
};

sendOrderFormatManager::sendOrderFormatManager(int numC) : OrderFormatHEADLL()
{
    numberContainer = numC;   
}
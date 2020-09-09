#include "PubSubProxy.hpp"

int main()
{
    PubSubProxy proxy;
    proxy.registerSigHandler();
    proxy.start();
    proxy.maintainProxy();
    return 1;
}

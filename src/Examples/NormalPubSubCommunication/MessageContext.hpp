#include "iostream"
#include "string"

#include "zmq.hpp"

using namespace std;

class MessageContext
{
    zmq::context_t context;

    public:
        static MessageContext& getStaticMessageContext();
        //TODO: object creation and return of singleton object.
}

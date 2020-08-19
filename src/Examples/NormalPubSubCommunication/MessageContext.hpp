#include "iostream"
#include "string"

#include "zmq.hpp"

using namespace std;

class MessageContext
{
    zmq::context_t * context;
    void createMessageContext();

    public:
        MessageContext();
        zmq::context_t & getStaticMessageContext();


        ~MessageContext() {
            delete context;
        }
};

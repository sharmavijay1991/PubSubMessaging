#include "MessageContext.hpp"

MessageContext::MessageContext()
{
    context = nullptr;
}

void MessageContext::createMessageContext()
{
    context = new zmq::context_t(1);
}

zmq::context_t & MessageContext::getStaticMessageContext()
{
    if(context == nullptr) {
        cout<<"Debug: null context, creating new"<<endl;
        createMessageContext();
    }
    else
        cout<<"Debug: Using already created context"<<endl;
    return *context;
}

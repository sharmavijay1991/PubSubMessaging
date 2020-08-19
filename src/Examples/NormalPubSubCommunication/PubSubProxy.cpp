#include <PubSubProxy.hpp>

PubSubProxy::stop = 0;

PubSubProxy::PubSubProxy() {
    stop = 0;
    //MessageContext & context = MessageContext::getStaticMessageContext();
    loadAddress();
}

void PubSubProxy::registerSigHandler()
{
    signal(SIGIO, PubSubProxy::sigHandler);
}

static void PubSubProxy::sigHandler(int signal)
{
    stop = 1;
}

void PubSubProxy::loadDefaultAddresses()
{
    pub_bind_address = "*.5580";
    sub_bind_address = "*.5581";
    pub_connect_address = "localhost:5581";
    sub_connect_address = "localhost:5580";
}

void PubSubProxy::loadAddress() {
    loadDefaultAddresses();
    string conn_string;
    cout<<"Pub Bind Address ["<<pub_bind_address<<"] :";
    cin>>conn_string;
    if(!conn_string.empty()) {
        pub_bind_address = conn_string;
        conn_string = "";
    }
    cout<<"Sub Bind Address ["<<sub_bind_address<<"] :";
    cin>>conn_string;
    if(!conn_string.empty()) {
        sub_bind_address = conn_string;
        conn_string = "";
    }
    cout<<"Pub Connect Address ["<<pub_connect_address<<"] :";
    cin>>conn_string;
    if(!conn_string.empty()) {
        pub_connect_address = conn_string;
        conn_string = "";
    }
    cout<<"Sub Connect Address ["<<sub_connect_address<<"] :";
    cin>>conn_string;
    if(!conn_string.empty()) {
        sub_connect_address = conn_string;
        conn_string = "";
    }
}

bool PubSubProxy::start()
{
    proxy_thread.reset(new thread(PubSubProxy::runZMQProxy(), this));
}

bool PubSubProxy::runZMQProxy()
{
    zmq::context_t & context = msg_context.getStaticMessageContext();
    zmq::socket_t pub(context.getZMQContext(), ZMQ_XPUB);
    pub.bind(pub_bind_address);
    zmq::socket_t sub(context.getZMQContext(), ZMQ_XSUB);
    sub.bind(sub_bind_address);
    zmq::socket_t controller(context.getZMQContext(), ZMQ_SUB);
    controller.connect(control_path);
    controller..setsockopt( ZMQ_SUBSCRIBE, "", 0 );
    zmq::proxy_steerable(pub, sub, NULL, controller);       //blocking call
    return true;

}

void PubSubProxy::maintainProxy()
{
    while(true) {
        if(stop == 1) {
            break;
        }
    }
}

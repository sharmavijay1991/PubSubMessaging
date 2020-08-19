#include <iostream>
#include <thread>
#include <string>
#include <zmq.hpp>
#include <csignal>

//Own header files
#include <MessageContext.hpp>

using namespace std;

class PubSubProxy
{
    static bool stop;
    string pub_bind_address, sub_bind_address, pub_connect_address, sub_connect_address;
    string control_path = "inproc://pubsubproxycontrol";
    unique_ptr<thread> proxy_thread;
    MessageContext msg_context;

    void loadDefaultAddresses();
    void loadAddress();
    static void sigHandler(int signal);

    public:
        PubSubProxy();
        void registerSigHandler();
        bool start();
        bool runZMQProxy();
        bool maintainProxy();

        //TODO:
        //Function: Shutdown with join on thread

};

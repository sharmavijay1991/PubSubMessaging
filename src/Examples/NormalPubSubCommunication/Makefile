all: MessageContext PubSubProxy

MessageContext: MessageContext.cpp
	g++ MessageContext.cpp -c -I  /usr/local/Cellar/zeromq/4.3.2/include/ -I ./ -I /Users/vijaysh3/Vijay/Code/PubSubMessaging/PubSubMessaging/include_binding/cppzmq/ -std=c++11

PubSubProxy: PubSubProxy.cpp
	g++ PubSubProxy.cpp -c -I  /usr/local/Cellar/zeromq/4.3.2/include/ -I ./ -I /Users/vijaysh3/Vijay/Code/PubSubMessaging/PubSubMessaging/include_binding/cppzmq/ -std=c++11

clean:
	rm -f MessageContext.o PubSubProxy.o

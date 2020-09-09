all: MessageContext PubSubProxy ProxyMain

MessageContext: MessageContext.cpp
	g++ MessageContext.cpp -c -I  /usr/local/Cellar/zeromq/4.3.2/include/ -I ./ -I /Users/vijaysh3/Vijay/Code/PubSubMessaging/PubSubMessaging/include_binding/cppzmq/ -std=c++11

PubSubProxy: PubSubProxy.cpp
	g++ PubSubProxy.cpp -c -I  /usr/local/Cellar/zeromq/4.3.2/include/ -I ./ -I /Users/vijaysh3/Vijay/Code/PubSubMessaging/PubSubMessaging/include_binding/cppzmq/ -std=c++11

Main: ProxyMain.cpp
	g++ ProxyMain.cpp PubSubProxy.cpp MessageContext.cpp -I  /usr/local/Cellar/zeromq/4.3.2/include/ -I ./ -I /Users/vijaysh3/Vijay/Code/PubSubMessaging/PubSubMessaging/include_binding/cppzmq/ -std=c++11 -o PSProxy -L /usr/local/Cellar/zeromq/4.3.2/lib/ -lzmq

clean:
	rm -f MessageContext.o PubSubProxy.o

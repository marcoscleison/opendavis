#ifndef __HTTP_SRV_H__
#define __HTTP_SRV_H__
#include<iostream>
#include<string>
#include<event2/event.h>
#include<event2/http.h>
#include<event2/buffer.h>
#include<event2/util.h>
#include<memory>



void HttpGlobalCallBack(struct evhttp_request *, void *);
class Router;

class HttpServer{
public:
    HttpServer(std::string host, int port):host(host),port(port), router(new Router()){
        this->init();
    }
    
    void init();
    
    void Listen();
    void Close();
    
    void handler(struct evhttp_request *, void *);
private:
    int port;
    std::string host;
    
    event_base* ebase;
    evhttp* server;
    std::shared_ptr<Router*> router;
    
};

class Router{
public:
    Router(){}
    
    void handler(struct evhttp_request *, void *);
    
};


#endif
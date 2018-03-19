#include"httpsrv.h"
#include<event2/event.h>
#include<event2/http.h>
#include<event2/buffer.h>
#include<event2/util.h>


void HttpGlobalCallBack(struct evhttp_request* request, void* srv) {
    
    HttpServer* server = static_cast<HttpServer*>(srv);
    
    if(server!=nullptr){
        server->handler(request,srv);
    }

}

void HttpServer::init() {
    this->ebase = event_base_new();
    this->server = evhttp_new(this->ebase);
    evhttp_set_allowed_methods(this->server, EVHTTP_REQ_GET | EVHTTP_REQ_POST | EVHTTP_REQ_CONNECT | EVHTTP_REQ_HEAD | EVHTTP_REQ_OPTIONS | EVHTTP_REQ_PUT | EVHTTP_REQ_TRACE | EVHTTP_REQ_DELETE | EVHTTP_REQ_PATCH);
    evhttp_set_gencb(this->server, HttpGlobalCallBack, this);
    
    

}

void HttpServer::Listen() {
    if (evhttp_bind_socket(this->server, this->host.c_str(), this->port) != 0) {
        
       std::cerr << "Cannot open connection at " << this->host << ":" << this->port;
     
        
        return;
    }
    event_base_dispatch(this->ebase);

}

void HttpServer::Close() {
    evhttp_free(this->server);
    event_base_free(this->ebase);
}

void HttpServer::handler(evhttp_request* request, void* srv){

}



void Router::handler(evhttp_request* request, void* srv){

}
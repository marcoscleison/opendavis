#include"opendavis/ui/dom.hpp"
using namespace opendavis::ui;

Node::Node(){}
Node::~Node() = default;

void Node::render(){
    
    for(auto& node:this->_children){
        if(node->visible()){
            node->render();
        }
    }
}
bool Node::visible() const {
    return this->_visible;
}




Dom::Dom(){

}
Dom::~Dom() = default;

void Dom::render(){
    for(auto& node:this->nodes){
        if(node->visible()){
            node->render();
        }
    }

}
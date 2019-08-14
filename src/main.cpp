#include<memory>
#include"opendavis/opendavis.hpp"
using namespace opendavis::ui;
int main(){
    Application app;
    Dom::Ptr doc = std::make_shared<Dom>();
    app.addDom(doc);
    app.run();
    return 0;

}
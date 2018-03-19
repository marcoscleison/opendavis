#include<iostream>
#include"httpsrv.h"
using namespace std;

int main(){
    cout<< "OpenDavis Server v."<<endl;
    cout<< "(c)2018 Marcos Cleison Silva Santana"<<endl;
    
    HttpServer srv("127.0.0.1",8081);
    

    return 0;
}
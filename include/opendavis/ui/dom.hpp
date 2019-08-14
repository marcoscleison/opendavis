#pragma once
#include<memory>
namespace opendavis{
    namespace ui{

        class Node{
            public:
            Node();
            virtual ~Node();
        };

        class Dom{
            public:
            using Ptr = std::shared_ptr<Dom>; 
            Dom();
            virtual ~Dom();
        };

    }
}
#pragma once
#include<memory>
#include<vector>
namespace opendavis{
    namespace ui{

        class Node{
            public:
            using Ptr = std::shared_ptr<Node>; 
            Node();
            virtual ~Node();
            virtual void render();
            bool visible() const;
            private:
            bool _visible = true;
            std::vector<Node::Ptr> _children;
        };

        class Dom{
            public:
            using Ptr = std::shared_ptr<Dom>; 
            Dom();
            void render();
            virtual ~Dom();
            private:
            std::vector<Node::Ptr> nodes;
           
        };

    }
}
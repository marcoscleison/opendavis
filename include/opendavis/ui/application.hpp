#pragma once
#include<memory>
#include<vector>
// #include<experimental/propagate_const>
#include"opendavis/ui/dom.hpp"

namespace opendavis{
    namespace ui{
        class Application{
            public:
            Application();
            ~Application();
            Application(Application&&);
            Application& operator=(Application&&);
            void addDom(Dom::Ptr dom);
            void run();

            private:

            class impl;
            std::unique_ptr<impl> pimpl;
            std::vector<Dom::Ptr> docs;
        };
    }
}
#pragma once
#include<memory>
#include<experimental/propagate_const>
namespace opendavis{
    namespace ui{
        class Application{
            public:
            Application();
            ~Application();
            Application(Application&&);
            Application& operator=(Application&&);

            void run();

            private:

            class impl;
            std::experimental::propagate_const<std::unique_ptr<impl>> pimpl;
        };
    }
}
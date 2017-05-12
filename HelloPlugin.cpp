//
// Created by yannick lamprecht on 05.05.17.
//


#include <iostream>
#include <boost/limits.hpp>
#include <boost/shared_ptr.hpp>
#include "IPlugin.h"


namespace pl {
    class HelloPlugin : public IPlugin {

    public:
        void onEnable() override {
            std::cout << "Hello Mister" << std::endl;

        }

        void onDisable() override {
            std::cout << "Goodbye Mister" << std::endl;
        }

        std::string getName() override {
            return "HelloPlugin";
        }
    };


    extern "C" BOOST_SYMBOL_EXPORT HelloPlugin plugin;
    HelloPlugin plugin;

}

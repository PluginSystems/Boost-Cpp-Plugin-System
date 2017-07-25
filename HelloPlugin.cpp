//
// Created by yannick lamprecht on 05.05.17.
//


#include <iostream>
#include <boost/limits.hpp>
#include <boost/shared_ptr.hpp>
#include "IPlugin.h"
#include "StringFace.h"


namespace pl {
    class HelloPlugin : public IPlugin, public StringFace{

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

        void printMessage(std::string message) override {
            std::cout << getName() << " saying " << message << std::endl;
        }

        std::string modifyMessage(std::string message) override {
            return getName() + " returning "+ message;
        }


    };



    extern "C" BOOST_SYMBOL_EXPORT HelloPlugin plugin;

    HelloPlugin plugin;
}

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

        }

        void onDisable() override {
        }

        std::string getName() override {
            return "HelloPlugin";
        }


        void test()override {}



    };



    extern "C" BOOST_SYMBOL_EXPORT HelloPlugin plugin;

    HelloPlugin plugin;
}

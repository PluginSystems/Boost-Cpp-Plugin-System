//
// Created by yannick lamprecht on 22.07.17.
//

#include <iostream>
#include <boost/dll/alias.hpp>
#include "IPlugin.h"

namespace ysl {
    class SecondPlugin : IPlugin {

    public:
        void onEnable() override {
            std::cout << "Hello " << getName() << std::endl;

        }

        void onDisable() override {
            std::cout << "Goodbye " << getName() << std::endl;
        }

        std::string getName() override {
            return "SecondPlugin";
        }

    };

    extern "C" BOOST_SYMBOL_EXPORT ysl::SecondPlugin plugin;
    SecondPlugin plugin;
}


//
// Created by yannick lamprecht on 24.07.17.
//

#ifndef CPPBOOSTPLUGINSYSTEM_CONTEXTSWITCHRETURNTYPEBENCHMARK_H
#define CPPBOOSTPLUGINSYSTEM_CONTEXTSWITCHRETURNTYPEBENCHMARK_H

#include <iostream>
#include "../TestCase.h"
#include "../../PluginLoader.h"
#include "../../StringFace.h"

class ContextSwitchReturnTypeBenchmark : public TestCase {
public:
    ContextSwitchReturnTypeBenchmark(ysl::PluginLoader &pluginLoader) : TestCase(pluginLoader) {}

    void setUp() override {
        loader.load();
        loader.enable();
    }

    void tearDown() override {
        loader.disable();
        loader.unload();
    }

protected:

    void runTest(unsigned long cycle) override {

        startTimer();

        boost::shared_ptr<IPlugin> plugin = loader.getPlugin("HelloPlugin");

        if(boost::shared_ptr<StringFace> face = boost::dynamic_pointer_cast<StringFace>(plugin)){
            std::cout << face->modifyMessage(getName()) << std::endl;
        }




        stopTimer();
        defineBenchmarkPoint(cycle, getName()+"_"+std::to_string(cycle+1));
        resetTimer();

    }

public:
    std::string getName() override {
        return "ContextSwitchReturnTypeBenchmark";
    }

};


#endif //CPPBOOSTPLUGINSYSTEM_CONTEXTSWITCHRETURNTYPEBENCHMARK_H

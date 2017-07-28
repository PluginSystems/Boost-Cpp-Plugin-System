//
// Created by yannick lamprecht on 24.07.17.
//

#ifndef CPPBOOSTPLUGINSYSTEM_CONTEXTSWITCHBENCHMARK_H
#define CPPBOOSTPLUGINSYSTEM_CONTEXTSWITCHBENCHMARK_H


#include "../TestCase.h"
#include "../../PluginLoader.h"
#include "../../StringFace.h"

class ContextSwitchBenchmark : public TestCase {
private:

    boost::shared_ptr<StringFace> _face;

public:
    ContextSwitchBenchmark(ysl::PluginLoader &pluginLoader) : TestCase(pluginLoader) {}

    void setUp() override {
        loader.load();
        loader.enable();
        boost::shared_ptr<IPlugin> plugin = loader.getPlugin("HelloPlugin");
        _face = boost::dynamic_pointer_cast<StringFace>(plugin);
    }

    void tearDown() override {
        loader.disable();
        loader.unload();
    }

protected:

    void runTest(unsigned long cycle) override {


        startTimer();

        if(_face!= nullptr){
            _face->test();
        }


        stopTimer();
        defineBenchmarkPoint(cycle, getName()+"_"+std::to_string(cycle+1));
        resetTimer();

    }

public:
    std::string getName() override {
        return "ContextSwitchBenchmark";
    }

};


#endif //CPPBOOSTPLUGINSYSTEM_CONTEXTSWITCHBENCHMARK_H

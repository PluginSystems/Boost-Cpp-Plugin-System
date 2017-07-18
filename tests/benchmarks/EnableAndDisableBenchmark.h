//
// Created by yannick lamprecht on 10.07.17.
//

#include "../TestCase.h"
#include "../../PluginLoader.h"

#ifndef QTPLUGINTEST_ENABLEDISABLETEST_H
#define QTPLUGINTEST_ENABLEDISABLETEST_H

#endif //QTPLUGINTEST_ENABLEDISABLETEST_H


class EnableAndDisableBenchmark : public TestCase{


public:

    EnableAndDisableBenchmark(ysl::PluginLoader& pluginLoader) : TestCase(pluginLoader) {

    }

    void setUp() override {
        loader.load();
    }

    void tearDown() override {
        loader.unload();
    }

protected:

    void runTest(unsigned long cycle) override {

        startTimer();

        loader.enable();

        loader.disable();

        stopTimer();
        defineBenchmarkPoint(cycle, getName()+"_"+std::to_string(cycle+1));
        resetTimer();

    }

    std::string getName() override {
        return "EnableAndDisableBenchmark";
    }
};
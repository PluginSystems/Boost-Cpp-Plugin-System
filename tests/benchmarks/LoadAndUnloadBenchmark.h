//
// Created by yannick lamprecht on 10.07.17.
//

#include <iostream>
#include "../TestCase.h"
#include "../../PluginLoader.h"

#ifndef CPPBOOSTPLUGINSYSTEM_LOADANDUNLOADBENCHMARK_H
#define CPPBOOSTPLUGINSYSTEM_LOADANDUNLOADBENCHMARK_H

#endif //CPPBOOSTPLUGINSYSTEM_LOADANDUNLOADBENCHMARK_H


class LoadAndUnloadBenchmark : public TestCase{


protected:

    void runTest(unsigned long cycle) override {


        ysl::PluginLoader loader("plugins");


        startTimer();
        loader.load();

        /*
        loader.enable();


        //std::cout << "HelloPlugin Name:  "<<loader.getPlugin("HelloPlugin")->getName() << std::endl;

        loader.disable("HelloPlugin");
        loader.enable("HelloPlugin");



        loader.disable();
         */

        loader.unload();

        stopTimer();

        defineBenchmarkPoint(cycle,getName());

        resetTimer();

    }

    std::string getName() override {
        return "LoadAndUnloadBenchmark";
    }

};
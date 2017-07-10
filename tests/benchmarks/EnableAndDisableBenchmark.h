//
// Created by yannick lamprecht on 10.07.17.
//

#include <iostream>
#include "../TestCase.h"
#include "../../PluginLoader.h"

#ifndef CPPBOOSTPLUGINSYSTEM_ENABLEANDDISABLEBENCHMARK_H
#define CPPBOOSTPLUGINSYSTEM_ENABLEANDDISABLEBENCHMARK_H

#endif //CPPBOOSTPLUGINSYSTEM_ENABLEANDDISABLEBENCHMARK_H


class EnableAndDisableBenchmark : public TestCase{

protected:

    void runTest(unsigned long cycle) override {

        ysl::PluginLoader loader("plugins");



        loader.load();

        startTimer();
        loader.enable();


        /*
        std::cout << "HelloPlugin Name:  "<<loader.getPlugin("HelloPlugin")->getName() << std::endl;

        loader.disable("HelloPlugin");
        loader.enable("HelloPlugin");

        */

        loader.disable();

        stopTimer();

        defineBenchmarkPoint(cycle,getName());

        resetTimer();


        loader.unload();





    }


    std::string getName() override {
        return "EnableAndDisableBenchmark";
    }


};
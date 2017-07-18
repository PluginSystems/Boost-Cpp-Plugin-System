#include <iostream>
#include <boost/dll/import.hpp>
#include <sstream>
#include <fstream>
#include "PluginLoader.h"
#include "tests/TestCase.h"
#include "tests/benchmarks/LoadAndUnloadBenchmark.h"
#include "tests/benchmarks/EnableAndDisableBenchmark.h"

int main(int argc, char *argv[]) {


    std::list<std::shared_ptr<TestCase>> benchmarks;

    ysl::PluginLoader loader("plugin");

    benchmarks.push_back(std::make_shared<LoadAndUnloadBenchmark>(LoadAndUnloadBenchmark(loader)));
    benchmarks.push_back(std::make_shared<EnableAndDisableBenchmark>(EnableAndDisableBenchmark(loader)));

    unsigned long count = 250;

    for (std::shared_ptr<TestCase> testCase: benchmarks) {
        testCase->runTestFully(count);
        std::cout << "Test run finished" << std::endl;
    }



    std::stringstream fileName;

    fileName << "results_"<< count << "_" << std::chrono::system_clock::now().time_since_epoch().count() << ".csv";

    std::ofstream resultFile;


    resultFile.open(fileName.str());

    for (std::shared_ptr<TestCase> finishedBenchmark : benchmarks) {
        finishedBenchmark->printStats(resultFile);
    }

    benchmarks.clear();

    resultFile.close();

    return 0;

}
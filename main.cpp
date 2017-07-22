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

    unsigned long long count = 10;

    for (std::shared_ptr<TestCase> testCase: benchmarks) {
        testCase->setUp();
        testCase->runTestFully(count);
        testCase->tearDown();
        std::cout << "Test run finished" << std::endl;
    }









    for (std::shared_ptr<TestCase> finishedBenchmark : benchmarks) {

        std::stringstream fileName;

        fileName << "results_"<<finishedBenchmark->getName()<<"_precision_nanoseconds"<<"_"<<"_"<< count << "_" << std::chrono::system_clock::now().time_since_epoch().count() << ".csv";

        std::ofstream resultFile;

        resultFile.open(fileName.str());

        finishedBenchmark->printStats(resultFile);

        resultFile.close();

    }

    benchmarks.clear();



    return 0;

}
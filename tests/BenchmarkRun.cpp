//
// Created by yannick lamprecht on 10.07.17.
//

#include <iostream>
#include "BenchmarkRun.h"

void BenchmarkRun::defineBenchmarkPoint(std::string benchmarkPointName, long nanosElapsed) {
    _stats.insert({benchmarkPointName,nanosElapsed});
}

void BenchmarkRun::defineBenchmarkPoint(std::string benchmarkPointName, int run, long nanosElapsed) {
    _stats[benchmarkPointName + std::to_string(run)] = nanosElapsed;
}

std::list<std::string> BenchmarkRun::getStatsCommaSeparatedList() {
    std::list<std::string> stringList(_stats.size());

    for (auto keyValue : _stats) {
        stringList.push_back(keyValue.first + ";" + std::to_string(keyValue.second));
    }
    return stringList;
}

void BenchmarkRun::printStats(std::ostream &outputStream) {
    for (auto value : getStatsCommaSeparatedList()) {
        outputStream << value << std::endl;
    }
}

#include <iostream>
#include <boost/dll/import.hpp>
#include <boost/range.hpp>
#include "IPlugin.h"
#include "PluginLoader.h"

int main(int argc, char *argv[]) {




    ysl::PluginLoader loader("plugins");

    loader.load();

    loader.enable();


    std::cout << "HelloPlugin Name:  "<<loader.getPlugin("HelloPlugin")->getName() << std::endl;

    loader.disable("HelloPlugin");
    loader.enable("HelloPlugin");



    loader.disable();

    loader.unload();



}
/*
    std::string dir("./plugins");
    ysl::PluginLoader p(dir);

    p.load();
    p.enable();
    p.disable();

    p.unload();

    return 0;
}

 */
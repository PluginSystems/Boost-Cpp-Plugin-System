#include <iostream>
#include <boost/dll/import.hpp>
#include <boost/range.hpp>
#include "IPlugin.h"
#include "PluginLoader.h"

int main(int argc, char *argv[]) {


    boost::filesystem::path lib_path(argv[1]);          // argv[1] contains path to directory with our plugin library
    boost::shared_ptr<IPlugin> plugin;            // variable to hold a pointer to plugin variable
    std::cout << "Loading the plugin" << std::endl;

    plugin = boost::dll::import<IPlugin>(          // type of imported symbol is located between `<` and `>`
            lib_path / "HelloPlugin",                     // path to the library and library name
            "plugin",                                       // name of the symbol to import
            boost::dll::load_mode::append_decorations              // makes `libmy_plugin_sum.so` or `my_plugin_sum.dll` from `my_plugin_sum`
    );

    std::cout << "plugin->getName() call:  " << plugin->getName() << std::endl;



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
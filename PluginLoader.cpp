//
// Created by yannick lamprecht on 04.05.17.
//

#include <iostream>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/range.hpp>
#include <boost/dll/import.hpp>
#include "PluginLoader.h"



ysl::PluginLoader::PluginLoader(std::string &filePath) {
    this->filePath=filePath;
}

void ysl::PluginLoader::load() {

    boost::filesystem::path lib_path(filePath);
    boost::shared_ptr<IPlugin> plugin;
    std::cout << "Loading the plugin" << std::endl;

    std::cout << "plugindirectory: "<<lib_path.filename() << std::endl;

    boost::filesystem::create_directories(lib_path);

    if (boost::filesystem::is_directory(lib_path)) {

        for (auto &entry : boost::make_iterator_range(boost::filesystem::directory_iterator(lib_path), {})) {
            std::cout << entry << "\n";

            plugin = boost::dll::import<IPlugin>(
                    entry.path(),
                    "plugin",
                    boost::dll::load_mode::append_decorations
            );

            pluginFiles[plugin->getName()]=plugin;
        }

        //todo write further http://www.boost.org/doc/libs/1_64_0/doc/html/boost_dll/tutorial.html

    }


}


void ysl::PluginLoader::disable() {
    for (auto& plugin : pluginFiles) {
        plugin.second->onDisable();
    }
}

void ysl::PluginLoader::enable() {

    for(auto& plugin : pluginFiles){
        plugin.second->onEnable();
    }


}

void ysl::PluginLoader::unload() {
    pluginFiles.clear();
}
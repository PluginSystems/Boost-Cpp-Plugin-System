//
// Created by yannick lamprecht on 04.05.17.
//

#include <iostream>
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/range.hpp>
#include <boost/dll/import.hpp>
#include "PluginLoader.h"


ysl::PluginLoader::PluginLoader(const std::string &filePath) {
    this->filePath = filePath;
}

void ysl::PluginLoader::load() {

    boost::filesystem::path lib_path(filePath);

    //std::cout << "Loading the plugin" << std::endl;

    //std::cout << "plugindirectory: " << lib_path.filename() << std::endl;

    boost::filesystem::create_directories(lib_path);

    if (boost::filesystem::is_directory(lib_path)) {

        for (auto &entry : boost::make_iterator_range(boost::filesystem::directory_iterator(lib_path), {})) {
            //std::cout << entry << "\n";
            this->load(entry.path().generic_string());
        }
    }
}


void ysl::PluginLoader::disable() {
    for (auto &plugin : pluginFiles) {
        plugin.second->onDisable();
    }
}

void ysl::PluginLoader::enable() {

    for (auto &plugin : pluginFiles) {
        plugin.second->onEnable();
    }


}

void ysl::PluginLoader::unload() {
    pluginFiles.clear();
}

boost::shared_ptr<IPlugin> ysl::PluginLoader::getPlugin(const std::string &pluginName) {
    return pluginFiles[pluginName];

}


void ysl::PluginLoader::disable(const std::string &pluginName) {
    pluginFiles[pluginName]->onDisable();
}

void ysl::PluginLoader::enable(const std::string &pluginName) {
    pluginFiles[pluginName]->onEnable();
}


void ysl::PluginLoader::unload(const std::string &pluginName) {
    pluginFiles.erase(pluginName);
}


void ysl::PluginLoader::load(const std::string &pluginName) {

    boost::shared_ptr<IPlugin> plugin = boost::dll::import<IPlugin>(
            pluginName,
            "plugin",
            boost::dll::load_mode::append_decorations
    );

    pluginFiles[plugin->getName()] = plugin;
}
//
// Created by yannick lamprecht on 04.05.17.
//

#ifndef CPPBOOSTPLUGINSYSTEM_PLUGINLOADER_H
#define CPPBOOSTPLUGINSYSTEM_PLUGINLOADER_H

#include <string>
#include <unordered_map>
#include "IPlugin.h"
#include <boost/dll/alias.hpp>                          // for BOOST_DLL_ALIAS
#include <boost/shared_ptr.hpp>

namespace ysl {




        boost::shared_ptr<IPlugin> create_plugin();   // Forward declaration

    class PluginLoader {

    protected:
        std::string filePath;
        std::unordered_map<std::string, boost::shared_ptr<IPlugin>> pluginFiles;

    public:

        PluginLoader(std::string &filePath);

        void disable(const std::string &pluginName);

        void enable(const std::string &pluginName);

        void enable();

        void disable();

        void load();

        void unload();

        std::unordered_map<std::string, std::shared_ptr<IPlugin>> getLoadedPlugins();

        void unload(const std::string &pluginName);
    };


};

BOOST_DLL_ALIAS(
        ysl::create_plugin,                        // <-- this function is exported with...
        create_plugin                                       // <-- ...this alias name
)

#endif //CPPBOOSTPLUGINSYSTEM_PLUGINLOADER_H

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


    class PluginLoader {

    protected:
        std::string filePath;
        std::unordered_map<std::string, boost::shared_ptr<IPlugin>> pluginFiles;

    public:

        PluginLoader(const std::string &filePath);

        void disable(const std::string &pluginName);

        void enable(const std::string &pluginName);

        void enable();

        void disable();

        void load();

        void unload();


        boost::shared_ptr<IPlugin> getPlugin(const std::string &pluginName);

        void unload(const std::string &pluginName);
    };

};


#endif //CPPBOOSTPLUGINSYSTEM_PLUGINLOADER_H

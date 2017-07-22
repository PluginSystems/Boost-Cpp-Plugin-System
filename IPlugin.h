//
// Created by yannick lamprecht on 04.05.17.
//

#ifndef CPPBOOSTPLUGINSYSTEM_IPLUGIN_H
#define CPPBOOSTPLUGINSYSTEM_IPLUGIN_H


#include <string>
    class IPlugin {

    public:

        virtual void onEnable()= 0;

        virtual void onDisable()= 0;

        virtual std::string getName()=0;
    };

#endif //CPPBOOSTPLUGINSYSTEM_IPLUGIN_H

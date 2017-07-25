//
// Created by yannick lamprecht on 24.07.17.
//

#ifndef CPPBOOSTPLUGINSYSTEM_STRINGFACE_H
#define CPPBOOSTPLUGINSYSTEM_STRINGFACE_H


#include <string>

class StringFace {
public:
    virtual void printMessage(std::string message)=0;
    virtual std::string modifyMessage(std::string message)=0;
};


#endif //CPPBOOSTPLUGINSYSTEM_STRINGFACE_H

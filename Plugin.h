//
// Created by yannick lamprecht on 05.05.17.
//

#ifndef CPPBOOSTPLUGINSYSTEM_PLUGIN_H
#define CPPBOOSTPLUGINSYSTEM_PLUGIN_H

#include <boost/dll/alias.hpp>                          // for BOOST_DLL_ALIAS
#include <boost/shared_ptr.hpp>
#include "IPlugin.h"

namespace ysl {
    boost::shared_ptr<IPlugin> create_plugin();   // Forward declaration
} // namespace my_namespace

/*BOOST_DLL_ALIAS(
    ysl::create_plugin,                        // <-- this function is exported with...
    create_plugin                                       // <-- ...this alias name
)
 */


#endif //CPPBOOSTPLUGINSYSTEM_PLUGIN_H

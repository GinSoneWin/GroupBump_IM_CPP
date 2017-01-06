//
// Created by WenJinXiong on 16-12-25.
//
#include "global.h"
#include <log4cpp/PropertyConfigurator.hh>
#include "../util/logger/CodeDebugConsoleLogger.h"
#include "../connector_layer/server/context/AbstractSocketServerContext.h"


std::shared_ptr<Logger> GLOBAL_CONSOLE_LOGGER = nullptr;
void globalInit(){
    log4cpp::PropertyConfigurator::configure("./../../config/log4cpp.properties");
    GLOBAL_CONSOLE_LOGGER = CodeDebugConsoleLogger::getInstance();
    GLOBAL_CONSOLE_LOGGER->debug("log4cpp logger setting up!");
    AbstractSocketServerContext::globalinit();
}
void sigterm_handler(int signo,siginfo_t *info,void *context)
{
    GLOBAL_CONSOLE_LOGGER->debug("groupbump application terminate");
}
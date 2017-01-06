//
// Created by WenJinXiong on 16-12-25.
//

#include "CodeDebugConsoleLogger.h"
std::shared_ptr<Logger> CodeDebugConsoleLogger::codedebuglogger_ptr = nullptr;
CodeDebugConsoleLogger::CodeDebugConsoleLogger():codedebugconsole_category(log4cpp::Category::getRoot()) {

}
CodeDebugConsoleLogger::~CodeDebugConsoleLogger() {

}
void CodeDebugConsoleLogger::debug(const std::string &info) {
    codedebugconsole_category.debug(info);
}

void CodeDebugConsoleLogger::info(const std::string &info) {
    codedebugconsole_category.info(info);
}

void CodeDebugConsoleLogger::error(const std::string &info) {
    codedebugconsole_category.error(info);
}
std::shared_ptr<Logger> CodeDebugConsoleLogger::getInstance() {
    if(codedebuglogger_ptr == nullptr)
        codedebuglogger_ptr.reset(new CodeDebugConsoleLogger());
    return codedebuglogger_ptr;
}
//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include "Logger.h"
#include <memory>
#include <log4cpp/Category.hh>

class CodeDebugConsoleLogger : public Logger{
public:

    virtual ~CodeDebugConsoleLogger();
    virtual void debug(const std::string &info) override;

    virtual void info(const std::string &info) override;

    virtual void error(const std::string &info) override;

    static std::shared_ptr<Logger> getInstance();


protected:
    CodeDebugConsoleLogger();
private:
    static std::shared_ptr<Logger> codedebuglogger_ptr;
    log4cpp::Category &codedebugconsole_category;
};




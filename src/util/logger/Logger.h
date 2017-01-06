//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

#include <string>

class Logger {
public:

    virtual ~Logger();
    virtual void debug(const std::string &info) = 0;
    virtual void info(const std::string &info) = 0;
    virtual void error(const std::string &info) = 0;

protected:
    Logger();

};

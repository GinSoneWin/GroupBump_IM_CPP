//
// Created by WenJinXiong on 16-12-25.
//

#include <cstdio>
#include <memory>
#include "log4cpp/Category.hh"
#include "log4cpp/FileAppender.hh"
#include "log4cpp/SimpleLayout.hh"
#include "log4cpp/Configurator.hh"
#include "log4cpp/PropertyConfigurator.hh"
#include <string>
int main()
{

    std::string initfileName = "./../../config/log4cpp.properties";

    log4cpp::PropertyConfigurator::configure(initfileName);




    log4cpp::Category &root_category = log4cpp::Category::getRoot();
    root_category.debug("debug log");
    root_category.info("info log");
    root_category.error("error log");


}
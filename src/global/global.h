//
// Created by WenJinXiong on 16-12-25.
//


#pragma once
#include <pthread.h>
#include <sys/stat.h>
#include "log4cpp/Category.hh"
#include <memory>
#include "../util/logger/Logger.h"
#include "../util/wrapper/unix_develop.h"

extern const mode_t FILE_MODE;
extern std::shared_ptr<Logger> GLOBAL_CONSOLE_LOGGER;
using fonny_thread_id_t = pthread_t;
void globalInit();
void sigterm_handler(int signo,siginfo_t *info,void *context);

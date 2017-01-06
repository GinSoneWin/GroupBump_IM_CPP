//
// Created by WenJinXiong on 16-12-26.
//

#pragma once

#include "AbstractEventHandler.h"

class AbstractEvent;

class NewConnEventHandler : public AbstractEventHandler{
public:
    NewConnEventHandler();

    virtual ~NewConnEventHandler();

    void handle_event(std::shared_ptr<AbstractEvent> event) override;
};





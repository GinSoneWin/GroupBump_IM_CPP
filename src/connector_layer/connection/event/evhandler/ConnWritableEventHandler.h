//
// Created by WenJinXiong on 16-12-26.
//

#pragma once

#include <memory>
#include "AbstractEventHandler.h"



class ConnWritableEventHandler : public AbstractEventHandler{
public:
    ConnWritableEventHandler();

    virtual ~ConnWritableEventHandler();

    void handle_event(std::shared_ptr<AbstractEvent> event) override;
};




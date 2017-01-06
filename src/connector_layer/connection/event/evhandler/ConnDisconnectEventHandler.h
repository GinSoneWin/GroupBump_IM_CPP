//
// Created by WenJinXiong on 16-12-26.
//

#pragma once

#include "AbstractEventHandler.h"

class ConnDisconnectEventHandler : public AbstractEventHandler{
public:
    ConnDisconnectEventHandler();
    virtual ~ConnDisconnectEventHandler();
    void handle_event(std::shared_ptr<AbstractEvent> event) override;
};





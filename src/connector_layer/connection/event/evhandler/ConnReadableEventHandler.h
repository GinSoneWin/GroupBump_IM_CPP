//
// Created by WenJinXiong on 16-12-26.
//

#pragma once
#include "../evhandler/AbstractEventHandler.h"
#include <memory>
class AbstractEvent;

class ConnReadableEventHandler : public  AbstractEventHandler{
public:
    ConnReadableEventHandler();

    virtual ~ConnReadableEventHandler();

    void handle_event(std::shared_ptr<AbstractEvent> event) override;
};





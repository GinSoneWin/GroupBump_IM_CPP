//
// Created by WenJinXiong on 16-12-26.
//

#include "ConnReadableEventHandler.h"
#include "../../../../global/global.h"
#include "../general/AbstractEvent.h"
#include "../../context/AbstractSocketConnectionContext.h"

ConnReadableEventHandler::ConnReadableEventHandler() {

}

ConnReadableEventHandler::~ConnReadableEventHandler() {


}
void ConnReadableEventHandler::handle_event(std::shared_ptr<AbstractEvent> event) {
    GLOBAL_CONSOLE_LOGGER->debug("connection readable eventhandler starts");
    event->getConncontext_ptr()->read();
    GLOBAL_CONSOLE_LOGGER->debug("connection readable eventhandler ends");

}
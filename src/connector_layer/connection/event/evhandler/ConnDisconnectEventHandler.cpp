//
// Created by WenJinXiong on 16-12-26.
//

#include "ConnDisconnectEventHandler.h"
#include "../../../../global/global.h"
#include "../../../server/context/AbstractSocketServerContext.h"
#include "../dispatcher/AbstractDispatcher.h"
#include "../general/AbstractEvent.h"

ConnDisconnectEventHandler::ConnDisconnectEventHandler():AbstractEventHandler()
{
}
ConnDisconnectEventHandler::~ConnDisconnectEventHandler() {

}
void ConnDisconnectEventHandler::handle_event(std::shared_ptr<AbstractEvent> event) {
    GLOBAL_CONSOLE_LOGGER->debug("conndisconection event handler starts;");
    AbstractSocketServerContext::getInstance()->getDispatcher()->remove_event(event);
    GLOBAL_CONSOLE_LOGGER->debug("conndisconection event handler end;");
}
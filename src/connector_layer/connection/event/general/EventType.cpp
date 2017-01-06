//
// Created by WenJinXiong on 16-12-25.
//

#include "EventType.h"


EventType::EventType(int type):type(type)
{

}
EventType::~EventType()
{

}
bool EventType::operator==(const EventType &eventType) const {
    return (this->type == eventType.type);
}
EventType EventType::LISTEN_EVENT(){
    return EventType(0);
}
EventType EventType::NEWCONN_EVENT(){
    return EventType(1);
}
EventType EventType::CONNREADABLE_EVENT(){
    return EventType(2);
}
EventType EventType::CONNWRITABLE_EVENT(){
    return EventType(3);
}
EventType EventType::REGISTER_READ_EVENT(){
    return EventType(4);
}
EventType EventType::REGISTER_WRITE_EVENT(){
    return EventType(5);
}
EventType EventType::CONN_DISCONNECT() {
    return EventType(6);
}
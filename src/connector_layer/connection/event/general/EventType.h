//
// Created by WenJinXiong on 16-12-25.
//

#pragma once

class EventType {
public:
    ~EventType();
    static EventType LISTEN_EVENT();
    static EventType NEWCONN_EVENT();
    static EventType CONNREADABLE_EVENT();
    static EventType CONNWRITABLE_EVENT();
    static EventType REGISTER_READ_EVENT();
    static EventType REGISTER_WRITE_EVENT();
    static EventType CONN_DISCONNECT();
    bool operator==(const EventType &eventType)const ;
private:
    EventType(int type);
    int type;
};





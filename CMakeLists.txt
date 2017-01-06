cmake_minimum_required(VERSION 3.6)
project(GroupBump_IM)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wl,--no-as-needed -pthread -Wall")


#add log4cpp library
add_library(log4cpp STATIC IMPORTED )
set_target_properties(log4cpp PROPERTIES
        IMPORTED_LOCATION_DEBUG lib/log4cpp/liblog4cpp.a
        IMPORTED_LOCATION_RELEASE lib/log4cpp/liblog4cpp.a
        )





#source file list
set(SOURCE_FILES main.cpp
        src/global/global.h src/global/global.cpp

        src/util/logger/Logger.cpp src/util/logger/Logger.h src/util/logger/CodeDebugConsoleLogger.cpp src/util/logger/CodeDebugConsoleLogger.h
        src/util/wrapper/wraplinux.cpp src/util/wrapper/wrappthread.cpp src/util/wrapper/wrapsock.cpp src/util/wrapper/wrapunix.cpp src/util/wrapper/signal.cpp src/util/wrapper/signal_intr.cpp  src/util/wrapper/signal_rt.cpp  src/util/wrapper/signal_rt_intr.cpp
        src/util/lock/Lock.cpp src/util/lock/Lock.h src/util/lock/SemaphoreLock.cpp src/util/lock/SemaphoreLock.h
        src/util/thread/ThreadGuard.cpp src/util/thread/ThreadGuard.h src/util/thread/AbstractThreadGroup.cpp src/util/thread/AbstractThreadGroup.h src/util/thread/BasicThreadGroup.cpp src/util/thread/BasicThreadGroup.h src/util/thread/AbstractThread.cpp src/util/thread/AbstractThread.h src/util/thread/BossThread.cpp src/util/thread/BossThread.h src/util/thread/WorkerThread.cpp src/util/thread/WorkerThread.h

        src/connector_layer/server/context/AbstractSocketServerContext.cpp src/connector_layer/server/context/AbstractSocketServerContext.h src/connector_layer/server/context/BasicSocketServerContext.cpp src/connector_layer/server/context/BasicSocketServerContext.h
        src/connector_layer/connection/context/AbstractSocketConnectionMap.cpp src/connector_layer/connection/context/AbstractSocketConnectionMap.h src/connector_layer/connection/context/BasicSocketConnectionMap.cpp src/connector_layer/connection/context/BasicSocketConnectionMap.h src/connector_layer/connection/context/AbstractSocketConnectionContext.cpp src/connector_layer/connection/context/AbstractSocketConnectionContext.h src/connector_layer/connection/context/BasicSocketConnectionContext.cpp src/connector_layer/connection/context/BasicSocketConnectionContext.h
        src/connector_layer/connection/event/general/Event.cpp src/connector_layer/connection/event/general/Event.h src/connector_layer/connection/event/general/EventType.cpp src/connector_layer/connection/event/general/EventType.h src/connector_layer/connection/event/evhandler/AbstractEventHandler.cpp src/connector_layer/connection/event/evhandler/AbstractEventHandler.h src/connector_layer/connection/event/general/AbstractEvent.cpp src/connector_layer/connection/event/general/AbstractEvent.h src/connector_layer/connection/event/dispatcher/AbstractDispatcher.cpp src/connector_layer/connection/event/dispatcher/AbstractDispatcher.h src/connector_layer/connection/event/dispatcher/BasicDispatcher.cpp src/connector_layer/connection/event/dispatcher/BasicDispatcher.h src/connector_layer/connection/event/dispatcher/AbstractDemultiplexer.cpp src/connector_layer/connection/event/dispatcher/AbstractDemultiplexer.h src/connector_layer/connection/event/dispatcher/EpollDemultiplexer.cpp src/connector_layer/connection/event/dispatcher/EpollDemultiplexer.h src/connector_layer/connection/event/dispatcher/AbstractEventQueue.cpp src/connector_layer/connection/event/dispatcher/AbstractEventQueue.h src/connector_layer/connection/event/dispatcher/BasicEventQueue.cpp src/connector_layer/connection/event/dispatcher/BasicEventQueue.h
        src/connector_layer/connection/initializer/SocketConnectionInitializer.cpp src/connector_layer/connection/initializer/SocketConnectionInitializer.h src/connector_layer/connection/initializer/BasicSocketConnectionInitializer.cpp src/connector_layer/connection/initializer/BasicSocketConnectionInitializer.h
        src/connector_layer/connection/msghandler/inbound/SocketConnectionInboundHandler.cpp src/connector_layer/connection/msghandler/inbound/SocketConnectionInboundHandler.h src/connector_layer/connection/msghandler/outbound/SocketConnectionOutboundHandler.cpp src/connector_layer/connection/msghandler/outbound/SocketConnectionOutboundHandler.h src/connector_layer/connection/msghandler/context/SocketConnectionHandlerChain.cpp src/connector_layer/connection/msghandler/context/SocketConnectionHandlerChain.h src/connector_layer/connection/msghandler/context/SocketConnectionHandlerContext.cpp src/connector_layer/connection/msghandler/context/SocketConnectionHandlerContext.h src/connector_layer/connection/msghandler/outbound/SocketMessageEncoder.cpp src/connector_layer/connection/msghandler/outbound/SocketMessageEncoder.h src/connector_layer/connection/msghandler/inbound/SocketMessageDecoder.cpp src/connector_layer/connection/msghandler/inbound/SocketMessageDecoder.h src/connector_layer/connection/msghandler/inbound/LengthBasedFrameDecoder.cpp src/connector_layer/connection/msghandler/inbound/LengthBasedFrameDecoder.h src/connector_layer/connection/msghandler/context/BasicSocketConnectionHandlerChain.cpp src/connector_layer/connection/msghandler/context/BasicSocketConnectionHandlerChain.h
        src/connector_layer/connection/general/SocketConnection.cpp src/connector_layer/connection/general/SocketConnection.h src/connector_layer/connection/general/BasicSocketConnection.cpp src/connector_layer/connection/general/BasicSocketConnection.h
        src/connector_layer/connection/buffer/ByteBuffer.cpp src/connector_layer/connection/buffer/ByteBuffer.h src/connector_layer/connection/buffer/BasicByteBuffer.cpp src/connector_layer/connection/buffer/BasicByteBuffer.h
        src/connector_layer/connection/event/evhandler/NewConnEventHandler.cpp src/connector_layer/connection/event/evhandler/NewConnEventHandler.h src/connector_layer/connection/event/evhandler/ConnDisconnectEventHandler.cpp src/connector_layer/connection/event/evhandler/ConnDisconnectEventHandler.h src/connector_layer/connection/event/evhandler/ConnReadableEventHandler.cpp src/connector_layer/connection/event/evhandler/ConnReadableEventHandler.h src/connector_layer/connection/event/evhandler/ConnWritableEventHandler.cpp src/connector_layer/connection/event/evhandler/ConnWritableEventHandler.h
        )



#final executable file
#add_executable(GroupBump_IM ${SOURCE_FILES})






#test file
add_executable(testThread testThread.cpp src/util/thread/AbstractThread.cpp  src/util/thread/AbstractThreadGroup.cpp src/util/thread/BasicThreadGroup.cpp src/util/thread/ThreadGuard.cpp)
target_link_libraries(testThread pthread rt)

add_executable(testSignal testSignal.cpp src/util/wrapper/wraplinux.cpp src/util/wrapper/wrappthread.cpp src/util/wrapper/wrapsock.cpp src/util/wrapper/wrapunix.cpp src/util/wrapper/signal.cpp src/util/wrapper/signal_intr.cpp src/util/wrapper/signal_rt.cpp src/util/wrapper/signal_rt_intr.cpp )
target_link_libraries(testSignal pthread rt)

add_executable(testMutex testMutex.cpp  src/util/thread/AbstractThread.cpp  src/util/thread/AbstractThreadGroup.cpp src/util/thread/BasicThreadGroup.cpp src/util/thread/ThreadGuard.cpp)
target_link_libraries(testMutex pthread rt)

#final executable file
add_executable(GroupBump_IM_Main  ${SOURCE_FILES})
target_link_libraries(GroupBump_IM_Main log4cpp.a pthread rt )
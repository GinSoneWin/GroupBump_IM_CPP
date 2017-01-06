#include <iostream>
#include "src/connector_layer/connection/context/AbstractSocketConnectionContext.h"
#include "src/global/global.h"
#include "src/connector_layer/server/context/AbstractSocketServerContext.h"
#include "src/connector_layer/connection/initializer/BasicSocketConnectionInitializer.h"

int main(int argc, char **argv) {
    if(argc != 2){
        printf("usage: main <port>\n");
        exit(1);
    }
    globalInit();
    std::shared_ptr<AbstractSocketServerContext> servercontext = AbstractSocketServerContext::getInstance();
    servercontext->setConnectionInitializer(std::make_shared<BasicSocketConnectionInitializer>()).setWorkerThreadCnt(6).bind(atoi(argv[1]));
    servercontext->init();
    servercontext->sync();
}
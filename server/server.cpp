#include "quickfix/FileStore.h"
#include "quickfix/SocketAcceptor.h"
#include "Application.h"
#include "quickfix/FileLog.h"
#include "quickfix/SessionSettings.h"

#include <fstream>
#include <iostream>
#include <memory>
#include <string>

void wait() {
  std::cout << "Type Ctrl-C to quit" << std::endl;
  while (true) {
    FIX::process_sleep(1);
  }
}

int main(int argc, char **argv) {

  try {
    FIX::SessionSettings settings("server/server.cfg");

    Application application;
    FIX::FileStoreFactory storeFactory(settings);
    FIX::FileLogFactory logFactory(settings);

    std::unique_ptr<FIX::Acceptor> acceptor;
    acceptor = std::unique_ptr<FIX::Acceptor>(new FIX::SocketAcceptor(application, storeFactory, settings, logFactory));

    acceptor->start();
    wait();
    acceptor->stop();

    return 0;
  } catch (std::exception &e) {
    std::cout << e.what() << std::endl;
    return 1;
  }
}
#include <iostream>
#include "Application.h"
#include "quickfix/FileLog.h"
#include "quickfix/SessionSettings.h"
#include "quickfix/FileStore.h"
#include "quickfix/SocketInitiator.h"
#include <memory>
#include <string>
#include <fstream>


int main(int argc, char* argv[]) {
  std::cout << "CLIENT" << std::endl;

  try {
    FIX::SessionSettings settings("client/client.cfg");

    Application application;
    FIX::FileStoreFactory storeFactory(settings);
    FIX::FileLogFactory logFactory(settings);

    std::unique_ptr<FIX::Initiator> initiator;

  
    initiator = std::unique_ptr<FIX::Initiator>(new FIX::SocketInitiator(application, storeFactory, settings, logFactory));

    initiator->start();
    application.run();
    initiator->stop();

    return 0;
  } catch (std::exception &e) {
    std::cout << e.what();
    return 1;
  }
}
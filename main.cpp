//
// async_tcp_echo_server.cpp
// ~~~~~~~~~~~~~~~~~~~~~~~~~
//
// Copyright (c) 2003-2021 Christopher M. Kohlhoff (chris at kohlhoff dot com)
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
//

#include <cstdlib>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

#include "server.hpp"

using boost::asio::ip::tcp;

int main(int argc, char* argv[]) {
  try {
    // parse command args for Config
    int port = 2000;

    boost::asio::io_context io_context;

    using namespace std; // For atoi.
    server s(io_context, port);

    std::cout << "Start service at port: " << port << std::endl;
    io_context.run();
  } catch (std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
  }

  return 0;
}

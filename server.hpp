
#pragma once
#ifndef TCP_SERVER_HPP
#define TCP_SERVER_HPP

#include <cstdlib>
#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

#include "session.hpp"

using boost::asio::ip::tcp;

class server {
public:
  server(boost::asio::io_context& io_context, short port) : io_context_(io_context),
      acceptor_(io_context, tcp::endpoint(tcp::v4(), port)) {
    start_accept();
  }

private:
  void start_accept() {
    session* new_session = new session(io_context_);
    acceptor_.async_accept(new_session->socket(),
        boost::bind(&server::handle_accept, this, new_session,
        boost::asio::placeholders::error));
  }

  void handle_accept(session* new_session, const boost::system::error_code& error) {
    std::cout << "start new session" << std::endl;
    if (!error) {
      new_session->start();
    } else {
      delete new_session;
    }

    start_accept();
  }

  boost::asio::io_context& io_context_;
  tcp::acceptor acceptor_;
};

#endif
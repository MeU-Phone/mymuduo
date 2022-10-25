#pragma once

#include <mymuduo/TcpServer.h>

class DaytimeServer
{
public:
    DaytimeServer(EventLoop *loop,
                  const InetAddress &listenAddrs);
    void start();

private:
    void onConnection(const TcpConnectionPtr &conn);
    void onMessage(const TcpConnectionPtr &conn,
                   Buffer *buf, Timestamp time);
    TcpServer server_;
};
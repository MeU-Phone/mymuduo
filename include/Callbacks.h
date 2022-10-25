#pragma once

#include <functional>
#include <memory>

class Buffer;
class TcpConnection;
class Timestamp;

using TcpConnectionPtr = std::shared_ptr<TcpConnection>;
using TimerCallback = std::function<void()>;
using ConnectionCallback = std::function<void(const TcpConnectionPtr&)>;
using CloseCallback = std::function<void(const TcpConnectionPtr&)>;
using WriteCompleteCallback = std::function<void(const TcpConnectionPtr&)>;
using HighWaterMarkCallback =
    std::function<void(const TcpConnectionPtr&, size_t)>;
using MessageCallback =
    std::function<void(const TcpConnectionPtr&, Buffer*, Timestamp)>;

static void defaultConnectionCallback(const TcpConnectionPtr& conn);
static void defaultMessageCallback(const TcpConnectionPtr& conn,
                                   Buffer* bufferm, Timestamp receiveTime);
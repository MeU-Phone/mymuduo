#include "Poller.h"
#include "EPollPoller.h"

#include <stdlib.h>

Poller* Poller::newDefaultPoller(EventLoop* loop) {
    // if (::getenv("MUDUO_USE_POLL"))
    //{
    //     return new PollPoller(loop);
    // }
    // else
    //{
    return new EPollPoller(loop);
    //}
}

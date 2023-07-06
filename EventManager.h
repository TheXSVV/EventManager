#pragma once

#include <memory>
#include <functional>
#include <vector>
#include "Event.h"

using namespace std;

class EventManager {
public:
    template<typename T>
    inline void Register(function<void(shared_ptr<T>)> handler) {
        handlers.push_back([handler](shared_ptr<Event> event) {
            if (auto casted = dynamic_pointer_cast<T>(event))
                handler(casted);
        });
    }
    inline void Call(shared_ptr<Event> event) {
        for (auto &handler : handlers)
            handler(event);
    }
private:
    vector<function<void(shared_ptr<Event>)>> handlers;
};

# EventManager

## Использование / Usage:
#### Создание своего евента / Creating a custom event:
```cpp
#include <Event.h>

class MessageEvent : public Event {
public:
    MessageEvent(const char* text) : text(text) {}

    const char* GetText() {
        return this->text;
    }
private:
    const char* text;
};
```
#### Использование евентов / Event usage:
```cpp
#include <iostream>
#include <EventManager.h>
#include "MessageEvent.h"

int main() {
    EventManager eventManager; // Создаём объект EventManager
	
	eventManager.Register<MessageEvent>([](shared_ptr<MessageEvent> event) { // Регистрация handler
	    std::cout << event->GetText() << std::endl;
	}
	
	eventManager.Call(make_shared<MessageEvent>("Message event called!")); // Вызов евента
}
```

project(EventManager)

add_library(EventManager
    Event.h
    EventManager.h
)

set_target_properties(EventManager PROPERTIES LINKER_LANGUAGE CXX)

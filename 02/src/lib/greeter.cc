#include "greeter.h"

namespace simple_app {
    std::string GetGreet(const std::string& who) {
        return "Hello " + who;
    }
}
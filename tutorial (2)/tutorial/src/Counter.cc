#include "Counter.h"

Counter::Counter() : value(0) {}

Counter::Counter(int value) : value(value) {}

int Counter::getValue() const { return value; }

void Counter::increment() {
    value++;
}

bool Counter::decrement() {
    // BUG: no comprueba si value es 0
    value--;
    return true;
}

std::ostream& operator<<(std::ostream& os, const Counter& c) {
    // BUG: formato incorrecto, debería ser "Counter: <value>"
    os << "Counter = " << c.value;
    return os;
}

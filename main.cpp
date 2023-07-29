#include "logger.hpp"

int main() {

    std::string a = "1. HELLO WORLD";
    std::string b = "2. ABCDEFGHIJ";
    std::string c = "3. 1234567890";

    Logger logger;

    std::thread w1(logWrite, std::ref(logger), std::ref(a));
    w1.join();

    std::thread w2(logWrite, std::ref(logger), std::ref(b));
    w2.join();

    std::thread w3(logWrite, std::ref(logger), std::ref(c));
    w3.join();

    std::thread r(logRead, std::ref(logger));
    r.join();

    return 0;
}
#include "httplib.h"
#include <iostream>

int main() {
    httplib::Server svr;

    svr.Get("/ping", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("tracker alive!", "text/plain");
        std::cout << "[Tracker] Peer pinged tracker!" << std::endl;
    });

    std::cout << "[Tracker] HTTP tracker listening on port 80" << std::endl;
    svr.listen("0.0.0.0", 80);

    return 0;
}

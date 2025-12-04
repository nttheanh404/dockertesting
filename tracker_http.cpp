#include "httplib.h"
#include <iostream>

int main() {
    httplib::Server svr;

    // endpoint ping
    svr.Get("/ping", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("connected!", "text/plain");
        std::cout << "Peer pinged tracker!" << std::endl;
    });

    std::cout << "HTTP tracker listening on port 80" << std::endl;
    svr.listen("0.0.0.0", 80); // lắng nghe tất cả interface
}


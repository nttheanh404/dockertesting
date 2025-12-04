#include "httplib.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <httplib.h>

void ping_waker(const std::string& waker_url) {
    httplib::Client cli(waker_url.c_str());
    while (true) {
        auto res = cli.Get("/ping");
        if (res) std::cout << "[Tracker] Pinged waker: " << res->status << std::endl;
        else std::cout << "[Tracker] Failed to ping waker!" << std::endl;
        std::this_thread::sleep_for(std::chrono::minutes(4));
    }
}

int main() {
    httplib::Server svr;

    svr.Get("/ping", [](const httplib::Request&, httplib::Response& res) {
        res.set_content("tracker alive!", "text/plain");
        std::cout << "[Tracker] Peer pinged tracker!" << std::endl;
    });

    // thread ping waker
    std::thread ping_thread(ping_waker, "waker-service.onrender.com"); // URL waker

    std::cout << "[Tracker] HTTP tracker listening on port 80" << std::endl;
    svr.listen("0.0.0.0", 80);

    ping_thread.join();
}

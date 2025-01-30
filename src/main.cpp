#include <libtorrent/session.hpp>
#include <libtorrent/alert_types.hpp>
#include <iostream>

int main() {
    std::cout << "Libtorrent Messenger App" << std::endl;

    // Example setup for a libtorrent session
    lt::session ses;

    // Configure DHT
    ses.add_dht_router(std::make_pair("router.utorrent.com", 6881));
    ses.start_dht();

    // Basic loop to show alerts
    for (;;) {
        std::vector<lt::alert*> alerts;
        ses.pop_alerts(&alerts);

        for (lt::alert* a : alerts) {
            std::cout << a->message() << std::endl;
        }

        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    return 0;
}


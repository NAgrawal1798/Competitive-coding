#include <vector>
#include <map>
#include <climits>

class ExamRoom {
public:
    int n;
    std::set<int> seats;

    ExamRoom(int _n) : n(_n) {}

    int seat() {
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }

        int maxDistance = *seats.begin(); // Distance from the start
        int startSeat = 0;

        auto it = seats.begin();
        int prev = *it;
        ++it;

        // Iterate through the set to find the maximum distance
        while (it != seats.end()) {
            int curr = *it;
            int distance = (curr - prev) / 2;

            if (distance > maxDistance) {
                maxDistance = distance;
                startSeat = prev + distance;
            }

            prev = curr;
            ++it;
        }

        // Check distance from the last seat
        if (n - 1 - *seats.rbegin() > maxDistance) {
            startSeat = n - 1;
        }

        seats.insert(startSeat);
        return startSeat;
    }

    void leave(int p) {
        seats.erase(p);
    }
};

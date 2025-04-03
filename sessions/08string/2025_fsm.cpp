#include <iostream>

class FSM {
private:
    struct simple_state {
        uint32_t next_state[256];
        uint32_t action; // if zero, do nothing
    };
    struct ifstate {
        uint32_t case1; uint32_t next1;
        uint32_t case2; uint32_t next2;
        uint32_t defaultcase;
    }
    std::vector<simple_state> states;
public:
    FSM() {}

    void input(uint8_t inp[], uint32_t len) {
        uint32_t current = 0;
        for (int i = 0; i < len; i++) {
            if (action != 0) {
                //TODO: whatever we want to do...
                current = states[current].next_state[inp[i]];
            }
        }
    }

};

int main() {


}
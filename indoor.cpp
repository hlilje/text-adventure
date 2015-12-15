#include "environments.hpp"

using namespace text_adventure;


Indoor::Indoor(const bool locked) : Environment(), _locked(locked) {

}

bool Indoor::is_locked() {
    return _locked;
}

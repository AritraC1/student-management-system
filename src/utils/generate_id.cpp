#include <string>
#include <math.h>

std::string generate_id() {
    int new_id = rand();

    return std::to_string(new_id);
}
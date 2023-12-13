#include <iostream>
#include <vector>
#include <random>
#include <ctime>

std::string generate_random_name() {
    static std::mt19937 prng(static_cast<unsigned int>(std::time(nullptr)));

    std::vector<std::string> first_names = {
        "Ann", "Andrew", "John", "Jane", "Bob", "Alice", "Bertram", "Monica", "Laura", "Eric", "Richard", "Karen",
        "Clara", "Rupert", "Bruce", "Martha", "Elizabeth", "Corey", "Nancy", "Joe", "Amy", "Mike"
    };

    std::vector<std::string> last_names = {
        "Hendricks", "Smith", "Gates", "Stein", "Warren", "Booker", "Williamson", "Walters", "Dunn", "Swanson",
        "Knope", "Haverford", "Ludgate", "Meagle", "Favreau", "Vietor", "Lovett", "Pfeifer", "Rhodes", "Abrams",
        "McFaul", "Stone", "Sisley", "Hanneman"
    };

    std::uniform_int_distribution<size_t> fnd(0, first_names.size() - 1);
    std::uniform_int_distribution<size_t> lnd(0, last_names.size() - 1);

    return first_names[fnd(prng)] + " " + last_names[lnd(prng)];
}

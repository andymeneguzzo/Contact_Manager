#include "Statistics.h"
#include <iostream>
#include <map>

void Statistics::generateStatistics(const std::vector<Contact>& contacts) const {
    std::map<std::string, int> genderStats;
    std::map<std::string, int> statusStats;
    std::map<std::string, int> professionStats;

    for (const auto& contact : contacts) {
        genderStats[contact.getGender()]++;
        statusStats[contact.getStatus()]++;
        professionStats[contact.getProfession()]++;
    }

    std::cout << "\n=== Statistiche ===\n";

    std::cout << "\nGenere:\n";
    for (const auto& [gender, count] : genderStats) {
        std::cout << gender << ": " << count << "\n";
    }

    std::cout << "\nStato Civile:\n";
    for (const auto& [status, count] : statusStats) {
        std::cout << status << ": " << count << "\n";
    }

    std::cout << "\nProfessione:\n";
    for (const auto& [profession, count] : professionStats) {
        std::cout << profession << ": " << count << "\n";
    }
}
#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include "Contact.h"

class Statistics {
public:
    void generateStatistics(const std::vector<Contact>& contacts) const;
};

#endif // STATISTICS_H
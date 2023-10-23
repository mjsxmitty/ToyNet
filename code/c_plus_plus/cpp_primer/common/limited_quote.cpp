
#include "limited_quote.h"


double limitedQuote::NetPrice(std::size_t cnt) const
{
    if (cnt <= quantity)
        return cnt * (1 - discount) * price_;
    else
        return quantity * (1 - discount) * price_ + (cnt - quantity) * price_;
}

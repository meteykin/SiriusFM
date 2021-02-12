#pragma once

#include <stdexcept>
#include <cmath>


namespace SiriusFM
{
    class Option
    {
    protected:
        bool const m_isAmerican;
        int const m_Tdays;
        Option(bool a_isAmerican, int a_Tdays)
          : m_isAmerican(a_isAmerican), m_Tdays(a_Tdays)
        {
            if (m_Tdays <= 0) throw std::invalid_argument("non-positive m_Tdays in Option\n");
        }
    public:
        virtual double payoff(long a_l, double const* a_t, double const* a_S) const = 0;
        bool IsAmerican() const
        {
            return m_isAmerican;
        }
        virtual ~Option(){}
    };
}

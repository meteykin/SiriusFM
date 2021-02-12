#pragma once

#include <stdexcept>
#include <cmath>

#include "Option.h"

namespace SiriusFM
{
    class EurCallOption final: public Option
    {
    private:
        double const m_K;       //K > 0
    public:
        EurCallOption(double a_K, int a_Tdays)
          : Option(0, a_Tdays), m_K(a_K)
        {
            if (m_K <= 0) throw std::invalid_argument("non-positive m_K in EurCallOption\n");
        }
        ~EurCallOption() override {}
        double payoff(long a_l, double const* a_t, double const* a_S) const override
        {
            assert (a_l > 0 && a_S != nullptr);
            double sT = a_S[a_l - 1];
            return std::max<double>(sT - m_K, 0.0);
        }
    };

    class EurPutOption final: public Option
    {
    private:
        double const m_K;       //K > 0
    public:
        EurPutOption(double a_K, int a_Tdays)
          : Option(0, a_Tdays), m_K(a_K)
        {
            if (m_K <= 0) throw std::invalid_argument("non-positive m_K in EurPutOption\n");
        }
        ~EurPutOption() override {}
        double payoff(long a_l, double const* a_t, double const* a_S) const override
        {
            assert (a_l > 0 && a_S != nullptr);
            double sT = a_S[a_l - 1];
            return std::max<double>(m_K - sT, 0.0);
        }
    };
}

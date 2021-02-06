#pragma once
#include <stdexcept>
#include <cmath>

namespace SiriusFM
{
    class DiffusionLipton
    {
    private:
        double const m_mu, m_sigma0, m_sigma1, m_sigma2;
    public:
        double mu(double a_S, double a_t) const {
            return m_mu * a_S;
        }

        double sigma(double a_S, double a_t) const {
            return m_sigma0 + m_sigma1 * a_S + m_sigma2 * a_S * a_S;
        }

        explicit DiffusionLipton(double a_mu, double a_sigma0, double a_sigma1, double a_sigma2)
        :   m_mu(a_mu), m_sigma0(a_sigma0), m_sigma1(a_sigma1), m_sigma2(a_sigma2)
        {
            if (m_sigma1 * m_sigma1 - 4 * m_sigma0 * m_sigma2 > 0)
                throw std::invalid_argument("non-positive sigma\n");
        }
    };
}

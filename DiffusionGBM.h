#pragma once
#include <stdexcept>
#include <cmath>

namespace SiriusFM
{
    class DiffusionGBM
    {
    private:
        double const m_mu, m_sigma;
    public:
        double mu(double a_S, double a_t) const {
            return m_mu * a_S;
        }

        double sigma(double a_S, double a_t) const {
            return m_sigma * a_S;
        }

        explicit DiffusionGBM(double a_mu, double a_sigma)
        : m_mu(a_mu), m_sigma(a_sigma)
        {
            if (m_sigma <= 0) throw std::invalid_argument("non-positive sigma\n");
        }
    };
}

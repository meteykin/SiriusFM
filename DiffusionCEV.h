#pragma once
#include <stdexcept>
#include <cmath>

namespace SiriusFM
{
    class DiffusionCEV
    {
    private:
        double const m_mu, m_sigma, m_beta;
    public:
        double mu(double a_S, double a_t) const {
            return m_mu * a_S;
        }

        double sigma(double a_S, double a_t) const {
            return m_sigma * pow(a_S, m_beta);
        }

        explicit DiffusionCEV(double a_mu, double a_sigma, double a_beta)
        :   m_mu(a_mu), m_sigma(a_sigma), m_beta(a_beta)
        {
            if (m_sigma <= 0) throw std::invalid_argument("non-positive sigma in CEV\n");
            if (m_beta < 0) throw std::invalid_argument("non-positive beta in CEV\n");
        }
    };
}

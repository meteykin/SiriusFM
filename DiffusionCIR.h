#pragma once
#include <stdexcept>
#include <cmath>

namespace SiriusFM
{
    class DiffusionCIR
    {
    private:
        double const m_kappa, m_theta, m_sigma;
    public:
        double mu(double a_S, double a_t) const {
            return m_kappa * (m_theta - a_S);
        }

        double sigma(double a_S, double a_t) const {
            return sqrt(m_sigma) * a_S;
        }

        explicit DiffusionCIR(double a_kappa, double a_theta, double a_sigma)
        :   m_kappa(a_kappa), m_theta(a_theta), m_sigma(a_sigma)
        {
            if (m_theta <= 0) throw std::invalid_argument("non-positive theta in CIR\n");
            if (m_sigma <= 0) throw std::invalid_argument("non-positive sigma in CIR\n");
        }
    };
}

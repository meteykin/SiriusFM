#include <iostream>

#include "DiffusionCEV.h"
#include "DiffusionCIR.h"
#include "DiffusionGBM.h"
#include "DiffusionLipton.h"
#include "DiffusionOU.h"

int main()
{
    SiriusFM::DiffusionCEV a(1,1,1);
    SiriusFM::DiffusionCIR b(1,1,1);
    SiriusFM::DiffusionGBM c(1,1);
    SiriusFM::DiffusionLipton d(1,1,1,1);
    SiriusFM::DiffusionOU e(1,1,1);
    std::cout << "Hello world!" << std::endl;
    return 0;
}

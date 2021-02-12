#include <stdexcept>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "IRProviderConst.h"

namespace SiriusFM
{
    IRProvider <IRModeE::Const>::IRProvider (char const* a_file)
    {
        memset(m_IRs, 0, sizeof(m_IRs));
        if (!a_file)
            //throw std::invalid_argument("empty filename");
            return;

        FILE* fin;
        if (!(fin = fopen(a_file, "r")))
            //throw std::runtime_error("file not found");
            return;

        char* line = nullptr;
        size_t len = 0;

        while (getline(&line, &len, fin) != -1)
        {
            line[3] = '\0';
            m_IRs[(size_t)(Str2CcyE(line))] = atof(line + 4);
        }

        free(line);
        fclose(fin);
    }
}

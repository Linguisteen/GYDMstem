#pragma once

#include <gydm_stem/game.hpp>
#include <gydm_stem/bang.hpp>

namespace WarGrey::SCSM {
    class TheSCSMPlane : public WarGrey::STEM::TheBigBang {
    public:
        TheSCSMPlane(const char* name, uint32_t title_color = 0U);
        virtual ~TheSCSMPlane() {}
    };
}

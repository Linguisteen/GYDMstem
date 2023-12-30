#pragma once

#include <gydm/game.hpp>
#include <gydm/bang.hpp>

namespace WarGrey::STEM {
    class TheSCSMPlane : public GYDM::TheBigBang {
    public:
        TheSCSMPlane(const char* name, uint32_t title_color = 0U);
        virtual ~TheSCSMPlane() {}
    };
}

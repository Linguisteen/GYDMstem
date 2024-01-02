#pragma once

#include <gydm/game.hpp>
#include <gydm/bang.hpp>

namespace WarGrey::PLT {
    class ThePLTPlane : public GYDM::TheBigBang {
    public:
        ThePLTPlane(const char* name, uint32_t title_color = 0U);
        virtual ~ThePLTPlane() {}

    protected:
        bool update_atlas_position_for_tooltip(GYDM::IMatter* m, float x, float y);
    };
}

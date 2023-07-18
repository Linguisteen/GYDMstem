#pragma once

#include <SDL2/SDL.h>

/**
 * 为兼容 Windows 而变得丑陋
 *
 * vcpkg 不直接提供 SDL2main
 * SDL2.h 把 main 改名为 SDL_main 了
 * 导致 MSVC 连接器找不到程序入口
 *
 * 手动链接会引发别的问题，比如跟默认库冲突
 * (否则 vcpkg 作者肯定脑子有坑才会整出“手动链接”这种脱了裤子那啥的活)
 */
#ifdef main
#undef main
#endif

#include "cosmos.hpp"
#include "matter.hpp"
#include "misc.hpp"

#include "graphics/colorspace.hpp"
#include "graphics/named_colors.hpp"
#include "graphics/geometry.hpp"
#include "graphics/font.hpp"
#include "graphics/text.hpp"
#include "graphics/texture.hpp"

#include "matter/atlas.hpp"
#include "matter/continent.hpp"
#include "matter/sprite.hpp"
#include "matter/sprite/folder.hpp"
#include "matter/sprite/sheet.hpp"

#include "matter/sprite/mascot/atlas/mario.hpp"
#include "matter/sprite/mascot/atlas/planetcute.hpp"
#include "matter/sprite/mascot/agent/linkmon.hpp"
#include "matter/sprite/mascot/tuxmon.hpp"
#include "matter/sprite/mascot/coinlet.hpp"
#include "matter/sprite/mascot/character.hpp"

#include "matter/graphlet.hpp"
#include "matter/graphlet/textlet.hpp"
#include "matter/graphlet/shapelet.hpp"
#include "matter/graphlet/dimensionlet.hpp"
#include "matter/graphlet/historylet.hpp"

#include "physics/random.hpp"
#include "physics/mathematics.hpp"

#include "physics/motion/platformer.hpp"
#include "physics/motion/map2d.hpp"

#include "datum/flonum.hpp"
#include "datum/string.hpp"
#include "virtualization/filesystem/imgdb.hpp"

/*************************************************************************************************/
#define isinstance(object, Type) (dynamic_cast<Type*>(object) != nullptr)
#pragma once // 确保只被 include 一次

#include <gydm_stem/game.hpp>

#include "../../scsm.hpp"

#include <map>

namespace WarGrey::SCSM {
    enum class GameState { Auto, Stop, Edit, _ };

    /** 声明游戏宇宙 **/
    class PinholePlane : public WarGrey::SCSM::TheSCSMPlane {
    public:
        PinholePlane(float gridsize = 8.0F) : TheSCSMPlane("小孔成像") {}
        virtual ~PinholePlane() {}

    public:    // 覆盖游戏基本方法
        void load(float width, float height) override;
        void reflow(float width, float height) override;
        void update(uint64_t count, uint32_t interval, uint64_t uptime) override;
        void on_mission_start(float width, float height) override;

    public:
        bool can_select(WarGrey::STEM::IMatter* m) override;
            
    protected: // 覆盖输入事件处理方法
        void on_char(char key, uint16_t modifiers, uint8_t repeats, bool pressed) override; // 处理键盘事件
        void on_tap(WarGrey::STEM::IMatter* m, float x, float y) override;                  // 处理鼠标事件

    private:
        void load_labview(float width, float height);
        void load_instructions(float width, float height);
        void switch_game_state(WarGrey::SCSM::GameState new_state);
        void update_instructions_state(const uint32_t* colors);
        void pace_forward();
            
    private: // 游戏操作
        std::map<char, WarGrey::STEM::Labellet*> instructions;

    private:
        class Pinholet;
        WarGrey::SCSM::PinholePlane::Pinholet* labview;

    private: // 游戏状态
        WarGrey::SCSM::GameState state = GameState::_;
    };
}

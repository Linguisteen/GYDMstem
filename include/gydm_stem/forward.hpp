#pragma once

namespace WarGrey::STEM {
    class IPlane;
    class IMatter;
    class ISprite;
    class Tracklet;
    class Cosmos;
    class Continent;

    enum class MatterAnchor { LT, CT, RT, LC, CC, RC, LB, CB, RB };
    enum class SpeechBubble { Default, Thought };
    enum class BorderEdge { TOP, RIGHT, BOTTOM, LEFT, NONE };
    enum class BorderStrategy { IGNORE, STOP, BOUNCE };
    
    void matter_anchor_fraction(MatterAnchor& a, float* ofx, float* ofy);    
}

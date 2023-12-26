#pragma once

namespace WarGrey::STEM {
    enum class CIE_Standard { Primary , D65 };

    void CIE_XYZ_to_RGB(CIE_Standard type, double X, double Y, double Z, double* R, double* G, double* B, bool gamma = true);
    void CIE_RGB_to_XYZ(CIE_Standard type, double R, double G, double B, double* X, double* Y, double* Z, bool gamma = true);
    void CIE_xyY_to_XYZ(double x, double y, double* X, double* Y, double* Z, double L = 1.0);
    void CIE_XYZ_to_xyY(double X, double Y, double Z, double* x, double* y);
}

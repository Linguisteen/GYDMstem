#pragma once // 确保只被 include 一次

namespace GYDM {
    int random_raw();
    int random_uniform(int min, int max);
    unsigned int random_uniform(unsigned int min, unsigned int max);
    float random_uniform(float min, float max);
    double random_uniform(double min = 0.0, double max = 1.0);
    
    bool random_bernoulli(double p_true);
}

#include "rgb.h" 
    Rgb::Rgb(int _r=0, int _g=0,int _b=0){
        r=_r;
        g=_g;
        b=_b;
    }
    void Rgb::set_r(int _r){
        r=_r;
    }
    void Rgb::set_g(int _g){
        g=_g;
    }
    void Rgb::set_b(int _b){
        b=_b;
    }
    void Rgb::set_r_g_b(int _r,int _g, int _b){
        r=_r;
        g=_g;
        b=_b;
    }
    int Rgb::get_r(){
        return r;
    }
    int Rgb::get_g(){
        return g;
    }
    int Rgb::get_b(){
        return b;
    }
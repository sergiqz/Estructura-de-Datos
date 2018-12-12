#ifndef RGB_H
#define RGB_H

using namespace std;

class Rgb{
  private:
    int r; 
    int g;
    int b; 
  public:  
    Rgb(int _r=0, int _g=0,int _b=0){
        r=_r;
        g=_g;
        b=_b;
    }
    void set_r(int _r){
        r=_r;
    }
    void set_g(int _g){
        g=_g;
    }
    void set_b(int _b){
        b=_b;
    }
    void set_r_g_b(int _r,int _g, int _b){
        r=_r;
        g=_g;
        b=_b;
    }
    int get_r(){
        return r;
    }
    int get_g(){
        return g;
    }
    int get_b(){
        return b;
    }

};

#endif 
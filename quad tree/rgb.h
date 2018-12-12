#ifndef RGB_H
#define RGB_H

using namespace std;

class Rgb{
  private:
    int r; 
    int g;
    int b; 
  public:  
    Rgb(int _r, int _g,int _b);
    void set_r(int _r);
    void set_g(int _g);
    void set_b(int _b);
    void set_r_g_b(int _r,int _g, int _b);
    int get_r();
    int get_g();
    int get_b();
};

#endif 
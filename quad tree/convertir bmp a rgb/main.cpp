#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <iostream>

#include <sstream>
#include <fstream>
using namespace cv;
using namespace std;

int imprimirrgv(int** array_R, int** array_G, int** array_B, int row , int col){
    for(int i=0; i <row; i++){
        for(int j=0;j<col;j++){
           cout<<array_R[i][j]<<","<<array_G[i][j]<<","<<array_B[i][j]<<endl;
        }
    }
}

void crearmatrix( int ** &matrix, int row, int col){
    matrix= new int*[row];
    for(int i=0;i<row;i++){
        matrix[i]=new int[col];
    }

}

void textorgb(int** array_R, int** array_G, int** array_B,int row,int col, string ruta){
    ofstream outfile(ruta.c_str());
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            outfile<<array_R[i][j]<<","<<array_G[i][j]<<","<<array_B[i][j]<<endl;
        }
    }
    outfile.close();
}



int main()
{

Mat image = imread("mitad.bmp");
Vec3b buf;
int** array_B;
int** array_G;
int** array_R;
crearmatrix(array_B,image.rows,image.cols);
crearmatrix(array_G,image.rows,image.cols);
crearmatrix(array_R,image.rows,image.cols);

//int array_B[image.rows][image.cols];
//int array_G[image.rows][image.cols];
//int array_R[image.rows][image.cols];

for(int i = 0; i < image.rows; i++)
    for(int j = 0; j < image.cols; j++)
    {
        buf = image.at<Vec3b>(i,j);
        array_B[i][j] = buf[0];
        array_G[i][j] = buf[1];
        array_R[i][j] = buf[2];
    }
//imwrite("C:/.../image2.jpg",image3);

imprimirrgv(array_R,array_G,array_B,image.rows,image.cols);

textorgb(array_R,array_G,array_B,image.rows,image.cols,"mitad.txt");




imshow("Image",image);
waitKey(0);
}

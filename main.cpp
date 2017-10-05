//Request file name from user
//Search directory for file name and load file into program
/*Convert bitmap image into a vector matrix
    -Create matrix with size rows of pixels x columns of pixels */
/*Create Loop That:
  -Gets RGB values of each pixel then get the average of all three values
  -Inserts the average of the values into the RGB values of the pixel*/
//Save file to computer as oldtimey.bmp

#include <iostream>
#include <vector>
#include "bitmap.h"
using namespace std;
const int RGB_3 = 3;
int main()
 {
  Bitmap image;
  vector <vector <Pixel> > bmp;
  Pixel rgb;
  image.open("tiger.bmp");
  bmp = image.toPixelMatrix();
  int rows = 0;
  int columns = 0;
    for(int i = 0; i <bmp.size(); i++)
      {
        rows = rows + 1;
          for(int x = 0; x < bmp[i].size(); x++)
          {
            columns = columns + 1;
          }
      }
      cout << rows << endl << columns << endl;
    if(image.isImage())
     {
      for(int i = 0; i <rows; i++)
        {
          for(int j = 0; j <columns; j++)
           {
              rgb = bmp[i][j];
              int greyScale = (rgb.red +rgb.green +rgb.blue) / RGB_3;
              rgb.red = greyScale;
              rgb.green = greyScale;
              rgb.blue = greyScale;
              bmp[i][j] = rgb;  
           }

         }         
     }
      else
     {
       cout << "Invalid Image" << endl; 
     }
  image.fromPixelMatrix(bmp);
  image.save("oldtimey.bmp"); 
  
  return 0;

}
    


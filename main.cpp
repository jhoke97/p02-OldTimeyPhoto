#include <iostream>
#include <vector>
#include <string>
#include "bitmap.h"
#include <stdlib.h>
#include <time.h>

using namespace std;
const int RGB_3 = 3;
const int GRAIN_RATIO = 25; //The lower this number the more grain will be added
int main()
 {
  srand (time(NULL));

  bool isImage;
  bool validImage = false;
  string fileName;
  Bitmap image;
  vector <vector <Pixel> > bmp;
  Pixel rgb;

  cout << "Enter filename of BMP image" << endl;
  cin >> fileName;
  image.open(fileName);

  //Check if image is valid
   if(image.isImage())
    {
     validImage = true;
    }
   if(validImage == false)
    {
     do{
        cout << "Invalid filename. Enter filename of a BMP image\n";
        cin >> fileName;
        image.open(fileName);
         if(image.isImage())
           {
             validImage = true;
           }
        }while(validImage == false);
   }
  bmp = image.toPixelMatrix();

  //convert image to greyscale
      for(int i = 0; i <bmp.size(); i++)
        {
          for(int j = 0; j <bmp[i].size(); j++)
          { int grainGenerator = rand() % GRAIN_RATIO + 1;
            if(grainGenerator  == GRAIN_RATIO) // Adds grain to photo
             {
               rgb = bmp[i][j];
               rgb.red = 1;
               rgb.green = 1;
               rgb.blue = 1;
               bmp[i][j] = rgb;
             }else
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
  if(image.isImage())
   {
    image.fromPixelMatrix(bmp);
    image.save("oldtimey.bmp");
   }else{
    cout << "invalid image" << endl;
   }
 return 0;
}

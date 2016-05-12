#ifndef Image_h
#define Image_h

#include "Array.h"
#include "Vec3.h"
#include "Serializable.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <string>

using namespace std;
using namespace math;

class Image:public Array<Vec3 <float> >,public Serializable{
    
public:
    
    Image(unsigned int w, unsigned int h):Array(w,h){
        
    }
    
    virtual bool operator << (string filename) {
        
        ifstream img (filename);
        
        if(!img){
            cerr<<"Error opening file \n";
            return false;
        }
        
        string str;
        img >> str; //Read P6
        cout << "Format: " << str << endl;
        
        if (str != "P6"){
            cerr << "Not P6 format!" << endl;
            return false;
        }
        
        istringstream iss_width;
        istringstream iss_height;
        istringstream iss_maxbr;
        
        img >> str;
        iss_width.str(str);
        iss_width >> width;
        
        img >> str;
        iss_height.str(str);
        iss_height >> height;
        
        img >> str;
        int maxbr;
        iss_maxbr.str(str);
        iss_maxbr >> maxbr;
        
        img.ignore(1,'\n');
        
        resize(width, height);
        
        
        
        if (img)
        {
            char red, green, blue;
            // Gia kathe ena apo ta [height x width] pixels, diavase tis rgb times
            for (int h = 0; h < height; h++){
                for (int w = 0; w < width; w++){
                    img.get(red);
                    img.get(green);
                    img.get(blue);
                    
                    Vec3<float> color((unsigned char) red/255.0, (unsigned char) green/255.0, (unsigned char) blue/255.0);
                    Image& myimage = *this;
                    //x=grami, y=stili
                    myimage((unsigned int)w, (unsigned int)h) = color;
                    
                    
                }
            }
            
        }
        img.close();
        
       
        
        
        
        return true;
    }
    
    virtual bool operator >> (string filename) {
        return true;
    }
    
    
    
    
    
};


#endif

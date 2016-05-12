#include <iostream>

#include "Image.h"


int main(int argc, const char * argv[]) {
    
    string filename;
    cout<<argv[0];
    
    if (argc == 1){
        cout << "File name of the image to load: ";
        cin >> filename;
    }
    else
        filename.assign(argv[1]); // string& assign (const char* s);
    
    Image image(0, 0);
    image << filename;
    cout<<"Image dimensions are: "<<image.getWidth()<<" x "<<image.getHeight()<<endl;
    
    Vec3<float> sum(0,0,0),average(0,0,0);
    
    for (int i=0;i<image.getWidth();i++){
        for (int j=0;j<image.getHeight();j++){
            sum=sum+image(i,j);
            
        }
    }
    
    average=sum/(image.getWidth()*image.getHeight());
    cout<<"The average color of the image is: " <<average[0]<<","<<average[1]<<","<<average[2];
    return 0;
}

#include <iostream>
#include <fstream>
#include <string>
#include <QImage>

using namespace std;

int main(){
    string filename = "imagen.jpg";
    QImage im(filename.c_str());
    im = im.scaled(8,8);
    string R = "{";
    string G = "{";
    string B = "{";

    for(int j = 0; j < 8; j++){
        for(int i = 0; i < 8; i++){
            R += to_string(im.pixelColor(i,j).red());
            G += to_string(im.pixelColor(i,j).green());
            B += to_string(im.pixelColor(i,j).blue());
            if(j == 7 && i == 7){
                R += "}";
                G += "}";
                B += "}";
            }else{
                R += ", ";
                G += ", ";
                B += ", ";
            }
        }
    }

    ofstream fout;
    fout.open("copiar.txt");
    fout << "//Pegue el siguiente codigo en tinkercad" << endl << endl;
    fout << "byte arr[3][64]{" << endl;
    fout << "\t" << R << "," << endl;
    fout << "\t" << G << "," << endl;
    fout << "\t" << B << endl;
    fout << "};" << endl;
    fout.close();

    return 0;
}

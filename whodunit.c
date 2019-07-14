#include <stdio.h>
#include "bmp.h"
#include <stdlib.h>


int main(int argc, char *argv[]){
     char *inFile = argv[1];
     char *outFile = argv[2];

     if (argc != 3){
         fprintf(stderr, "Usage: ./whodunit infile outfile\n");
         return 1;
     }

    //Create variable for opening the input file.
    FILE *inptfle = fopen(inFile, "r");
    if (inptfle == NULL){
        fprintf(stderr, "Input file not found.\n");
        return 2;
    }

    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptfle);
    if (bf.bfType != 19778){
        fprintf(stderr, "This is not a valid BMP file.");
        return 5;
    }

    BITMAPINFOHEADER bfi;
    fread(&bfi, sizeof(BITMAPINFOHEADER), 1, inptfle);
    if(bfi.biBitCount != 24){
        fprintf(stderr, "This is not a 24Bit BMP File.\n");
        return 4;
    }else if (bfi.biCompression != 0){
        fprintf(stderr, "This is not an uncompressed BMP file.\n");
        return 4;
    }

    //Create file for writing
    FILE *ouptfle = fopen(outFile, "w+");
    if (ouptfle == NULL){
        fprintf(stderr, "Output file cannot be created.\n");
        return 6;
    }

    //Write to file the reuqired header info.
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, ouptfle);
    fwrite(&bfi, sizeof(BITMAPINFOHEADER), 1, ouptfle);

    RGBTRIPLE rgbt;
    for(int i = 0, biTimes = abs(bfi.biHeight) * bfi.biWidth; i < biTimes; i++){
            fread(&rgbt, sizeof(RGBTRIPLE), 1, inptfle);
            if(rgbt.rgbtBlue == 255 && rgbt.rgbtGreen == 255 && rgbt.rgbtRed == 255){
                rgbt.rgbtBlue = 0;
                rgbt.rgbtGreen = 0;
                rgbt.rgbtRed = 255;
            }
            fwrite(&rgbt, sizeof(RGBTRIPLE),1, ouptfle);
    }
    fclose(ouptfle);

    return 0;
}
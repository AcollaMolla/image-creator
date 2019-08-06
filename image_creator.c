#include <stdio.h> 
int main(){
	//Settings for the image, ie height, width and iterators
	int width = 10, input, i, j, pixel;
	int height = 10;
	//The actual image data. Will create a horizontal striped monochromatic image
	int image[10][10]  = {
		{0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1},
		{0,0,0,0,0,0,0,0,0,0},
		{1,1,1,1,1,1,1,1,1,1},	
	};
	//Initialize file handler
	FILE* image_file;
	image_file = fopen("pbmimg.pbm", "wb");
	
	//Begin writing to file
	//Write magic number to beginning of file
	fprintf(image_file, "P1\n");
	//Write width and height for the image
	fprintf(image_file, "%d %d\n", width, height);
	for(i=0;i<height;i++){
		for(j=0;j<width;j++){
			//Determine the color value of a single pixel based on the 'image' 2D array above
			pixel = image[i][j];
			//Write single pixel to the image
			fprintf(image_file, "%d", pixel);
		}
	}
	//Close file stream
	fclose(image_file);
	
	return 0;
}
#include <stdio.h> 
#include <stdlib.h>
void createImage(){
		//Settings for the image, ie height, width and iterators
	int width = 10, input, i, j, pixel;
	int height = 10;
	//The actual image data. Will create a horizontal striped monochromatic image
	int image[10][10];
	for(i=0;i<10;i++){
		for(j=0;j<10;j++){
			image [i][j] = rand() % 2;
		}
	}
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
}
int main(){
	int choice;
	do{
		printf("1. Generate image");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Creating image\n");
				createImage();
			break;
			default:
				printf("Illegal command");
			break;
		}
	}while(choice != 0);
	return 0;
}
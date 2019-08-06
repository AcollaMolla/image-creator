#include <stdio.h> 
#include <stdlib.h>
void createImage(int width, int height){
	int i, j;
	//Calculate the number of pixels needed
	int pixels = width * height;
	int *image = malloc(pixels * sizeof(int));
	for(i=0;i<pixels;i++){
		image [i] = rand() % 2;
	}
	//Initialize file handler
	FILE* image_file;
	image_file = fopen("pbmimg.pbm", "wb");
	
	//Begin writing to file
	//Write magic number to beginning of file
	fprintf(image_file, "P1\n");
	//Write width and height for the image
	fprintf(image_file, "%d %d\n", width, height);
	for(i=0;i<pixels;i++){
			//Write single pixel to the image
			fprintf(image_file, "%d", image[i]);
	}
	//Close file stream
	fclose(image_file);
}
int main(){
	int choice, width, height;
	do{
		printf("1. Generate image\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter width for image: ");
				scanf("%d", &width);
				printf("Enter height for image: ");
				scanf("%d", &height);
				printf("Creating image\n");
				createImage(width, height);
			break;
			default:
				printf("Illegal command");
			break;
		}
	}while(choice != 0);
	return 0;
}
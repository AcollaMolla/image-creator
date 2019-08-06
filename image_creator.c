#include <stdio.h> 
#include <stdlib.h>
void createRandomImage(int width, int height){
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
void createHorizontallyStripedImage(width, height){
	int pixels = width * height, i, color = 1;
	int *image = malloc(pixels * sizeof(int));
	for(i=0;i<pixels;i++){
		image[i] = color;
		if((i+1)%width == 0){
			if(color == 1){
				color = 0;
			}
			else if(color == 0){
				color = 1;
			}
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
	for(i=0;i<pixels;i++){
			//Write single pixel to the image
			fprintf(image_file, "%d", image[i]);
	}
	//Close file stream
	fclose(image_file);
}
void compress(){
	int image[9] = {1,1,1,0,0,0,1,1,1}, i, temp = image[0], count = 0;
	for(i=0;i<9;i++){
		if(image[i] != temp || i == 8){
			if(i == 8){
				count++;
			}
			printf("%d %d\n", count, temp);
			count = 1;
			temp = image[i];
		}
		else if(image[i] == temp){
			count++;
		}
	}
	printf("\n");
}
int main(){
	int choice, width, height;
	do{
		printf("1. Generate random image\n");
		printf("2. Generate horizontally striped image\n");
		printf("3. Compress generic image\n");
		scanf("%d", &choice);
		switch(choice){
			case 1:
				printf("Enter width for image: ");
				scanf("%d", &width);
				printf("Enter height for image: ");
				scanf("%d", &height);
				printf("Creating image\n");
				createRandomImage(width, height);
			break;
			case 2:
				printf("Enter width for image: ");
				scanf("%d", &width);
				printf("Enter height for image: ");
				scanf("%d", &height);
				printf("Creating image\n");
				createHorizontallyStripedImage(width, height);
			break;
			case 3:
				compress();
			break;
			default:
				printf("Illegal command");
			break;
		}
	}while(choice != 0);
	return 0;
}
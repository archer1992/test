#include <stdio.h>
#include <math.h>
double main(){
	double e[1000];  //initialize the array for the input txt
	int N; //length of the input

	double y[3]; // initialize the output y(0) up to y(2)
	y[0] = 0;
	y[1] = 0;
	y[2] = 0;
	
	int i; int j; // for looping
	FILE *input_file = fopen("in.txt","r"); //opens the input.txt file
	
	if (input_file==NULL){ //checks if the input file is present in the current directory
		printf("There's no in.txt file from the directory.");
		return 1;
	}
    N = 0;
	   for (j=0;!feof(input_file);j++)
    	{
        fscanf(input_file, "%lf", &e[j]); //encodes the number per line of the in.txt into the array
        N = N+1; //counts the number of lines of in.txt
		}
		
	fclose(input_file); //closes the in.txt
	
	FILE *output_file = fopen("out.txt","w"); //writes the output.txt file
    for (i=0;i<N-1;i++)
    {
		y[i+2] = 0.9891*e[i+2] - 1.8403*e[i+1] + 0.9891*e[i] + 1.8403*y[i+1] - 0.9783*y[i]; //the difference equation
		fprintf(output_file,"%lf\n", y[i]); // starts saving the output y(k) to the out.txt file
		
    }

    fclose(output_file); //closes the out.txt

}


#include <stdio.h>
#include <math.h>

#include <stdlib.h>

double m_avg(double buffer[], int avg_size, double new_item);



int main(){
	int i, bufferSize;
	char anotherVal;

	double newValue, avgValue;
	
	printf("Enter the size of the buffer: ");
	scanf("%d", &bufferSize);
	
	double buffer[bufferSize];
	
	for(i = 0; i < bufferSize; i++){
		printf("\nEnter the value for place %d: ", i);
		scanf("%lf", &buffer[i]);
	}
	
	
	
	
	
	while (1){
		
		printf("\nEnter a new value: ");
		scanf("%lf", &newValue);
	
		avgValue = m_avg(buffer, bufferSize, newValue);
	
		printf("\nThe average value is: %.4f", avgValue);
		
		printf("\nEnter another value? y/n: ");
		scanf("%c", &anotherVal);
		
		if(anotherVal == 'n'){
			break;
		}
	}
	
	return 0;
}


double m_avg(double buffer[], int avg_size, double new_item)
{
	int i;
	double sum;
	
	for(i = avg_size - 1; i > 0; i--){
		buffer[i] = buffer[i-1];
	}
	buffer[0] = new_item;
	
	for(i = 0; i < avg_size; i++){
		sum += buffer[i];
	}
	
	return (sum / avg_size);
}

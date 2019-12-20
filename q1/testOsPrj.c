#include<stdio.h> 
#include<stdlib.h> 
#include<unistd.h> 
#include<sys/types.h> 
#include<string.h> 
#include<sys/wait.h> 

int main() 
{ 
	// We use two pipes 
	// First pipe to send input number from parent 
	// Second pipe to send concatenated string and result from child 

	int pipe1[2]; // Used to store two ends of first pipe 
	int pipe2[2]; // Used to store two ends of second pipe 

	char fixed_str[] = " The sum of even digits in the input number:"; 
	char input_str[100]; 
	pid_t p; 

	// Pipe1 failed
	if (pipe(pipe1)==-1) 
	{ 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	} 
	// Pipe2 failed
	if (pipe(pipe2)==-1) 
	{ 
		fprintf(stderr, "Pipe Failed" ); 
		return 1; 
	} 

	
	p = fork(); 

	// Fork failed
	if (p < 0) 
	{ 
		fprintf(stderr, "fork Failed" ); 
		return 1; 
	} 

	// Parent process 
	else if (p > 0) 
	{ 
		printf("I am parent , please enter your number : \n");
		scanf("%s", input_str); 
		char concat_str[100]; 

		close(pipe1[0]); // Close reading end of first pipe 

		// Write input string and close writing end of first pipe
		write(pipe1[1], input_str, strlen(input_str)+1); 
		close(pipe1[1]); 

		// Wait for child to send a string 
		wait(NULL); 

		close(pipe2[1]); // Close writing end of second pipe 

		// Read string from child, print it and close 
		// reading end. 
		read(pipe2[0], concat_str, 100); 
		printf("%s\n", concat_str); 
		close(pipe2[0]); 
	} 

	// child process 
	else
	{ 
		close(pipe1[1]); // Close writing end of first pipe 

		// Read a string using first pipe 
		char concat_str[100]; 
		read(pipe1[0], concat_str, 100); 
		
		// Calculate the sum
		int total = atoi(concat_str);
		int sum = 0;
		for( ; total > 0; total /= 10){
			if (total % 2 == 0){
				sum += total % 10;
			}
		}
		

		// Concatenate a fixed string with it 
		int k = strlen(concat_str); 
		int i; 
		for (i=0; i<strlen(fixed_str); i++) 
			concat_str[k++] = fixed_str[i]; 

		// Concatenate the sum 
		int length = snprintf( NULL, 0, "%d", sum );
		char* sum_str = malloc( length + 1 );
		snprintf( sum_str, length + 1, "%d", sum );
		for (int j = 0 ; j < length ; j++)
			concat_str[k++] = sum_str[j];

		concat_str[k] = '\0'; // string ends with '\0' 

		// Close both reading ends 
		close(pipe1[0]); 
		close(pipe2[0]); 

		// Write concatenated string and close writing end 
		write(pipe2[1], concat_str, strlen(concat_str)+1); 
		close(pipe2[1]); 

		exit(0); 
	} 
} 


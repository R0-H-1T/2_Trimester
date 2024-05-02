#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MOVIE_SIZE 128

int check[10];

struct Movie {
	int movie_id;
	char movie_name[MOVIE_SIZE];
	float movie_rating;
};
typedef struct Movie Movie;

struct List {
	Movie m;
	struct List *next;
};
typedef struct List List;


Movie *getMovie (int *count) {
	Movie *newmovie = (Movie*) malloc (sizeof(Movie));
	
	printf("\nEnter movie details.\n");
	
	printf ("Enter movie id: ");
	scanf ("%d", &newmovie->movie_id);
	getchar();
	
	if (newmovie->movie_id < 0 || newmovie->movie_id >9){
		fprintf (stderr, "\nRange is from 0-10...\nExiting...");
		exit(EXIT_FAILURE);
	}
	
	if (*count <= 10 ){
		int i;
		for (i=0; i<10; i++) {
			if (check[i] == newmovie->movie_id){
				fprintf (stderr, "\nCannot contain duplicates...\nExiting...");
				exit(EXIT_FAILURE);
			}
		}
		check[*count] = newmovie->movie_id;
		count++;
	}
	
	
	char movie_name[MOVIE_SIZE];
	printf ("Enter movie name: ");
	//scanf("%s", newmovie->movie_name);
	fgets (movie_name, MOVIE_SIZE, stdin);

	strcpy(newmovie->movie_name, movie_name);
	
	printf ("Enter movie rating: ");
	scanf ("%f", &newmovie->movie_rating);
	getchar();
	
	return newmovie;
}

List *getNode (int *count) {
	Movie *m = getMovie(count);
	List *new_node = (List*) malloc (sizeof(List));
	
	new_node->m = *m;
	new_node->next = NULL;
	
	return new_node;
}




List* createList (int *count) {
	List *newnode = getNode (count);
	
	
	char ch;
	printf ("Enter another movie? (y/n): ");
	scanf("%c", &ch);
	getchar();
	if (ch == 'y'){
		newnode -> next = createList(count);
	}
	
	return newnode;
}


void printMovie (List *temp) {

	printf ("\nMovie Id\tMovie Rating\tMovie Name");
	printf("\n---------------------------------------------------");
	while (temp != NULL) {
		printf ("\n%d", temp->m.movie_id);
		printf ("\t\t%.1f", temp->m.movie_rating);
		printf ("\t\t%s", temp->m.movie_name);
		
		
		temp = temp->next;
	}
}

int getLength(List *temp) {
	int count = 0;
	
	while(temp != NULL) {
		count ++;
		temp = temp->next;
	}
	
	return count;
}

int* getMovieIds (List *head, int len) {
	List *temp = head;
	
	int *arr = (int*) malloc (sizeof(int) * len);
	
	int i;
	for (i=0; temp != NULL; i++){
		arr[i] = temp->m.movie_id;
		temp = temp->next;
	}
	
	return arr;

}


void printArr (int *arr, int n) {
	
	printf("\n\nDisplaying sorted array: ");
	int i;
	for (i=0; i<n; i++) {
		printf ("%d ", arr[i]);
	}
}


void insertion_sort (int *arr, int n) {
	printArr (arr, n);
	
	int i;
	for (i=0; i<n-1; i++) {
		int j = i+1;
		int num = arr[j];
		
		while (j>0 && num < arr[j-1]) {
			arr[j] = arr[j-1];
			arr[j-1] = num;
			j--;
		}
	}
}

int main() {
	int count = 0;
	List *head = createList (&count);
	
	printf("\nDisplaying movies:");
	printMovie(head);
	
	int len = getLength(head);
	int *arr = getMovieIds(head, len);
	
	printArr(arr, len);	
	insertion_sort(arr, len);
	printArr(arr, len);

	return 0;	
}


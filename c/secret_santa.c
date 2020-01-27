#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>


void char2hex(char c, char out[]);
void knuth_fisher_yates_shuffle(int array[], int len);
int pick_random(int from);
void generate_derangement(int arr[], int len);
int * integer_array_duplicate(int arr[], int len);
int reject_derangement(int arr[], int compare[], int len);
void print_int_array(int arr[], int len);
void print_hidden_name(char name[]);  


////////////////////////////////////////
int main(){

  ////////////////////////////////////////
  // 0: init. random number generator
  ////////////////////////////////////////
  srand(67825);

  ////////////////////////////////////////
  // 1: init. words, names
  ////////////////////////////////////////
  int num_words = 18;
  const char * w[num_words];
  w[0] = "sweet";
  w[1] = "small";
  w[2] = "many";  
  w[3] = "brown";
  w[4] = "rectangular";
  w[5] = "wooden";
  w[6] = "flat";
  w[7] = "deep";
  w[8] = "flashy";
  w[9] = "furry";
  w[10] = "spicy";
  w[11] = "magical";
  w[12] = "round";
  w[13] = "foreign";
  w[14] = "striped";
  w[15] = "orange";
  w[16] = "square";  
  w[17] = "fruity";
  
  int num_people = 6;
  const char * p[num_people];
  p[0] = "Nastja B.";
  p[1] = "Nastja L.";
  p[2] = "Dima A.";
  p[3] = "Katia";
  p[4] = "Artem";
  p[5] = "Dim";

  ////////////////////////////////////////
  // 2: prepare random numbers
  ////////////////////////////////////////
  int people_order[num_people];
  for(int i = 0; i < num_people; ++i)
    people_order[i] = i;

  knuth_fisher_yates_shuffle(people_order, num_people);
  knuth_fisher_yates_shuffle(people_order, num_people);  

  int word_order[num_words];
  for(int i = 0; i < num_words; ++i)
    word_order[i] = i;

  knuth_fisher_yates_shuffle(word_order, num_words);
  knuth_fisher_yates_shuffle(word_order, num_words);  


  ////////////////////////////////////////
  // 3: assign words -> people
  ////////////////////////////////////////
  for(int i = 0; i < num_people; ++i){
    printf("[%s]\t\t", p[people_order[i]]);
    for(int j = 0; j < 3; ++j){

      int pick_word = word_order[3*i+j];
      char out[2];
      char word[20];
      strcpy(word, w[pick_word]);
      int wlen = 0, ll = 0, c;

      while((c = word[ll]) != '\0')
	wlen++, ll++;

      for(int k = 0; k < wlen; ++k){
	char2hex(word[k], out);
	printf("%s", out);
      }
      printf("%X", ' ');
    }
    printf("\n");
  }

  ////////////////////////////////////////
  // Bonus: play secret santa
  ////////////////////////////////////////
  
  srand(2357);
  int * temp = integer_array_duplicate(people_order, num_people);
  generate_derangement(people_order, num_people);

  for(int i = 0; i < num_people; ++i)
    assert(people_order[i] != temp[i]);

  for(int l = 0; l < num_people; ++l){
    
    char name[20];
    strcpy(name, p[people_order[l]]);
    printf("Person [%s]: ", p[temp[l]]);
    print_hidden_name(name);
    printf("\n");
  }

  return 0;

}


/* Function: knuth_fisher_yates_shuffle
 * ----------------------------------------
 * this function illustrates a known pattern in C
 * the array passed :param original: cannot be 
 * identified for it's size
 * the above is related to the property of C 
 * that says; C is not a reflective language
 * objects do not know what they are
 */
void knuth_fisher_yates_shuffle(int arr[], int len){

  printf("Begin KFY shuffle on arr array of size [%d] \n", len);
  for(int i = len - 1; i >= 1; --i){

    int j = rand() % (i+1);
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    
  }

}


/* Function: generate_derangement
 * ----------------------------------------
 * this function uses rejection sampling to 
 * simulate derangement i.e. for a set A of n
 * elements, all permutations s.t. P(a_i) != a_i
 */
void generate_derangement(int arr[], int len){

  int state = 1;
  int * temp = integer_array_duplicate(arr, len);

  while(state){
    knuth_fisher_yates_shuffle(arr, len);
    state = (reject_derangement(arr, temp, len)) ? 1: 0;
    printf("State = [%d] \n", state);
  }

}


////////////////////////////////////////
int * integer_array_duplicate(int arr[], int len){

  int * duplicate_array = malloc(sizeof(int) * len);
  memcpy(duplicate_array, arr, sizeof(int) * len);

  return duplicate_array;

}



////////////////////////////////////////
int reject_derangement(int arr[], int compare[], int len){

  for(int i = 0; i < len; ++i)
    if(arr[i] == compare[i])
      return 1;

  return 0;

}


////////////////////////////////////////
void print_hidden_name(char name[]){

  char out[2];
  int wlen = 0, ll = 0, c;
  int mask_len = 64 - wlen;
  while((c = name[ll]) != '\0')
    wlen++, ll++;

  for(int k = 0; k < wlen; ++k){
    char2hex(name[k], out);
    printf("%s", out);
  }
  
  printf("%X", ' ');    
  printf("%X", '=');    
  printf("%X", ')');    
  printf("%X", ' ');    

  for(int i = 0; i < mask_len - 2; ++i){
    printf("%X", rand() % 64);
  }

}


////////////////////////////////////////
void print_int_array(int arr[], int len){

  for(int i = 0; i < len; ++i)
    printf("%d ", arr[i]);
  printf("\n");
}


////////////////////////////////////////
int pick_random(int from){

  return rand() % from;

}


////////////////////////////////////////
void char2hex(char c, char out[]){

  char possible_values[] = "0123456789ABCDEF";

  out[2] = '\0';
  for(int i = 1; c != 0; --i){
    out[i] = possible_values[c % 16];
    c /= 16;
  }
  
}

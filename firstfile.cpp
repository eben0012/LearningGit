#include<iostream>
/*
takes an int num and raises it to the power expo, then returns
the new number as an unsigned long int ie. power(2,3) returns 8
*/
unsigned long int power(int num, int expo){
    int mult = num;
    //all numbers raised to the power 0 equal 1
    if(expo == 0) return 1;
    for(int i = 1; i < expo; i++){
        num *= mult;
    }
    return num;
}
//takes an array and does the number rotation from first to last
int circ(unsigned int num, int counter){
    int firstdig = num % 10;
    num /= 10;
    for(int i = 1; i < counter; i++){
        firstdig *= 10;
    }
    firstdig += num;
    return firstdig;
}
/*
takes in a number and test whether it is prime or not
*/
bool is_prime(unsigned int num){
    //test to see if number is prime or not
    bool prime = true;
    //checks from 1 less than a num to 2 to see if num is a prime
    for(int i = num-1; i > 1; i--){
        if(num % i == 0){
            prime = false;
            break;
        }
    }
    return prime;
}
/*
function takes a char array and returns its length
*/
int strlength(const char *str){
    int i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}
/*
function converts a hex number into its respective value in decimal
eg. if given 'A' convert will return 10, if given '3' it will
return 3.
*/
int convert(const char *hexval, int index){
    const char hex[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    const int hexnum[16] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    for(int i = 0; i < 16; i++){
        if(hexval[index] == hex[i]){
            return hexnum[i];
        }
    }
    return 0;
}
/*
takes an empty function and an int as parameters and turns
the int into separate chars stored inside arr2 ie. num = 124
will result in arr2 = {'1','2','4','\0'}
*/
void int2char(int num, char* arr2){
    int counter, trash;
    trash = num;
    //var to store the number of digits in number "n"
    counter = 0;
    // finds the length of number n
    while(trash >= 1){
        trash = trash/10;
        counter++;
    }
    trash = num;
    //array to store the separated decimal values of num
    char done[counter+1];
    //if num = 00, return arr2 as {'0','\0'}, a single zero
    if(counter == 0){
        arr2[0] = '0';
        arr2[1] = '\0';
        return;
    }
    for(int i = counter-1; i >= 0; i--){
      int last = trash % 10;
      //changes the decimal value into a char
      char add = last+'0';
      //adds new char to array
      done[i] = add;
      //move on to next value
      trash = (trash - last) / 10;
    }
    //mark end of done with a null char
    done[counter] = '\0';
    //copies new char array onto onto the non-local
    //char array arr2
    for(int i = 0; i < strlength(done); i++){
        arr2[i] = done[i];
    }
    //mark new end of arr2
    arr2[counter] = '\0';
}
/*
creates a substring from str starting at str[start] and extending
"length" units long. The resulting substr is stored in char array sub
*/
void sub_str(const char *str, char *sub, int start, int length){
    for(int i = 0; i < length; i++){
        sub[i] = str[start+i];
    }
    sub[length] = '\0';
}
/*
modification of sub_str that makes a sub string from a char array str instead
of a const char array
*/
void sub_str2(char *add, char *sub, int start, int length){
    for(int i = 0; i < length; i++){
        sub[i] = add[start+i];
    }
    sub[length] = '\0';
}
/*
takes a char array sub and a const char array pattern
and checks whether substring matches pattern in a certain
location
*/
bool patt_check(char *sub, const char *pattern){
    bool same = true;
    for(int i = 0; i < strlength(pattern); i++){
        if(sub[i] != pattern[i]){
            return false;
        }
    }
    return same;
}
/*
takes two char arrays and checks whether they are the same
*/
bool same_str(char *str1, char *str2){
    bool same = true;
    for(int i = 0; i < strlength(str2); i++){
        if(str1[i] != str2[i]){
            return false;
        }
    }
    return same;
}
/*
takes a char array and removes all instances of '.' from the
array
*/
void remove_dots(char *arr){
    //temporary array on the heap to store edits made to arr
    char* tempA = new char[strlength(arr)+1];
    int counter = 0;
    //copies arr without any '.' to tempA
    for(int i = 0; i < strlength(arr); i++){
        if(arr[i] != '.'){
            tempA[counter] = arr[i];
            counter++;
        }
    }
    tempA[counter] = '\0';
    //copies the newly edited array back on to the
    //original
    for(int j = 0; j <= strlength(tempA); j++){
        arr[j] = tempA[j];
    }
    //remove the temporary array
    delete[] tempA;
}
/*
takes an array and changes all the uppercase letters in it to lowercase letters
*/
void toLower(char *arr){
    char AlphUp[27] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    char AlphLo[27] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
    for(int i = 0; i < strlength(arr); i++){
        for(int j = 0; j < 26; j++){
            if(arr[i] == AlphUp[j]){
                arr[i] = AlphLo[j];
                break;
            }
        }
    }
}
/*
Takes a char array and removes all elements from a '+' present
up to but not including the first '@' encountered. Changes nothing
if there is no '+' present.
*/
void chop(char* arr){
    //vars to store the indexes of '+' and '@' when theyre found
    int plusloc, atloc = 0;
    //will track whether the address contains a '+' character
    bool exists = false;
    //if it exists, finds the + marking the start of the
    //part of the addres which can be chopped out
    for(int i = 0; i < strlength(arr); i ++){
        if(arr[i] == '+'){
            plusloc = i;
            exists = true;
            //exits once the first '+' is found, in case there are multiple present
            break;
        }
    }
    //if there is no + in the address, exits the function
    if(exists == false){
        return;
    }
    //finds the index of the @ marking the end of the disposable area
    for(int i = 0; i < strlength(arr); i++){
        if(arr[i] == '@'){
            atloc = i;
            break;
        }
    }
    //this will overwrite the removable section of the
    //address using the tail end past the '@' character
    //effectively removing it entirely
    int counter = plusloc;
    for(int j = atloc; j <= strlength(arr); j++){
        arr[counter] = arr[j];
        counter++;
    }
}
/*
=====================|
question 1 sort_three|
=====================|
*/
void sort_three(int a, int b, int c, int *list){
    if(a>=b && a>=c){
        list[0] = a;
        if(b>=c){
            list[1] = b;
            list[2] = c;
        }
        else {
            list[1] = c;
            list[2] = b;
        }
    }
    else if(b>=a && b>=c){
        list[0] = b;
        if(a>=c){
            list[1] = a;
            list[2] = c;
        }
        else {
            list[1] = c;
            list[2] = a;
        }
    }
    else if(c>=b && c>=a){
        list[0] = c;
        if(b>=a){
            list[1] = b;
            list[2] = a;
        }
        else {
            list[1] = a;
            list[2] = b;
        }
    }
}
/*
======================|
question 2 unique_sums|
======================|
*/
long int unique_sums(const int *A, unsigned int n, unsigned int k){
    // i = 0 -> 1 -> 2
    /*for(int i = 0; i <= (n-k); i++){
        //tempA = {3,-2,-1,2} -> {-2,-1,2} -> {-1,2}
        int* tempA = new int[n-i];
        int index = 0;
        for(int j = i; j < n; j++){
            tempA[index] = A[j];
            index++;
        }
        //index = max index of tempA
        //length tempA = index+1
        //function to work on each shorter function and stuff
        int Alen = index+1;
        for(int z = 1; z < (Alen-k); z++){
        }
        delete[] tempA;
    }*/
    return 0;
}
/*
==========================|
question 3 circular_prime |
==========================|
*/
bool circular_prime(unsigned int n){
    //1 is definitionally not a prime number
    if(n == 1){
        return false;
    }
    //n is declared as not a circular prime unless
    //all cases are passed
    bool prime = false;
    //num will be used for arithmetic without changing n
    unsigned int num = n;
    //the number of digits in number "n"
    int counter = 0;
    // finds the length of number n
    while(num > 0){
        counter++;
        num /= 10;
    }
    num = n;
    /*
    runs through all possible rotations of n and checks
    whether each is prime
    */
    for(int i = 0; i < counter; i++){
        //rotates number one place ie. 197 -> 719
        num = circ(num, counter);
        //checks whether number is prime in its current arrangement
        prime = is_prime(num);
        //if any rotation of the number is false, it is not a circular prime
        if(prime == false) return prime;
    }
    //if prime is returned as true, n is prime in all its
    //rotations
    return prime;
}
/*
==================|
question 4 any2dec|
==================|
*/
unsigned long int any2dec(const char *num, unsigned int b){
    //finds the number of digits in num
    int n = strlength(num);
    int sum = 0;
    int inc = 0;
    int mult = 0;
    //sum holds the final converted decimal sum of num
    //inc holds increments to the sum
    //mult is used to place digits in their correct positions
    /*
    takes each part of the hex val, converts it into a dec val
    and adds it to the sum at the correct decimal position
    */
    for(int i = 0; i < n; i++){
        //resets inc and mult for each itteration through
        inc = 0;
        mult = 0;
        //converts the given hex val into a decimal value
        inc = convert(num, i);
        //raises values to different magnitudes eg. so that 342 could become 34,020
        mult = power(b, n-(i+1));
        //adds new value to the total sum
        sum += inc * mult;
    }
    //returns the decimal number
    return sum;
}
/*
==================|
question 5 hex2rgb|
==================|
*/
void hex2rgb(const char *hex, char *rgb){
    //if hex = "#04F3A8" the code below does the following:
    const char r[3] = {hex[1],hex[2]}; // r = {0,4}
    const char g[3] = {hex[3],hex[4]}; // g = {F,3}
    const char b[3] = {hex[5],hex[6]}; // b = {A,8}
    //convert hex values to decimal values
    int rval = any2dec(r,16); // rval = 4
    int gval = any2dec(g,16); // gval = 243
    int bval = any2dec(b,16); // bval = 168
    //begins the rgb output string "rgb("
    rgb[0] = 'r';
    rgb[1] = 'g';
    rgb[2] = 'b';
    rgb[3] = '(';
    //index to track current loc in rgb string
    int counter = 4;
    //r,g,b vals arranged in nice neat order in which they will be used
    int valarr[3] = {rval,gval,bval}; // {4,243,168}
    //arrays to hold the valarr elements converted to char arrays
    char r2[4];
    char g2[4];
    char b2[4];
    //converts decimals to char arrays and stores them to the above arrays
    int2char(valarr[0],r2); // 4 => {4}
    int2char(valarr[1],g2); // 243 => {2,4,3}
    int2char(valarr[2],b2); // 168 => {1,6,8}
    //formats the char arrays into the rgb output array
    //in form "rgb(r2, g2, b2)"
    for(int i = 0; i < strlength(r2); i++){
        //if r is shorter than 3 digits, stops it from taking up 3 whole spaces
        if(r2[i] == '\0'){
            break;
        }
        rgb[counter] = r2[i];
        counter++;
    }
    rgb[counter] = ',';
    counter++;
    for(int i = 0; i < strlength(g2); i++){
        //if g is shorter than 3 digits, stops it from taking up 3 whole spaces
        if(g2[i] == '\0'){
            break;
        }
        rgb[counter] = g2[i];
        counter++;
    }
    rgb[counter] = ',';
    counter++;
    for(int i = 0; i < strlength(b2); i++){
        //if b is shorter than 3 digits, stops it from taking up 3 whole spaces
        if(b2[i] == '\0'){
            break;
        }
        rgb[counter] = b2[i];
        counter++;
    }
    rgb[counter] = ')';
    counter++;
    //marks end of array in case there are less than 17 characters
    rgb[counter] = '\0';
}
/*
=====================|
question 6 str_search|
=====================|
*/
unsigned int str_search(const char *pattern, const char *text){
    //char array to hold a substring
    char sub[strlength(pattern) + 1];
    //tracks the number of times pattern occurs in text
    unsigned int pattcount = 0;
    /*
    goes through text and finds occurences of pattern
    and tracks the number of times pattern occurs
    */
    for(int i = 0; i <= (strlength(text) - strlength(pattern)); i++){
        sub_str(text, sub, i, strlength(pattern));
        //if an occurence of pattern is found, increase the count
        if(patt_check(sub,pattern) == true){
            pattcount += 1;
        }
    }
    //returns the no. of times pattern occured in text
    return pattcount;
}
/*
=====================|
question 7 same_gmail|
=====================|
*/
bool same_gmail(const char *g1, const char *g2){
    //lengths of g1 and g2
    int sizeg1 = strlength(g1);
    int sizeg2 = strlength(g2);
    //mutable char arrays the same size as g1 and g2
    char G1[sizeg1 + 1];
    char G2[sizeg2 + 1];
    /*
    fills the mutable arrays, making them copies of g1 and g2
    respectively
    */
    for(int i = 0; i <= sizeg1; i++){
        G1[i] = g1[i];
    }
    for(int j = 0; j <= sizeg2; j++){
        G2[j] = g2[j];
    }
    //removes all dots '.' from G1 and G2
    remove_dots(G1);
    remove_dots(G2);
    //checks whether the two addresses are the same once the dots are removed
    if(same_str(G1,G2) == true){
        return true;
    }
    //changes letters in G1 and G2 into lowercase letters
    toLower(G1);
    toLower(G2);
    //checks whether the addresses are the same once they are both in
    //all lowercase letters
    if(same_str(G1,G2) == true){
        return true;
    }
    //removes any part of the addresses between the first '+' and the '@'
    chop(G1);
    chop(G2);
    //checks whether the addresses are the same after any section between
    //+ and @ has been removed
    if(same_str(G1,G2) == true){
        return true;
    }
    //if the addresses are the same after all the changes have been made to them
    //they are found to be different addresses
    return false;
}
/*
======================|
question 8 to_hostname|
======================|
*/
void to_hostname(char* address){
    //empty array to hold substring searches for "//"
    char beginning[3];
    //array to compare searches against
    char lookfor[3] = {'/','/','\0'};
    //holds the index of the beginning of the domain name
    int domstart = 0;
    //index holding the index of the end of the domain name
    int domend = strlength(address);
    //searches the string for the start of the domain name
    //using substrings
    for(int i = 0; i < strlength(address); i++){
        sub_str2(address, beginning, i, 2);
        if(same_str(beginning, lookfor) == true){
            //index of the first char of the domain name
            domstart = (i+2);
        }
    }
    //looks for the first occurence of '/' after the start
    //of the domain name denoting the end of the domain name
    for(int j = domstart; j < domend; j++){
        if(address[j] == '/'|| address[j] == ':'){
            domend = j;
            //exits once the end has been found
            break;
        }
    }
    //length of the domain name
    int domlength = (domend - domstart);
    int counter = 0;
    //overwrites address in place to hold the domain name
    for(int z = 0; z < domlength; z++){
        address[z] = address[domstart+z];
        counter++;
    }
    //put a null char at the end of the new address to end it after the domain name
    address[counter] = '\0';
    //makes domain name all lowercase letters
    toLower(address);
}

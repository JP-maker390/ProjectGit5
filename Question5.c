/******************************************************************************

Programming Skills Challenge Siemens.
Question 5 - Teste unitário para a função ConcatRemove(s,t,k)

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Checks if there is a sequence of identical elements in the string and returns 
//the position of the string where there is a difference.
int Check_string(const char *str1, const char *str2) {
    int i;
    for (i = 0; str1[i] != '\0' && str2[i] != '\0'; i++) {
        if (str1[i] != str2[i]) {
            return i;
        }
    }

    //This means equal strings ("abc" = "abc") or one of the complete strings is 
    //equal to the initial sequence of the other string of the same length
    //("abc" = "abcdef")
     return -1;
}


char *ConcatRemove(const char *s, const char *t, int k){
    
    int num_move;// number of movements required
    int pos_diff;//position of the string that will be modified
    
    
    //Returns the index of the position where both strings are different.
    pos_diff  = Check_string(s, t);
    //concat+remove,
    if (pos_diff == 0) {
        num_move = strlen(s) + strlen(t);
      
    } 
    //concat+remove, considering the presence of equal elements
    if(pos_diff > 0) {
      num_move= (strlen(s)-pos_diff + strlen(t)-pos_diff);
    } 
    if(pos_diff == -1) {
     
      if( strlen(t)>strlen(s)){
        num_move = strlen(t)-strlen(s);//concat data ex: t="ABCDE" and s="ABC"
      }else if(strlen(t)<strlen(s)){
        num_move = strlen(t)-strlen(s);//remove data ex: t="ABC" and s="ABCDE"
      }
    }
    
    // Define the conditions to return "Yes" or "No"
    if(k>=num_move){
        
        char *str3 = (char *)malloc(4); 
        str3="Yes";
        return str3;
        
    }else{
        
      char *str4 = (char *)malloc(3);
      str4="No";
      return str4;
    }
    
    
    
}

int main()
{
    

  char minhaString[4];
  char s[101]="abc";
  char t[101]="def";
  int  k[4] = {4,5,6,7};
  
  char s1[101]="blablablabla";
  char t1[101]="blablabcde";
  int  k1[3] = {7,8,9};
  int i;
  int Aux;// auxiliar variable
  char *nova_string;
   
    //Evaluates whether the function works correctly when the number of moves is
    //less than, greater than, or equal to the value of k as defined.
    for(i=0;i<=3;i++){
       Aux = k[i];
       printf("s: %s\n", s);
       printf("t: %s\n", t);
       printf("k: %d\n", Aux);
       nova_string = ConcatRemove(s, t, Aux);
       printf("Return ConcatRemove: %s\n\n",nova_string );
    }
   
    for(i=0;i<=2;i++){
       Aux = k1[i];
       printf("s1: %s\n", s1);
       printf("t1: %s\n", t1);
       printf("k1: %d\n", Aux);
       nova_string = ConcatRemove(s1, t1, Aux);
       printf("Return ConcatRemove: %s\n\n", nova_string);
    }
  return 0;

}
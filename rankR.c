#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
float countLetters(string text);
float countWords(string text);
float countSentences(string text);
float returnGrade(float letters, float words, float sent);

int main(void){
    string text = get_string("Put your text there: ");


    float letrs = countLetters(text);
    float word = countWords(text);
    float sents = countSentences(text);
    int grade = (int)returnGrade(letrs,word,sents);
    printf("%f letter(s)\n",letrs);
    printf("%f word(s)\n",word);
    printf("%f sentence(s)\n",sents);



   if(grade < 1)
       printf("Before Grade 1\n");
   else if(grade >= 16){
       printf("Grade 16+\n");
   }
   else
       printf("Grade %i\n", grade);



}

float countLetters(string text)
{
    float count = 0;
    int i = 0;
    int len = strlen(text);
    for(i = 0;i<len;i++)
    {
        if((text[i] >=97 && text[i <=122]) || (text[i] >= 65 && text[i] <=90))
        count ++;
    }
    return count;
}

float countWords(string text)
{
    float count  = 0;
    int i;
    int len = strlen(text);

    for(i = 0;i< len ;i++)
    {
        //if you see a space in th text,mark that as the end of a word and increase
        //the word count by 1; if you find a double space ingore it; if you see a point mark it as a word
        //if there are no spaces after it(at the end of a text)
        if(text[i]  == 32 || text[i] == 46 || text[i] == 63 || text[i] == 33 || text[i] == 39)
        {
            if(text[i+1] != 32)
            count ++;


        }


    }
    return count;
}

float countSentences(string text)
{
  float count = 0;
  int i;
  int len = strlen(text);

  for(i = 0;i<len;i++){
      //if it ends with a dot,exclamation point or a question mark, make it a sentence
      if(text[i] == 46 || text[i] == 33 || text[i] == 63)
      count ++;
  }

  return count;
}
 float returnGrade(float letters,float words,float sent)
 {
     float L = (letters/words) * 100;
     float S = (sent/words) *100;
     float index  = round(0.0588 * L - 0.296 * S - 15.67);

     return  index;
 }

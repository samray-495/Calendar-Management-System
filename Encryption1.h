#include<stdio.h>
#include<stdlib.h>
#include"Calendar.h"



int encrypt(void);
int decrypt(void);
int encrypt_view(void);
int decrypt_view(void);
int okay(void); 
int Password;
 
FILE *fp1, *fp2;
char ch, en; 

void encrypted1(int Encrypt)
{
    int choice;
    while(1)
    {   
        printf("Select One of the Following:\n");
        printf("\n1. Encrypt\n");   
        printf("2. View The Encypted File\n");
        printf("3. View The Decrypted File\n");
        printf("4. Calendar\n");
        printf("\nEnter Your Choice:\t");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: encrypt();
                break;
            case 2: encrypt_view();
                break;
            case 3: decrypt_view();
                break;
            case 4: okay();
              break; 
        }
    }
}
int encrypt(){
  fp1 = fopen("AccountInformation.txt","r");
  if(fp1 == NULL){
    printf("Source File Could Not Be Found\n"); 
    exit(1);
  } 
  fp2 = fopen("Encryted File.txt","w+");

  if (fp2 == NULL) {
      puts("file Open Error.\n");
      exit(1);
   }
  do {
      ch = fgetc(fp1);
      if (ch >= 'a' || ch <= 'z'){
         en = (ch+3-97)%26 +97;
        fputc(en, fp2);
      } 
      else if(ch >= 'A' || ch <= 'Z'){
         en = (ch+3-65)%26 +65;
        fputc(en, fp1);
      } 
      else
        fputc(ch,fp1);
   } while (ch != EOF);
   
  fclose(fp1);
  fclose(fp2);
  return 0;
}
 
int encrypt_view() //This works Just have to be encrypted
{
    printf("\n");
    fp1 = fopen("Encryted File.txt","r");
    if(fp1 == NULL)
    {
        printf("No File Found\n");
        return(1);
    }
    int ch;
  while ((ch = fgetc(fp1)) != EOF) {
    if (ch >= ' ' || ch <= '~') {
      printf("%c", ch);
    } else {
      printf("<%d>", ch);
    }
  }
  printf("\n");
  fclose(fp1);
}
  
int decrypt_view() //This works Just have to be encrypted
{
   printf("Please enter your password:"); 
   scanf("%d", &Password); 

    if(Password== 5514){
       printf("\n");
    fp1 = fopen("AccountInformation.txt","r");
    if(fp1 == NULL)
    {
        printf("No File Found\n");
        return(1);
    }
    int ch;
  while ((ch = fgetc(fp1)) != EOF) {
    if (ch >= ' ' || ch <= '~') {
      printf("%c", ch);
    } else {
      printf("<%d>", ch);
    }
  }
  printf("\n");
  fclose(fp1);
  return 0;  
     }  
     else {
       printf("incorrect password\n"); 

} 
}

int okay(){

printf("\n\n\t\t\t\t::::::Calendar!::::::\n");
cal(1);
  
}


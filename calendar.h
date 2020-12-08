#include <stdio.h>
#include <stdlib.h>
#include <float.h>
#include <string.h> 
#include "calendarfunctions.h"

//Encryption 
int encrypt(void);
int decrypt(void);
int encrypt_view(void);
int decrypt_view(void);
int okay(void);
FILE *fp1, *fp2;
char ch, en; 
//End of encryption

int ret;
int remove(const char *note);
int number, duration, month, day, year;
float start, end;

void flush() {
  int c; 
  while ((c=getchar())!='\n' && c !=EOF);
   
}

typedef struct {
  int day;
  int month;
  int year;
  char note[255];
  char eventNote[255];
  char eventTitle[255];
  char eventDuration[255];
  char durationTime[255];
  
} Note;

void cal(int sun){

  int year, month, day;
  char choice;
   Note note;
  FILE *fp=NULL;
  char fName[225];
  char fNameFile[255];
  char eventNote[255];
  char eventDescription;
  char eventTitle;
  char eventDuration[255];
  char durationTime[255];
  char eventStart[30];
  char startTime[30];
  char eventEnd[30];
  char endTime[30];
  char title;
  char eventDate[255];
  char date;
  char reminder[255];
  char eventReminder[255];
   
  while(1) {
    printf("1: print calendar\n");
    printf("2. add note\n");
    printf("3. delete note\n");
    printf("4. edit or search note\n");
    printf("5. Logout\n");
    printf("enter your choice: ");
    scanf("\n%c", &choice);
    switch(choice) { 
      //print calendar
      case '1':

      calendar22(1);
      break;

      //add event
      case '2':
        printf("enter event title (no spaces): ");
        scanf("%s", fName );
        sprintf(fNameFile, "%s.txt", fName);
        printf("\nFile created successfully (Press enter)\n");
        

        fp=fopen(fNameFile, "w");

        scanf("%c", &eventTitle);
        fgets(fName, 255, stdin);
        fprintf(fp, "title: %s\n", fName);

        printf("\n++Before each prompt, please enter a space!!++\n");

        printf("\nEnter the month, day and year: ");
        scanf("%c", &date);
        fgets(eventDate, 255, stdin);
        fprintf(fp, "date: %s\n", eventDate);
        
        printf("Enter event note: \n");
        scanf("%c", &eventDescription);
        fgets(eventNote, 255, stdin);
        fprintf(fp,"description: %s\n", eventNote);

        printf("Enter start time: \n");
        scanf("%c", startTime);
        fgets(eventStart, 30, stdin);
        fprintf(fp, "Start time: %s\n", eventStart);

        printf("Enter end time: \n");
        scanf("%c", endTime);
        fgets(eventEnd, 30, stdin);
        fprintf(fp, "End Time: %s\n", eventEnd);

        printf("Enter duration: \n");
        scanf("%c", durationTime);
        fgets(eventDuration, 30, stdin);
        fprintf(fp, "duration: %s\n", eventDuration);

        printf("Enter reminder: \n");
        scanf("%c", reminder);
        fgets(eventReminder, 30, stdin);
        fprintf(fp, "duration: %s\n", eventReminder);

        printf("Note added sucessfully\n");
        fclose(fp);
        
        //Encryption
        while(1){
                  fp1 = fopen(fNameFile,"r");
          if(fp1 == NULL){
            printf("Source File Could Not Be Found\n"); 
            exit(1);
          } 
          fp2 = fopen("Encryted Notes.txt","w+");

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
           break; 
//End of Encryption
        }
        break;
        //removing file
        case '3':
        ret=remove(fNameFile);
        
        printf("Enter the file name: \n");
        scanf("%s", fName);
        sprintf(fNameFile, "%s.txt", fName);
        
        fp=fopen(fNameFile,"r");
        fgets(fName, 255, stdin);
        remove(fNameFile);

         {
        if (ret)
          printf("Note deleted successfully\n");
        else
          printf("unable to delete note\n");
        }
        break;  

        //edit/search file
        case '4': 
          printf("Please enter the file name: \n");
          scanf("%s", fName);
          sprintf(fNameFile, "%s.txt", fName);
          fp2=fopen("Encryted Edit File.txt", "w");
          fclose(fp2);
        
          char newName[255];
          char newDuration[255];
          char startTime[30];
          char endTime[30];
         
          char newReminder[255];
          char newFile[255]; 
          char okay[225];
          int ret;
          char ch;
          char string1[30];
          char string2[30];
          char string3[30];
          char temp[255];
          
          while(2){
            printf("Please select one of the following options.\n");
            printf("1. Edit Title\n");
            printf("2. Edit Duration\n");
            printf("3. Edit Start\n");
            printf("4. Edit End\n");
            printf("5. Edit Description\n");
            printf("6. Edit Reminders\n");
            printf("7. Search Title\n");
            printf("8. Search Duration\n");
            printf("9. Search Start\n");
            printf("10. Search End\n");
            printf("Number: ");
            scanf("%d", &number);
            switch (number)
            {
              case 1:
                fp=fopen(fNameFile, "r+");
                printf("Enter new name for file: ");
                scanf("%s", newName);
                sprintf(newName, "%s.txt", newFile);
                ret=rename(fNameFile, newFile);
                if (ret==0) {
                  printf("file renamed succssfully.\n"); 
                }
                else{
                printf("error: unable to rename file\n");
                }
                break;

              case 2:
                printf("Please use - and a space before editing this task.\n");
                fp=fopen(fNameFile, "r+");
                printf("edit duration: ");
                scanf("%s", durationTime);
                fgets(durationTime, 255, stdin);
                fprintf(fp,"duration: %s\n", durationTime);
                fclose(fp);
   //Encryption edit
                while(1){
                  fp1 = fopen(fNameFile,"r");
          if(fp1 == NULL){
            printf("Source File Could Not Be Found\n"); 
            exit(1);
          } 
          fp2 = fopen("Encryted Notes.txt","w+");

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
           break; 
            
//End of Encryption
          
            
              case 3:
                fp=fopen(fNameFile, "r+");
                printf("edit start time: ");
                scanf("%s", eventStart);
                fgets(eventStart, 30, stdin);
                fprintf(fp, "start: %s\n", eventStart);
                fclose(fp);

  //Encryption edit time
                 while(1){
                    fp1 = fopen(fNameFile,"r+"); 
                    if(fp1 == NULL){
                      printf("Source File Could Not Be Found\n"); 
                      } 
                      fp2 = fopen("Encryted Edit start time File.txt","r+");
                      if (fp2 == NULL) {
                      puts("file Open Error.\n");
                      }
                      do {
                          ch = fgetc(fp1);
                      if (ch >= 'a' || ch <= 'z'){
                    en = (ch+3-97)%26 +97;
                    fputc(en, fp1);
                      } 
                      else if(ch >= 'A' || ch <= 'Z'){
                    en = (ch+3-65)%26 +65;
                    fputc(en, fp2);
                      } 
                
                      } while (ch != EOF);
              
                      fclose(fp1);
                      fclose(fp2);
                      break;
                 }
            
//End of Encryption
       
            
              case 4:
                fp=fopen(fNameFile, "r+");
                printf("edit end time: ");
                scanf("%s", endTime);
                fgets( endTime, 30, stdin);
                fprintf(fp, "end: %s\n", endTime);
                fclose(fp);

      //Encryption edit time
                 while(1){
                    fp1 = fopen(fNameFile,"r+"); 
                    if(fp1 == NULL){
                      printf("Source File Could Not Be Found\n"); 
                      } 
                      fp2 = fopen("Encryted Edit end time File.txt","r+");
                      if (fp2 == NULL) {
                      puts("file Open Error.\n");
                      }
                      do {
                          ch = fgetc(fp1);
                      if (ch >= 'a' || ch <= 'z'){
                    en = (ch+3-97)%26 +97;
                    fputc(en, fp1);
                      } 
                      else if(ch >= 'A' || ch <= 'Z'){
                    en = (ch+3-65)%26 +65;
                    fputc(en, fp2);
                      } 
                
                      } while (ch != EOF);
              
                      fclose(fp1);
                      fclose(fp2);
                      break;
                 }
            
//End of Encryption
    
              case 5:
                fp=fopen(fNameFile, "r+");
                printf("edit description: ");
                scanf("%s", &eventDescription);
                fgets( &eventDescription, 255, stdin);
                fprintf(fp, "description: %s\n", &eventDescription);
                fclose(fp);
   //Encryption edit description
                 while(1){
                      fp1 = fopen(fNameFile,"r+"); 
                      if(fp1 == NULL){
                        printf("Source File Could Not Be Found\n"); 
                        } 
                        fp2 = fopen("Encryted edit File.txt","r+");
                        if (fp2 == NULL) {
                        puts("file Open Error.\n");
                        }
                        do {
                            ch = fgetc(fp1);
                        if (ch >= 'a' || ch <= 'z'){
                      en = (ch+3-97)%26 +97;
                      fputc(en, fp1);
                        } 
                        else if(ch >= 'A' || ch <= 'Z'){
                      en = (ch+3-65)%26 +65;
                      fputc(en, fp2);
                        } 
                  
                        } while (ch != EOF);
                
                        fclose(fp1);
                        fclose(fp2);
                        break;
                
//End of Encryption
        
            
              case 6:
                fp=fopen(fNameFile, "r+");
                printf("edit reminder: ");
                scanf("%s", newReminder);
                fgets( newReminder, 255, stdin);
                fprintf(fp, "reminder: %s\n", newReminder);
                fclose(fp);
//Encryption edit reminder
                 while(1){
                    fp1 = fopen(fNameFile,"r+"); 
                    if(fp1 == NULL){
                      printf("Source File Could Not Be Found\n"); 
                      } 
                      fp2 = fopen("Encryted Edit File.txt","r+");
                      if (fp2 == NULL) {
                      puts("file Open Error.\n");
                      }
                      do {
                          ch = fgetc(fp1);
                      if (ch >= 'a' || ch <= 'z'){
                    en = (ch+3-97)%26 +97;
                    fputc(en, fp1);
                      } 
                      else if(ch >= 'A' || ch <= 'Z'){
                    en = (ch+3-65)%26 +65;
                    fputc(en, fp2);
                      } 
                
                      } while (ch != EOF);
              
                      fclose(fp1);
                      fclose(fp2);
                      break;
                 }
            
//End of Encryption
        

              case 7:
                fp=fopen(fNameFile, "r");
                
                while ((ch=fgetc(fp)) !=EOF)
                  printf("%c", ch);
                break;
            
              case 8:
                
                fp=fopen(fNameFile, "r"); 
                printf("Enter the duration you want to search: \n");
                scanf("%s", eventDuration);
                fgets(string1, 30, stdin);
                printf("the duration is %s\n", string1);
                break;
            
              case 9:
                fp=fopen(fNameFile, "r"); 
                printf("Enter the start time you want to search: \n");
                scanf("%s", eventStart);
                fgets(string2, 30, stdin);
                printf("the start time is %s\n", string2);
                break;

              case 10:
                fp=fopen(fNameFile, "r"); 
                printf("Enter the end time you want to search: \n");
                scanf("%s", eventEnd);
                fgets(string3, 30, stdin);
                printf("the end time is %s\n", string3);
                break;

              case 11:
                printf("\n Thank you! have a good day!\n");
                break;
                

              default:
                printf("This is not an option. Please chose one of the options listed above.\n");
                break;
                 }
            }
            }
          
      case '5':
          printf("\nThank you. Have a good day!\n");
		  exit(1);
          break;

      default:
        printf("not a valid option\n");
        break; 
       
    }
  }     
  //return 0;
           
}
} 

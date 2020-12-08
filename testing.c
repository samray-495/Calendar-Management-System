#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "Encryption1.h"

// Variables for Creating Account
char fname[120], lname[120], username[120], password[120];
// Variables for Login
char user[120], pass[120];
char admin;
// Variable for reading file
char fileReader[255];
// Variables to help with creating an account and logging in
int found, session;
FILE * accountInfoPointer;

int main (void)
{
  printf("\n\n\t\t\t\t::::::Welcome to Calendar!::::::\n"); 
    // Asking user if they want to sign up or login
  printf("\n\n\t\t\t\tPlease choose one of the following: \n");
  printf("1. Sign up\n");
  printf("2. Login\n");  
  //printf("3. Admin login\n");   
  
  printf("Option: "); 

  scanf("%d", &session);
  
switch(session)
  {
    // Signup
    case 1:

      printf("Are you creating an admin account? (YES = $) or (NO = !)?\n");
      scanf("%s", &admin);
      char *keycode;
      switch(admin)
      {
        case '$':
          printf("PLEASE ENTER ADMIN KEY: ");
          scanf("%s", keycode);
          if(strcmp(keycode, "Admin123") == 0)
          {
              printf("ADMIN KEY IS CORRECT\n");
          }
          else
          {
              printf("ADMIN KEY INCORRECT\n");
              return 0;
          }
        break;

        case '!':
          printf("REGULAR USER ACCOUNT\n");
        break;

        default:
        printf("Invalid Selection");
        return 0;
        break;
      }
      
      printf("TYPE YOUR FIRST NAME: ");
      scanf("%s", fname);

      printf("TYPE YOUR LAST NAME: ");
      scanf("%s", lname);

      printf("CREATE USERNAME: ");
      scanf("%s", username);

      // Reading Account Information Text File
      accountInfoPointer = fopen("AccountInformation.txt", "r");
      if(accountInfoPointer == NULL)
      {
          printf("\nCan't open file or file doesn't exist.");
          exit(0);
      }
        
      // Retrieving username from account information file
      while(fscanf(accountInfoPointer, "%s\n", user) != EOF)
      {
        if(strcmp(username,user) == 0)
        {
          found = 1;
          break;
        }
      }
        // If the username already exists, it will not allow the user to create their account
        if(found == 1){
          printf("Username already exists!");
        }
        else
        {
              printf("Create a password: \n");
              scanf("%s", password);

              accountInfoPointer = fopen("AccountInformation.txt", "a");
                      
              fprintf(accountInfoPointer,"%s\t\t\t%s\t\t\t%s\t\t\t%s\t\t\t%c\n", fname, lname, username, password, admin);
        }


      fclose(accountInfoPointer);
      break;
      //LOGIN CODE
      case 2:
        found = 0;
        printf("What is your username?\n");
        scanf("%s", user);

        // Reading Account Infor mation Text File
        accountInfoPointer = fopen("AccountInformation.txt", "r");

        if(accountInfoPointer == NULL){
          printf("\nCan't open file or file doesn't exist.");
          exit(0);
        }

        // Reading Data From File
        while(fscanf(accountInfoPointer, "%s", username)!=EOF)
        {
          if(strcmp(username,user)==0)
          {
            found = 1;
            break;
          }
        }

        if(found == 1)
        {
            printf("What is your password?\n");
            scanf("%s", pass);

            // Reading data from file (password)
            while(fscanf(accountInfoPointer, "%s", password) != EOF)
            {
              if(strcmp(password,pass) == 0)
              {
                found = 2;
                break;
              }
              else
              {
                printf("Incorrect password");
              }
            }          
        }
        else
        {
          printf("Invalid password");
        }

        if(found == 2)
        {
          printf("WELCOME %s", username);
        }
        else
        {
          printf("Invalid password");
        }

        fclose(accountInfoPointer);
        break;

      default:
        printf("Invalid selection");
      break;
  }

      goto Encrypt; //goes to calender menu 
 Encrypt:{
        char Title;{ 
        printf("\n\n\t\t\t\t::::::Encrypt::::::\n");  
        encrypted1(1); 
      }
  }
}

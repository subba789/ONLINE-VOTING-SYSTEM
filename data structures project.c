// A simple online voting system using data structures in C with file handling

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<windows.h>
#define pass 5478
#define mainpass 2825
// Define a structure for a candidate
typedef struct candidate {
    char *name; // Name of the candidate
    int votes; // Number of votes received
    struct candidate *next; // Pointer to the next candidate
} candidate;

// Define a structure for a voter
typedef struct voter {
    char *id; // ID of the voter
    int voted; // Flag to indicate if the voter has voted or not
    struct voter *next; // Pointer to the next voter
} voter;

// Define a global variable for the head of the candidate list
candidate *head = NULL;

// Define a global variable for the head of the voter list
voter *vhead = NULL;

// Define a global variable for the file name of candidates data
char *cfile = "candidates.txt";

// Define a global variable for the file name of voters data
char *vfile = "voters.txt";

// Define a function to load the candidates data from a file
void load_candidates() {
    // Open the file in read mode
    FILE *fp = fopen(cfile, "r");
    // If the file does not exist or cannot be opened, print a message and return
    if (fp == NULL) {
        printf("Cannot open candidates file.\n");
        return;
    }
    // Else, read each line from the file and create a candidate node with that data
    else {
        char name[20];
        int votes;
        while (fscanf(fp, "%s %d\n", name, &votes) == 2) {
            candidate *new = (candidate *)malloc(sizeof(candidate));
            new->name = (char *)malloc(strlen(name) + 1);
            strcpy(new->name, name);
            new->votes = votes;
            new->next = NULL;
            if (head == NULL) {
                head = new;
            }
            else {
                candidate *temp = head;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = new;
            }
        }
        // Close the file
        fclose(fp);
    }
}

// Define a function to load the voters data from a file
void load_voters() {
    // Open the file in read mode
    FILE *fp = fopen(vfile, "r");
    // If the file does not exist or cannot be opened, print a message and return
    if (fp == NULL) {
printf("              Cannot open voters file.\n");
        return;
    }
    // Else, read each line from the file and create a voter node with that data
    else {
        char id[10];
        int voted;
        while (fscanf(fp, "%s %d\n", id, &voted) == 2) {
            voter *new = (voter *)malloc(sizeof(voter));
            new->id = (char *)malloc(strlen(id) + 1);
            strcpy(new->id, id);
            new->voted = voted;
            new->next = NULL;
            if (vhead == NULL) {
                vhead = new;
            }
            else {
                voter *temp = vhead;
                while (temp->next != NULL) {
                    temp = temp->next;
                }
                temp->next = new;
            }
        }
        // Close the file
        fclose(fp);
    }
}

// Define a function to find a candidate by name and return its pointer 

candidate *find_candidate(char *name) {

// If the list is empty, return NULL

if (head == NULL) {

return NULL;

}

// Else,traverse the list and compare each candidate's name with the given name

else {

candidate *temp = head;

while (temp != NULL) {

// If a match is found, return its pointer

if (strcmp(temp->name,name) == 0) {

return temp;

}

temp = temp->next;

}

// If no match is found,return NULL

return NULL;

}

}

// Define a function to find a voter by id and return its pointer

voter *find_voter(char *id) {

// If the list is empty, return NULL

if (vhead == NULL) {

return NULL;

}

// Else, traverse the list and compare each voter's id withthe given id

 else { 
voter *temp = vhead; 

while (temp != NULL) {

 // If a match is found,return its pointer

if (strcmp(temp->id,id) == 0) {
return temp;
}
temp = temp->next;
}
// If no match is found, return NULL
return NULL;
}
}


// Define a function to create a new candidate and add it to the list
void create_candidate(char *name) {
    // Allocate memory for a new candidate
    candidate *new = (candidate *)malloc(sizeof(candidate));
    // Allocate memory for the name field
    new->name = (char *)malloc(strlen(name) + 1);
    // Copy the name to the new candidate
    strcpy(new->name, name);
    // Initialize the votes to zero
    new->votes = 0;
    // Set the next pointer to NULL
    new->next = NULL;
    // If the list is empty, make the new candidate the head
    if (head == NULL) {
        head = new;
    }
    // Else, traverse the list and add the new candidate at the end
    else {
        candidate *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = new;
    }
}

// Define a function to create a new voter and add it to the list
void create_voter(char *id) {
    // Allocate memory for a new voter
    voter *new = (voter *)malloc(sizeof(voter));
    // Allocate memory for the id field
    new->id = (char *)malloc(strlen(id) + 1);
    // Copy the id to the new voter
    strcpy(new->id, id);
    // Initialize the voted flag to zero
    new->voted = 0;
    // Set the next pointer to NULL
    new->next = NULL;
    // If the list is empty, make the new voter the head 
if (vhead == NULL) { 
vhead = new; 
} 
// Else, traverse the list and add the new voter at the end 
else { 
voter *temp = vhead; 
while (temp->next != NULL) { 
temp = temp->next; 
} 
temp->next = new; 
} 
} 

// Define a function to display all the candidates and their votes 
void display_candidates() { 
// If the list is empty, print a message and return 
if (head == NULL) { 
printf("               No candidates found.\n"); 
return; 
} 
// Else, traverse the list and print each candidate and their votes 
else { 
printf("\n                    Candidates:\n"); 
candidate *temp = head; 
while (temp != NULL) { 
printf("                    %s\n", temp->name); 
temp = temp->next; 
} 
printf("\n"); 
} 
sleep(3);
} 

// Define a function to display all voters and their status
 void display_voters() {
 // If the list is empty, print a message and return
if (vhead == NULL) {
printf("               No voters found.\n");
return;
}
// Else, traverse the list and print each voter and their status

else {

printf("\n                    Voters and their status:\n");

voter *temp = vhead;

while (temp != NULL) {

printf("                    %s: %s\n", temp->id,temp->voted ? "Voted" : "Not voted");

temp = temp->next;

}

printf("\n");

}
sleep(3);
}


// Define a function to cast a vote for a given voter id and candidate name 
void cast_vote(char *id,char *name) {
// Find the voter by id using find_voter function
voter *v = find_voter(id);
// If no such voter exists, print a message and return 
if (v == NULL) {
printf("              Invalid voter id.\n");
return;
}
// Else,check if the voter has already voted or not
 else {
if (v->voted == 1) {
// If yes,print a message and return 
printf("              You have already voted.\n");
return;
}
else {
// Else, find the candidate by name using find_candidate function
candidate *c = find_candidate(name);
// If no such candidate exists, print a message and return
 if (c == NULL) {
printf("               Invalid candidate name.\n\n");
return;
}
else {
// Else, increment the votes ofthe candidate by one
 c->votes+=1;
// Set the voted flag of the voter to one
 v->voted = 1;
// Print a confirmation message 
printf("                You have successfully voted for %s.\n\n",c->name);
}
}
}
}
// Define a function to declare the winner of the election based on maximum votes
void declare_winner() {
    // If the list is empty, print a message and return
    if (head == NULL) {
printf("                No candidates found.\n\n");
        return;
    }
    // Else, traverse the list and find the candidate with maximum votes
    else {
        candidate *max = head;
        candidate *temp = head->next;
        while (temp != NULL) {
            if (temp->votes > max->votes) {
                max = temp;
            }
            temp = temp->next;
        }
        // Print the name and votes of the winner
printf("\n\n                  The winner of the election is %s with %d votes.\n\n\n", max->name, max->votes);
printf("                          ****HEARTLY CONGRATULATIONS %s *****\n\n",max->name);
    }
}


// Define a function to save the candidates data to a file
void save_candidates() {
    // Open the file in write mode
    FILE *fp = fopen(cfile, "w");
    // If the file cannot be opened, print a message and return
    if (fp == NULL) {
printf("                Cannot open candidates file.\n");
        return;
    }
    // Else, traverse the list and write each candidate's data to the file
    else {
        candidate *temp = head;
        while (temp != NULL) {
            fprintf(fp, "%s %d\n", temp->name, temp->votes);
            temp = temp->next;
        }
        // Close the file
        fclose(fp);
    }
}


// Define a function to save the voters data to a file
void save_voters() {
     // Open the file in write mode 
     FILE *fp = fopen(vfile,"w"); 
     // If the file cannot be opened,print a message  and return 
     if (fp == NULL) { 
printf("               Cannot open voters file.\n"); 
          return; 
     } 
     // Else,traverse the list and write each voter's data to the file 
     else { 
          voter *temp= vhead; 
          while (temp != NULL) { 
               fprintf(fp,"%s %d\n",temp->id,temp->voted); 
               temp = temp->next; 
          } 
          // Close the file 
          fclose(fp); 
     } 
} 
// Define a main function to test the program 

int main() { 

int choice,i,sai; 

char id[3], name[50]; 

// Load the candidates and voters data from the files 

load_candidates(); 

load_voters(); 
while(1){
printf("              Enter password to start the election process\n\n");

printf("\n");

                      scanf("               %d",&sai);
if(sai==mainpass){
	system("cls");
for(i=0;i<3;i++){
	if(i==0){
		printf("\n\n                                            REGISTRATIONS OPEN\n\n\n");
		while(1){
		
printf("\n\n               *********************WELCOME TO ONLINE VOTING SYSTEM********************               \n\n\n"); 

printf("                                 SRMAP 2023 STUDENT COUNCIL ELECTIONS \n\n");

printf("              1. Create Candidate\n\n"); 

printf("              2. Create Voter\n\n"); 
            
printf("              3. Exit(only admin can access)\n\n");
            
printf("              Enter your choice: \n\n");

            scanf("%d", &choice); 
            if(choice==3){
printf("              Enter password to exit\n\n\n");
            	scanf("%d",&sai);
            	if(sai==pass){
printf("              REGISTRATIONS COMPLETED\n");
            		sleep(2);
            		break;
				}
				else{
printf("             Wrong password!!!please try again\n");
system("cls");
					continue;
				}
			}
            switch(choice) { 

case 1:  

printf("            Enter candidate name:\n\n ");  

scanf("%s",&name);

candidate *c = find_candidate(name);
 if (c == NULL) {
 	create_candidate(name);  
}
else {
printf("           Name already exists\n");}
break;  

case 2:  

printf("          Enter voter id: (it should be only three digits i.e 0 to 9)\n");  

scanf("%s", id);  
if(strlen(id)>3||strlen(id)<3){
printf("         Invalid id\n");
printf("\n       Please re-enter the password(it should be only three digits i.e 0 to 9)\n\n");
break;}
else{
	voter *v = find_voter(id);
if (v == NULL) {
	create_voter(id);  
}
else
printf("        This voter id already exits\n");
}

break;  

default:

printf("        Invalid choice.\n");



}

sleep(2);

   system("cls");
		}
	}
	
	else if(i==1){
		system("cls");
		printf("\n\n                                  VOTING STARTS\n\n\n\n\n");
		while(1){
	
printf("\n\n               *********************WELCOME TO ONLINE VOTING SYSTEM********************               \n\n\n"); 

printf("                                 SRMAP 2023 STUDENT COUNCIL ELECTIONS \n\n\n");

printf("                   1. Display Candidates\n\n"); 

printf("                   2. Display Voters(only admin can access)\n\n"); 

printf("                   3. Cast Vote\n\n");  

printf("                   4. Exit(only admin can access)\n\n"); 

printf("                   Enter your choice:\n\n "); 

scanf("%d", &choice); 
  if(choice==4){
printf("                   Enter password to exit\n");
            	scanf("%d",&sai);
            	if(sai==pass){
printf("                   VOTING COMPLETED\n");
            		sleep(2);
            		break;
				}
				else{
printf("                   Wrong password!!!please try again\n");
					system("cls");
					
					continue;
				}
			}
switch(choice){
case 1:  

display_candidates();  

break;  

case 2:  

printf("                   Enter password to exit\n");
            	scanf("%d",&sai);
            	if(sai==pass){
            		display_voters(); 
				}
				else{
printf("                  Wrong password!!!please try again\n");
system("cls");
					continue;
				}
 

break;  

case 3:  

printf("                  Enter your voter id:\n\n ");  

scanf("%s", id);  

display_candidates();

printf("                 Enter your preferred candidate name:\n\n ");  

scanf("%s", name);  

cast_vote(id,name);  

break;  
	default:
printf("                 Invalid choice\n");
		}
		sleep(2);
	
	system("cls");
	}
	
	
}
else{
	system("cls");
	printf("\n\n                                   WINNER DECLARATION\n\n\n\n\n");
	while(1){
printf("\n\n               *********************WELCOME TO ONLINE VOTING SYSTEM********************               \n\n\n"); 

printf("                                 SRMAP 2023 STUDENT COUNCIL ELECTIONS \n\n\n");

printf("                   1. Declare Winner(only for admin)\n\n");

printf("                   2.Exit(only admin can access)\n\n");

printf("                   Enter choice\n\n");
	scanf("%d",&choice);
	switch(choice){
		case 1: 

printf("                   Enter the password:\n\n\n");
int ram;
scanf("%d",&ram);

if(ram==pass)

declare_winner();

else{
printf("                  You have entered wrong password!!! please try again\n");
  
printf("                  Successfully voting completed\n");
			printf("\n\n");
			sleep(2);}
			break;
			case 2:
save_candidates();

save_voters();

exit(0);

default:

printf("                 Invalid choice.\n");	

}
}
	}
}}

else
printf("                Wrong password.....!!! Please try again\n");}


return 0;

}

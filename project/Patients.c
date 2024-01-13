//ID: admin
//password: 1234
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

char key;

struct history {
    int id;
    char time[50];  
    char AppointmentOrVisit[50];
    char Date[50];
    int DocID;
    int timecode;
    int daycode;
} h;

struct patient {
    int ID;
    int bedNum;
    char patientname[50];
    int patientage;
    char disease[50];
    char address[50];
    char patientcontact[50];
    char date[12];
} p;

struct Doctor {
    char ID[50];
    char DoctorName[50];
    char Specialization[50];
    char Timings[50];
    char Days[50];
}D;

//struct beds {
//   int id;
//    int bedNum;
//    char patientName[50];
//    int patientcontact;
//    char patientAddress[50];
//    char disease[50];
//    char date[12];
//}b;

FILE *docfile;
//FILE *patientBed;
    
int DoctorAdd();
int DoctorView();
int DoctorSearch();
int SpecializationSearch();
int DeleteDoctor();
int UpdateDoctor();


// function declarations
int admitrecord(FILE *fileptr);
int readrecord(FILE *fileptr);
int searchrecord(FILE *fileptr,FILE *historyptr);
int deleterecord(FILE *fileptr);
int editrecordappoinments(FILE *historyptr,int id);
int editrecordvisits(FILE *historyptr,int id);
//

int ReserveBed(FILE *fileptr);
int availableBed(FILE *fileptr);
int ViewOccupiedBeds(FILE *fileptr);
int DischargePatientFromBed(FILE *fileptr);
int SearchBedByPatientName(FILE *fileptr);
int SearchBedByContactNo(FILE *fileptr);

int appointments(FILE *historyptr);

int removeappointment(FILE *historyptr);

int main()
{
	FILE *fileptr;
	FILE *historyptr;
	while(1){
	int idcheck=0;
	int passcheck=0;

         do {
            system("cls");
            if ((idcheck && passcheck)) {
                printf("Incorrect ID or Password\n");
                getch();
            }
            system("cls");
            
            char ID[50];
            char password[50];

            printf("Hospital Management System\n=============================\n\t   Login\n\n");
            printf("ID:");
            gets(ID);

            printf("Password:");
            int i = 0;
            while (1) {
                password[i] = getch();
                if (password[i] == '\r') {
                    password[i] = '\0';
                    break;
                }
                printf("*");
                i++;
            }

            idcheck = strcmp("admin", ID);
            passcheck = strcmp("1234", password);

        } while (idcheck || passcheck); // Continue if either ID or Password is incorrect

        printf("\n\nLogin Successful!\n");

	while(1)
	{
					system("cls");
					int choice3;
		            printf("Hospital Management System\n=============================");
		            printf("\n0. Exit ");
	            	printf("\n1. View Patient Records");
	            	printf("\n2. Search Patient Records");
	             	printf("\n3. Add New Patient Record");
	               	printf("\n4. Delete Patient Records");
	               	printf("\n5. Add Appointments");
		          	printf("\n6. Add Visits");
		            printf("\n7. Add Doctor");
		            printf("\n8. View Doctors");
		            printf("\n9. Search Doctor By Name");
		            printf("\n10. Search Doctor By Specialization");
		            printf("\n11. Delete Doctor");
		            printf("\n12. Update Doctor");
		            printf("\n13. Reserve a Bed");
		            printf("\n14. Check Availble Beds");
		            printf("\n15. Discharge A Patient From Bed");
		            printf("\n16. Search Patient By Contact");
		            printf("\n17. Check Appointments");
		            printf("\n18. Remove Todays Appointment");
		            printf("\nEnter your choice: "); scanf("%d",&choice3);
		            switch(choice3)
		            {
			            case 0: break;
			            case 1: readrecord(fileptr); break;
		            	case 2: searchrecord(fileptr,historyptr); break;
			            case 3: admitrecord(fileptr); break;
		            	case 4: 
		           	{
				           
				           deleterecord(fileptr); break;
			        }   
			            case 5: 
			        {
			               int id; printf("\nEnter the record id you want to add appointments for: "); 
						   key = getch();
                           if (key == 27)
		                   {
                              return 0;
	                       }
						   scanf("%d",&id);
			               editrecordappoinments(historyptr,id);
                           break;
		        	} 
			            case 6: 
			        {
			              int id; printf("\nEnter the record id you want to add visits for: "); 
						   key = getch();
                           if (key == 27)
		                   {
                              return 0;
		                   }
		                   scanf("%d",&id);
				           editrecordvisits(historyptr,id); break;
		          	}


                        	case 7:
                            DoctorAdd();
                            break;

                            case 8:
                            DoctorView();
                            break;
                
                            case 9:
                            DoctorSearch();
                            break;
                
                            case 10:
                         	SpecializationSearch();
                        	break;
            	
                            case 11:
            	            DeleteDoctor();
            	            break;
            	
                            case 12:
            	            UpdateDoctor();
            	            break;

                            case 13:
                            ReserveBed(fileptr);
                            break;

                            case 14:
                            availableBed(fileptr);
                            break;

                            case 15:
                            DischargePatientFromBed(fileptr);
                            break;


                            case 16:
                            SearchBedByContactNo(fileptr);
                            break;
                            
                            case 17:
                            appointments(historyptr);
                            break;
                            
                            case 18:
                            removeappointment(historyptr);
							break;
								
                            default:
                            printf("Invalid Choice...\n\n");
                        	break;
						}
					}
	fclose(fileptr);
}
}

// fuction definitions
int admitrecord(FILE *fileptr){
	system("cls");
	fileptr =  fopen("Patients.txt","a");
	printf("\nEnter pateint ID: ");
	key = getch();
        if (key == 27) {
                return 0;
			}
	 scanf("%d",&p.ID);
	printf("\nEnter pateint name: ");
	key = getch();
        if (key == 27) {
                return 0;
			} scanf("%s",p.patientname);
	
	printf("\nEnter pateint age: "); key = getch();
        if (key == 27) {
                return 0;
			}scanf("%d",&p.patientage);
	printf("\nEnter patient disease: ");key = getch();
        if (key == 27) {
                return 0;
			} scanf("%s",p.disease);
	
	printf("\nEnter patient address: ");key = getch();
        if (key == 27) {
                return 0;
			} scanf("%s",p.address);
	
	printf("\nEnter patient contact: ");key = getch();
        if (key == 27) {
                return 0;
			} scanf("%s",p.patientcontact);
	
	p.bedNum=0;
	strcat(p.date,"0");
	
	fprintf(fileptr,"\n%d %d %s %d %s %s %s %s",p.ID,p.bedNum,p.patientname,p.patientage,p.disease,p.address,p.patientcontact,p.date);
	fclose(fileptr);
	printf("\nPatient information added to the file successfully.\n");	
	getch();
	
	
}

int DoctorAdd()
{
	system("cls");
	printf("\nEnter Doctor ID: ");
	key = getch();
    if (key == 27){
        return 0;
	}
	scanf(" %[^\n]",D.ID);
	printf("\nEnter Doctor Name: ");
	key = getch();
        if (key == 27) {
                return 0;
			}
	scanf(" %[^\n]",D.DoctorName);
	printf("\nEnter Doctor Specialization: ");
	key = getch();
        if (key == 27) {
                return 0;
			}
	scanf(" %[^\n]",D.Specialization);
	printf("\nEnter Doctor Timings: ");
	key = getch();
        if (key == 27) {
                return 0;
			}
	scanf(" %[^\n]",D.Timings);
	printf("\nEnter Doctor Days: ");
	key = getch();
        if (key == 27) {
                return 0;
			}
	scanf(" %[^\n]",D.Days);
	
	docfile = fopen("doctors.txt","a");
	fprintf(docfile,"%s %s %s %s %s\n",D.ID,D.DoctorName,D.Specialization,D.Timings,D.Days);
	fclose(docfile);
	
	printf("\nDoctor information added to the file successfully.\n");	
	getch();
}

int ReserveBed(FILE *fileptr) {
    int key, ch, found = 0;

    printf("Enter id of patient: ");
    key = getch();
    if (key == 27) {
        return 0;
    }
    scanf("%d", &ch);

    fileptr = fopen("Patients.txt", "r+");
    if (fileptr == NULL) {
        printf("Error opening file!\n");
        getch();
        return 0;
    }

    FILE *tempFile = fopen("temp.txt", "w+");
    if (tempFile == NULL) {
        printf("Error opening temporary file!\n");
        fclose(fileptr);
        getch();
        return 0;
    }

    while (fscanf(fileptr, "%d %d %s %d %s %s %s %s", &p.ID, &p.bedNum, p.patientname, &p.patientage, p.disease, p.address, p.patientcontact, p.date) == 8) {
    if (ch == p.ID && p.bedNum == 0) {
        found = 1;
        availableBed(fileptr);
        printf("Enter Bed Number: ");
        key = getch();
        if (key == 27) {
            fclose(fileptr);
            fclose(tempFile);
            remove("temp.txt");
            return 0;
        }
        scanf("%d", &p.bedNum);
        printf("Enter Date: ");
        if (key == 27) {
            fclose(fileptr);
            fclose(tempFile);
            remove("temp.txt");
            return 0;
        }
        scanf("%s", p.date);
        fprintf(tempFile, "%d %d %s %d %s %s %s %s\n", p.ID, p.bedNum, p.patientname, p.patientage, p.disease, p.address, p.patientcontact, p.date);
        printf("\nPatient Admitted.\n");
    } else {
        fprintf(tempFile, "%d %d %s %d %s %s %s %s\n", p.ID, p.bedNum, p.patientname, p.patientage, p.disease, p.address, p.patientcontact, p.date);
    }
}


    if (!found) {
        printf("No patient found\n");
    }

    fclose(fileptr);
    fclose(tempFile);
    remove("Patients.txt");
    rename("temp.txt", "Patients.txt");
    getch();
    return 0;
}


int readrecord(FILE *fileptr){
	system("cls");
	
    
	fileptr =  fopen("Patients.txt","r");
    rewind(fileptr);
	printf("%-10s %-10s %-20s %-20s %-20s %-20s %s %s\n","ID","Bed Number","Name","Age","Disease","Address","Contact","Bed Entry");
	printf("----------------------------------------------------------------------------------------------------------------------------\n");
    while(fscanf(fileptr,"%d %d %s %d %s %s %s %s",&p.ID,&p.bedNum,p.patientname,&p.patientage,p.disease,p.address,p.patientcontact,p.date)==8)
    {
    	printf("%-10d %-10d %-20s %-20d %-20s %-20s %s %s\n\n",p.ID,p.bedNum,p.patientname,p.patientage,p.disease,p.address,p.patientcontact,p.date);
	}
    printf("\n\n");
    fclose(fileptr);
    
	getch();	
}

int availableBed(FILE *fileptr) {
    int i;
    int freq[100] = {0};

    fileptr = fopen("Patients.txt", "r");
    rewind(fileptr);
    while (fscanf(fileptr,"%d %d %s %d %s %s %s %s",&p.ID,&p.bedNum,p.patientname,&p.patientage,p.disease,p.address,p.patientcontact,p.date)==8) {
        if(p.bedNum!=0){
		freq[p.bedNum-1]++;
		}
    }

    printf("AVAILABLE BEDS\n");
    for (i = 0; i < 25; i++) {
        if (freq[i] == 0) {
            printf("bed number: %d\n", i + 1);
        }
    }

    fclose(fileptr);
    getch();
}

//int ViewOccupiedBeds() {
//	system("cls");
//    patientBed = fopen("patientBed.txt", "r");
//    while (fscanf(patientBed, "%d %d %s %d  %s %s  %s ", &b.id, &b.bedNum, b.patientName,&b.patientcontact, b.patientAddress, b.disease, b.date) == 7) {
//		printf("%-2d %-3d %-20s %-15d  %-20s %-20s  %-20s \n", b.id, b.bedNum, b.patientName,b.patientcontact, b.patientAddress, b.disease, b.date);
//	}
//	fclose(patientBed);
//	getch();
//}

int DoctorView()
{
	system("cls");
	docfile = fopen("doctors.txt","r");
	printf("%-10s %-30s %-30s %-30s %-30s\n","ID","Doctor Name","Specialization", "Timings", "Days");
	while(fscanf(docfile,"%s %s %s %s %s",D.ID,D.DoctorName,D.Specialization,D.Timings,D.Days)==5)
	{
		printf("%-10s %-30s %-30s %-30s %-30s\n\n",D.ID,D.DoctorName,D.Specialization,D.Timings,D.Days);
	}
	fclose(docfile);
	getch();
}
int searchrecord(FILE *fileptr,FILE *historyptr){
	system("cls");
	

	char ch;
			
	
	while(ch!='a' && ch!='b' && ch!='A' && ch!='B' && ch!='1' && ch!='2')
	{
		printf("Search by:\n\n(a) ID\n(b) Name\n\nYour Choice: ");
		key = getch();
        if (key == 27)
		{
            return 0;
		}
	    scanf(" %c",&ch);
	}
   
	switch(ch)
	{
	    case 'a':
		case 'A':
		case '1':
		{
			int found, enteredID; printf("Enter the record ID you want to search: "); 
			key = getch();
            if (key == 27) {
            return 0;
			}
			scanf("%d",&enteredID);
			system("cls");
			fileptr =  fopen("Patients.txt","r");
			printf("%-10s %-20s %-20s %-20s %-20s %-20s %s %s\n","ID","Bed Number","Name","Age","Disease","Address","Contact","Bed Entry");
	        printf("----------------------------------------------------------------------------------------------------------------------------\n");
    
	        while(fscanf(fileptr,"%d %d %s %d %s %s %s %s",&p.ID,&p.bedNum,p.patientname,&p.patientage,p.disease,p.address,p.patientcontact,p.date)==8)
            {
    	       if(enteredID == p.ID)
		       {
    		       printf("%-10d %-20d %-20s %-20d %-20s %-20s %s %s\n\n",p.ID,p.bedNum,p.patientname,p.patientage,p.disease,p.address,p.patientcontact,p.date);
    		       found = 1;
		       }
		    
	        }
	 printf("\n\nAppointments for patient ID %d: \n\n", enteredID);
            printf("------------------------------\n");
            historyptr = fopen("historyfile.txt", "r");
            printf("%-10s %-20s %-20s %-20s %-20s","ID","TIME","DAY","A/V","DOCTORS NAME");
            printf("\n---------------------------------------------------------------------------------------------");
            rewind(historyptr);
            
			while (fscanf(historyptr, "%d %s %s %s %d %d %d", &h.id, h.time, h.AppointmentOrVisit,h.Date,&h.DocID,&h.timecode,&h.daycode) == 7) {
                
				if (h.id == enteredID){ //&& (strcmp(h.AppointmentOrVisit, "Appointment") == 0)) {
                    printf("\n%-10d %-20s %-20s %-20s %-20d\n",h.id, h.time, h.Date, h.AppointmentOrVisit, h.DocID);
                    
                }
            }
            fclose(historyptr);

            
            printf("\n\nVisits for patient ID %d:\n", enteredID);
            printf("------------------------------\n");
            historyptr = fopen("historyfile.txt", "r");
            printf("%-10s %-20s %-20s %-20s %-20s","ID","TIME","DAY","A/V","DOCTORS NAME");
            printf("\n-----------------------------------------------------------------------------------------------\n");
            rewind(historyptr);
			while (fscanf(historyptr, "%d %s %s %s %d %d %d", &h.id, h.time, h.AppointmentOrVisit,h.Date,&h.DocID,&h.timecode,&h.daycode) == 7) {
                if (h.id == enteredID && (strcmp(h.AppointmentOrVisit, "Visit") == 0)) {
                    printf("\n%-10d %-20s %-20s %-20s %-20d\n",h.id, h.time, h.Date, h.AppointmentOrVisit, h.DocID);
                    
                }
            }
            fclose(historyptr);

            if (!found)
                printf("Record was not found.\n");
            printf("\n\n");
            getch();
            break;

    fclose(fileptr);
	        
	        if(!found)
	        printf("Record was not found.");
            printf("\n\n");
            getch();
			
		} 
		break;
		case 'b':
		case 'B':
		case '2':
		{
			int found = 0;
			char enteredName[10]; printf("Name: "); scanf("%s",enteredName);
			fileptr =  fopen("Patients.txt","r");
			printf("%-10s %-20s %-20s %-20s %-20s %-20s %s %s\n","ID","Bed Number","Name","Age","Disease","Address","Contact","BedEntry");
	        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
    
	        while(fscanf(fileptr,"%d %d %s %d %s %s %s %s",&p.ID,&p.bedNum,p.patientname,&p.patientage,p.disease,p.address,p.patientcontact,p.date)==8)
            {
    	       if(strcmp(enteredName,p.patientname)==0)
		       {
    		       printf("%-10d %-20d %-20s %-20d %-20s %-20s %s %s\n\n",p.ID,p.bedNum,p.patientname,p.patientage,p.disease,p.address,p.patientcontact,p.date);
    		       found = 1;
		       }
		       
		
	        }
	        if(!found)
	        printf("Record was not found.");
            printf("\n\n");
			getch();
		} break;
		
		
	}

	fclose(fileptr);
}

int DoctorSearch(){
				system("cls");
				char search[50];
				char UDName[50];
				int found=0,i;
                printf("\n");
				printf("\nEnter Name Of Doctor:");
				key = getch();
                if (key == 27) {
                return 0;
		     	}
				scanf(" %[^\n]",search);
				system("cls");
				i=0;
				while(search[i]!='\0')
				{
                    	search[i]=toupper(search[i]);
                    	i++;
					}
                docfile = fopen("doctors.txt", "r");
                printf("%-10s %-30s %-30s %-30s %s\n", "ID", "Doctor Name", "Specialization", "Timings", "Days");
                printf("-----------------------------------------------------------------------------------------------------------------------------------\n");
                while (fscanf(docfile, "%s %s %s %s %s", D.ID, D.DoctorName, D.Specialization, D.Timings, D.Days) == 5) {
                    strcpy(UDName,D.DoctorName);
                    i=0;
                    while(UDName[i]!='\0'){
                    	UDName[i]=toupper(UDName[i]);
                    	i++;
					}
					if (strstr(UDName,search) != NULL) {
                    	printf("%-10s %-30s %-30s %-30s %s\n\n", D.ID, D.DoctorName, D.Specialization, D.Timings, D.Days);
                    	found=1;
					}
                }
                if(!found){
                	printf("\n%s not found\n",search);
				}
                fclose(docfile);
                getch();
}

int deleterecord(FILE *fileptr) {
	system("cls");
    int id;
    printf("\nEnter the record id you want to delete: ");
    	key = getch();
        if (key == 27)
		{
            return 0;
		}
    scanf("%d", &id);

    FILE *tempptr = fopen("temp.txt", "w");
    fileptr = fopen("Patients.txt", "r");
    int found = 0;

    rewind(fileptr);

    while (fscanf(fileptr, "%d %d %s %d %s %s %s %s", &p.ID, &p.bedNum, p.patientname, &p.patientage, p.disease, p.address, p.patientcontact, p.date) == 8) {
        if (id == p.ID) {
            found = 1;
        } else {
            fprintf(tempptr, " %d %d %s %d %s %s %s %s\n", p.ID, p.bedNum, p.patientname, p.patientage, p.disease, p.address, p.patientcontact, p.date);
        }
    }

    if (found == 1) {
        printf("\nDeleted Successfully");
    } else {
        printf("\nNot Found");
    }

    fclose(fileptr);
    fclose(tempptr);

    remove("Patients.txt");
    rename("temp.txt", "Patients.txt");

    getch();
}

int SpecializationSearch(){
				system("cls");
				char search[50],USpecialization[50];
				int found=0,i;
				printf("\nEnter Specialization Name:");
				key = getch();
                if (key == 27)
		        {
                    return 0;
		        }
				scanf(" %[^\n]",search);
				system("cls");
				i=0;
				while(search[i]!='\0'){
                    	search[i]=toupper(search[i]);
                    	i++;
					}
                docfile = fopen("doctors.txt", "r");
                printf("%-10s %-30s %-30s %-30s %s\n", "ID", "Doctor Name", "Specialization", "Timings", "Days");
                printf("---------------------------------------------------------------------------------------------------------------------------------\n");
                while (fscanf(docfile, "%s %s %s %s %s", D.ID, D.DoctorName, D.Specialization, D.Timings, D.Days) == 5) {
                	strcpy(USpecialization,D.Specialization);
                    i=0;
                    while(USpecialization[i]!='\0'){
                    	USpecialization[i]=toupper(USpecialization[i]);
                    	i++;
					}                    
					if (strstr(USpecialization,search) != NULL) {
                    	printf("%-10s %-30s %-30s %-30s %s\n\n", D.ID, D.DoctorName, D.Specialization, D.Timings, D.Days);
                    	found=1;
					}
                }
                if(!found){
                	printf("\n%s not found\n",search);
				}
                fclose(docfile);
                getch();	
}

int DeleteDoctor(){
				system("cls");
				int found=0,i;
                
    			char Delete[50];
    			found = 0;
    			printf("\nEnter ID of the Doctor to delete: ");
    			key = getch();
                if (key == 27)
		        {
                   return 0;
		        }
    			scanf(" %s", Delete);
				system("cls");
    			docfile = fopen("doctors.txt", "r");
    			FILE *tempfile = fopen("temp.txt", "w");
    			while (fscanf(docfile, "%s %s %s %s %s", D.ID, D.DoctorName, D.Specialization, D.Timings, D.Days) == 5) {
        			if (strcmp(D.ID,Delete) == 0) {
            			found = 1;
            			printf("\n%s has been deleted successfully.\n", D.DoctorName);
        				}
					else {
            			fprintf(tempfile, "%s %s %s %s %s\n", D.ID, D.DoctorName, D.Specialization, D.Timings, D.Days);
        				}
    			}

    			fclose(docfile);
    			fclose(tempfile);

    			if (!found) {
        			printf("\nDoctor with ID %s not found.\n", Delete);
    			}

    			remove("doctors.txt");
    			rename("temp.txt", "doctors.txt");

    			getch();
}

int UpdateDoctor(){
				system("cls");
				char search[50];
				int found=0;				
				printf("\nEnter ID of Doctor:");
				key = getch();
                if (key == 27)
	          	{
                   return 0;
		        }
				scanf("%s",search);
				system("cls");
                docfile = fopen("doctors.txt", "r");
                printf("%-10s %-30s %-30s %-30s %s\n", "ID", "Doctor Name", "Specialization", "Timings", "Days");
                printf("-------------------------------------------------------------------------------------------------------------------------------------\n");
                while (fscanf(docfile, "%s %s %s %s %s", D.ID, D.DoctorName, D.Specialization, D.Timings, D.Days) == 5) {             
					if ((strcmp(search,D.ID))==0) {
                    	printf("%-10s %-30s %-30s %-30s %s\n\n", D.ID, D.DoctorName, D.Specialization, D.Timings, D.Days);
                    	found=1;
					}
                }
                if(!found){
                	printf("\nDoctor With ID %s not found\n",search);
				}
                fclose(docfile);
                printf("Update: (1) Timings (2) Days (3) Back\n");
                int ch;
                scanf("%d",&ch);
 			    docfile = fopen("doctors.txt", "r");
    			FILE *tempFile = fopen("temp.txt", "w");
				if(ch==1){
    			while (fscanf(docfile, "%s %s %s %s %s", D.ID, D.DoctorName, D.Specialization, D.Timings, D.Days) == 5) {
        		if (strcmp(D.ID, search) == 0) {
            	found = 1;
            	printf("Enter Doctor Timings: ");
            	scanf(" %[^\n]", D.Timings);
            	fprintf(tempFile, "%s %s %s %s %s\n", D.ID, D.DoctorName, D.Specialization, D.Timings, D.Days);
            	printf("\nDoctor information updated successfully.\n");
        		}
        		else{
        			fprintf(tempFile, "%s %s %s %s %s\n", D.ID, D.DoctorName, D.Specialization, D.Timings, D.Days);
				}
				}
				}
				if(ch==2){
    			while (fscanf(docfile, "%s %s %s %s %s", D.ID, D.DoctorName, D.Specialization, D.Timings, D.Days) == 5) {
        		if (strcmp(D.ID, search) == 0) {
            	found = 1;
            	printf("Enter Doctor Days: ");
            	scanf(" %[^\n]", D.Days);
            	fprintf(tempFile, "%s %s %s %s %s\n", D.ID, D.DoctorName, D.Specialization, D.Timings, D.Days);
            	printf("\nDoctor information updated successfully.\n");
        		}
        		else{
        			fprintf(tempFile, "%s %s %s %s %s\n", D.ID, D.DoctorName, D.Specialization, D.Timings, D.Days);
				}
				}
				}
				fclose(docfile);
    			fclose(tempFile);
    			remove("doctors.txt");
   				rename("temp.txt", "doctors.txt");
                getch();
            }
int DischargePatientFromBed(FILE *fileptr) {
    system("cls");
	int id, found = 0;
    FILE *tempFile, *patientBed;

    printf("Enter patient id: ");
    key = getch();
        if (key == 27)
		{
            return 0;
		}
    scanf("%d", &id);

    tempFile = fopen("tempFile.txt", "w");
    fileptr = fopen("Patients.txt", "r");

    
    while (fscanf(fileptr,"%d %d %s %d %s %s %s %s",&p.ID,&p.bedNum,p.patientname,&p.patientage,p.disease,p.address,p.patientcontact,p.date)==8) {
        if (p.ID == id) {
        	p.bedNum=0;
        	strcpy(p.date,"0");
        	fprintf(tempFile, " %d %d %s %d %s %s %s %s\n",p.ID,p.bedNum,p.patientname,p.patientage,p.disease,p.address,p.patientcontact,p.date);
            found = 1;
            
        }
        else
        {
        	fprintf(tempFile, " %d %d %s %d %s %s %s %s\n",p.ID,p.bedNum,p.patientname,p.patientage,p.disease,p.address,p.patientcontact,p.date);
		}
		
		
        
}
    if(found==1)
    {
    	    printf("Patient Discharged Successfully.\n");
	}
	else
	{
		printf("Patient Not Found.\n");
	}

    fclose(fileptr);
    fclose(tempFile);
    remove("Patients.txt");
    rename("tempFile.txt", "Patients.txt");

    getch();
}

//int SearchBedByPatientName() {
//    char name[50];
 //   int found = 0;
//
//	getchar();
 //   printf("Enter Patient Name: ");
 //   scanf("%[^\n]",name);
//
  //  FILE *patientBed = fopen("patientBed.txt", "r");
    
//
  //  while (fscanf(fileptr,"%d %d %s %d %s %s %s %s",&p.ID,&p.bedNum,p.patientname,p.patientage,p.disease,p.address,p.patientcontact,p.date)==8) {
  //      if (strstr(b.patientName, name)) {
  //          found = 1;
   //         printf("%-2d %-3d %-20s %-15d  %-20s %-20s  %-20s \n", b.id, b.bedNum, b.patientName,b.patientcontact, b.patientAddress, b.disease, b.date);
   //     }
  //  }

  //  fclose(patientBed);
  //  if (found != 1) {
 //       printf("No Record Found\n");
  //  }
  //  getch();
//}
int SearchBedByContactNo(FILE *fileptr) {
    int found = 0;
    char cNum[50];
    printf("Enter Patient Contact Number: ");
    key = getch();
        if (key == 27)
		{
            return 0;
		}
    scanf("%s", cNum);

	fileptr = fopen("Patients.txt", "r");
	rewind(fileptr);
	printf("%-10s %-10s %-20s %-20s %-20s %-20s %s %s\n","ID","Bed Number","Name","Age","Disease","Address","Contact","Bed Entry");
	printf("----------------------------------------------------------------------------------------------------------------------------\n");
    
    while (fscanf(fileptr,"%d %d %s %d %s %s %s %s",&p.ID,&p.bedNum,p.patientname,&p.patientage,p.disease,p.address,p.patientcontact,p.date)==8) {
        if (strcmp(p.patientcontact,cNum)==0) {
            found = 1;
            printf("%-10d %-10d %-20s %-20d %-20s %-20s %s %s\n\n",p.ID,p.bedNum,p.patientname,p.patientage,p.disease,p.address,p.patientcontact,p.date);
        }
    }

    fclose(fileptr);
    getch();
   
}
int editrecordappoinments(FILE *historyptr, int id) {
	system("cls");
    historyptr = fopen("historyfile.txt", "a");
    h.id=id;
    DoctorView();
    printf("\nEnter appointment time for %d: ", id);
    key = getch();
        if (key == 27)
		{
            return 0;
		}
    scanf("%s", h.time); 
    
    printf("\nEnter appointment date for %d\n(Enter \"today\" for today's appointment): ", id);
    key = getch();
        if (key == 27)
		{
            return 0;
		}
    scanf("%s", h.Date); 
    
    printf("\nEnter Doctor ID for %d: ", id);
    key = getch();
        if (key == 27)
		{
            return 0;
		}
    scanf("%d",&h.DocID);
    printf("\nEnter Time Code for %d\n(0-8am 1-9am 2-10am 3-11am 4-12pm 5-1pm 6-2pm 7-3pm 8-4pm 9-5pm 10-11pm): ", id);
    key = getch();
        if (key == 27)
		{
            return 0;
		}
    scanf("%d",&h.timecode);
    printf("\nEnter Day Code for %d\n(0-Mon 1-Tue 2-Wed 3-Thu 4-Fri 5-Sat 6-Sun): ", id);
    key = getch();
        if (key == 27)
		{
            return 0;
		}
    scanf("%d",&h.daycode);
    
    strcpy(h.AppointmentOrVisit,"Appointment");

    fprintf(historyptr, "\n%d %s %s %s %d %d %d\n", h.id, h.time, h.AppointmentOrVisit,h.Date,h.DocID,h.timecode,h.daycode);
    fclose(historyptr);
    getch();
}

int editrecordvisits(FILE *historyptr, int id) {
	system("cls");
    historyptr = fopen("historyfile.txt", "a");
    h.id=id;
    DoctorView();
    printf("\nEnter appointment time for %d: ", id);
    key = getch();
        if (key == 27)
		{
            return 0;
		}
    scanf("%s", h.time); 
    
    printf("\nEnter appointment date for %d\n(Enter \"today\" for today's appointment): ", id);
    key = getch();
        if (key == 27)
		{
            return 0;
		}
    scanf("%s", h.Date); 
    
    printf("\nEnter Doctor ID for %d: ", id);
    key = getch();
        if (key == 27)
		{
            return 0;
		}
    scanf("%d",&h.DocID);
    printf("\nEnter Time Code for %d\n(0-8am 1-9am 2-10am 3-11am 4-12pm 5-1pm 6-2pm 7-3pm 8-4pm 9-5pm 10-11pm): ", id);
    key = getch();
        if (key == 27)
		{
            return 0;
		}
    scanf("%d",&h.timecode);
    printf("\nEnter Day Code for %d\n(0-Mon 1-Tue 2-Wed 3-Thu 4-Fri 5-Sat 6-Sun): ", id);
    key = getch();
        if (key == 27)
		{
            return 0;
		}
    scanf("%d",&h.daycode);
    
    strcpy(h.AppointmentOrVisit,"Visit");

    fprintf(historyptr, "%d %s %s %s %d %d %d\n", h.id, h.time, h.AppointmentOrVisit,h.Date,h.DocID,&h.timecode,h.daycode);
    fclose(historyptr);
    getch();
}

int appointments(FILE *historyptr){
	FILE *docfile;
	int **app,i,j,k=1,start,end,l;
	app = (int **)malloc(11 * sizeof(int *));
	 for (int i = 0; i < 11; i++) {
        app[i] = (int *)malloc(7 * sizeof(int));
    }
	docfile = fopen("doctors.txt","r");
	while(fscanf(docfile,"%s %s %s %s %s",D.ID,D.DoctorName,D.Specialization,D.Timings,D.Days)==5)
	{
		for(i=0;i<11;i++){
			for(j=0;j<7;j++){

					app[i][j]=-1;
			}
		}
		
		system("cls");
		printf("Avalible = 0 & Not Availible = -1\n");
		printf("\t  Doctor %d\n================================\n",k);
		printf("      %-4s %-4s %-4s %-4s %-4s %-4s %-4s","Mon","Tue","Wed","Thu","Fri","Sat","Sun");
		for(i=0;i<11;i++){
			if(i==0){
				printf("\n8 AM:");
			}
			else if(i==1){
				printf("\n9 AM:");
			}
			else if(i==2){
				printf("\n10AM:");
			}
			else if(i==3){
				printf("\n11AM:");
			}
			else if(i==4){
				printf("\n12PM:");
			}
			else if(i==5){
				printf("\n1 PM:");
			}
			else if(i==6){
				printf("\n2 PM:");
			}
			else if(i==7){
				printf("\n3 PM:");
			}
			else if(i==8){
				printf("\n4 PM:");
			}
			else if(i==9){
				printf("\n5 PM:");
			}
			else if(i==10){
				printf("\n6 PM:");
			}
			for(j=0;j<7;j++){
				if(j==0){
					if(strstr(D.Days,"Monday")!=NULL){
						if(app[i][j]==-1){
							if(strstr(D.Timings,"8")!=NULL){
								start= 0;
							}
							else if(strstr(D.Timings,"9")!=NULL){
								start= 1;
							}
							else if(strstr(D.Timings,"10")!=NULL){
								start= 2;
							}else if(strstr(D.Timings,"11")!=NULL){
								start= 3;
							}else if(strstr(D.Timings,"12")!=NULL){
								start= 4;
							}else if(strstr(D.Timings,"1")!=NULL){
								start= 5;
							}else if(strstr(D.Timings,"2")!=NULL){
								start= 6;
							}else if(strstr(D.Timings,"3")!=NULL){
								start= 7;
							}else if(strstr(D.Timings,"4")!=NULL){
								start= 8;
							}else if(strstr(D.Timings,"5")!=NULL){
								start= 9;
							}
							else if(strstr(D.Timings,"6")!=NULL){
								start= 10;
							}
							
							if(strstr(D.Timings,"8")!=NULL&&start!=0){
								end= 0;
							}
							else if(strstr(D.Timings,"9")!=NULL&&start!=1){
								end= 1;
							}
							else if(strstr(D.Timings,"10")!=NULL&&start!=2){
								end= 2;
							}else if(strstr(D.Timings,"11")!=NULL&&start!=3){
								end= 3;
							}else if(strstr(D.Timings,"12")!=NULL&&start!=4){
								end= 4;
							}else if(strstr(D.Timings,"1")!=NULL&&start!=5){
								end= 5;
							}else if(strstr(D.Timings,"2")!=NULL&&start!=6){
								end= 6;
							}else if(strstr(D.Timings,"3")!=NULL&&start!=7){
								end= 7;
							}else if(strstr(D.Timings,"4")!=NULL&&start!=8){
								end= 8;
							}else if(strstr(D.Timings,"5")!=NULL&&start!=9){
								end= 9;
							}
							else if(strstr(D.Timings,"6")!=NULL&&start!=10){
								end= 10;
							}
							for(l=start;l<=end;l++){
								app[l][0]=0;
							}
							
						}
					}
				}
				if(j==1){
					if(strstr(D.Days,"Tuesday")!=NULL){
						if(app[i][j]==-1){
							if(strstr(D.Timings,"8")!=NULL){
								start= 0;
							}
							else if(strstr(D.Timings,"9")!=NULL){
								start= 1;
							}
							else if(strstr(D.Timings,"10")!=NULL){
								start= 2;
							}else if(strstr(D.Timings,"11")!=NULL){
								start= 3;
							}else if(strstr(D.Timings,"12")!=NULL){
								start= 4;
							}else if(strstr(D.Timings,"1")!=NULL){
								start= 5;
							}else if(strstr(D.Timings,"2")!=NULL){
								start= 6;
							}else if(strstr(D.Timings,"3")!=NULL){
								start= 7;
							}else if(strstr(D.Timings,"4")!=NULL){
								start= 8;
							}else if(strstr(D.Timings,"5")!=NULL){
								start= 9;
							}
							else if(strstr(D.Timings,"6")!=NULL){
								start= 10;
							}
							
							if(strstr(D.Timings,"8")!=NULL&&start!=0){
								end= 0;
							}
							else if(strstr(D.Timings,"9")!=NULL&&start!=1){
								end= 1;
							}
							else if(strstr(D.Timings,"10")!=NULL&&start!=2){
								end= 2;
							}else if(strstr(D.Timings,"11")!=NULL&&start!=3){
								end= 3;
							}else if(strstr(D.Timings,"12")!=NULL&&start!=4){
								end= 4;
							}else if(strstr(D.Timings,"1")!=NULL&&start!=5){
								end= 5;
							}else if(strstr(D.Timings,"2")!=NULL&&start!=6){
								end= 6;
							}else if(strstr(D.Timings,"3")!=NULL&&start!=7){
								end= 7;
							}else if(strstr(D.Timings,"4")!=NULL&&start!=8){
								end= 8;
							}else if(strstr(D.Timings,"5")!=NULL&&start!=9){
								end= 9;
							}
							else if(strstr(D.Timings,"6")!=NULL&&start!=10){
								end= 10;
							}
							for(l=start;l<=end;l++){
								app[l][1]=0;
							}
							
						}
					}
				}
				if(j==2){	
					if(strstr(D.Days,"Wednesday")!=NULL){
						if(app[i][j]==-1){
							if(strstr(D.Timings,"8")!=NULL){
								start= 0;
							}
							else if(strstr(D.Timings,"9")!=NULL){
								start= 1;
							}
							else if(strstr(D.Timings,"10")!=NULL){
								start= 2;
							}else if(strstr(D.Timings,"11")!=NULL){
								start= 3;
							}else if(strstr(D.Timings,"12")!=NULL){
								start= 4;
							}else if(strstr(D.Timings,"1")!=NULL){
								start= 5;
							}else if(strstr(D.Timings,"2")!=NULL){
								start= 6;
							}else if(strstr(D.Timings,"3")!=NULL){
								start= 7;
							}else if(strstr(D.Timings,"4")!=NULL){
								start= 8;
							}else if(strstr(D.Timings,"5")!=NULL){
								start= 9;
							}
							else if(strstr(D.Timings,"6")!=NULL){
								start= 10;
							}
							
							if(strstr(D.Timings,"8")!=NULL&&start!=0){
								end= 0;
							}
							else if(strstr(D.Timings,"9")!=NULL&&start!=1){
								end= 1;
							}
							else if(strstr(D.Timings,"10")!=NULL&&start!=2){
								end= 2;
							}else if(strstr(D.Timings,"11")!=NULL&&start!=3){
								end= 3;
							}else if(strstr(D.Timings,"12")!=NULL&&start!=4){
								end= 4;
							}else if(strstr(D.Timings,"1")!=NULL&&start!=5){
								end= 5;
							}else if(strstr(D.Timings,"2")!=NULL&&start!=6){
								end= 6;
							}else if(strstr(D.Timings,"3")!=NULL&&start!=7){
								end= 7;
							}else if(strstr(D.Timings,"4")!=NULL&&start!=8){
								end= 8;
							}else if(strstr(D.Timings,"5")!=NULL&&start!=9){
								end= 9;
							}
							else if(strstr(D.Timings,"6")!=NULL&&start!=10){
								end= 10;
							}
							for(l=start;l<=end;l++){
								app[l][2]=0;
							}
							
						}
					}
				}
				if(j==3){	
					if(strstr(D.Days,"Thursday")!=NULL){
						if(app[i][j]==-1){
							if(strstr(D.Timings,"8")!=NULL){
								start= 0;
							}
							else if(strstr(D.Timings,"9")!=NULL){
								start= 1;
							}
							else if(strstr(D.Timings,"10")!=NULL){
								start= 2;
							}else if(strstr(D.Timings,"11")!=NULL){
								start= 3;
							}else if(strstr(D.Timings,"12")!=NULL){
								start= 4;
							}else if(strstr(D.Timings,"1")!=NULL){
								start= 5;
							}else if(strstr(D.Timings,"2")!=NULL){
								start= 6;
							}else if(strstr(D.Timings,"3")!=NULL){
								start= 7;
							}else if(strstr(D.Timings,"4")!=NULL){
								start= 8;
							}else if(strstr(D.Timings,"5")!=NULL){
								start= 9;
							}
							else if(strstr(D.Timings,"6")!=NULL){
								start= 10;
							}
							
							if(strstr(D.Timings,"8")!=NULL&&start!=0){
								end= 0;
							}
							else if(strstr(D.Timings,"9")!=NULL&&start!=1){
								end= 1;
							}
							else if(strstr(D.Timings,"10")!=NULL&&start!=2){
								end= 2;
							}else if(strstr(D.Timings,"11")!=NULL&&start!=3){
								end= 3;
							}else if(strstr(D.Timings,"12")!=NULL&&start!=4){
								end= 4;
							}else if(strstr(D.Timings,"1")!=NULL&&start!=5){
								end= 5;
							}else if(strstr(D.Timings,"2")!=NULL&&start!=6){
								end= 6;
							}else if(strstr(D.Timings,"3")!=NULL&&start!=7){
								end= 7;
							}else if(strstr(D.Timings,"4")!=NULL&&start!=8){
								end= 8;
							}else if(strstr(D.Timings,"5")!=NULL&&start!=9){
								end= 9;
							}
							else if(strstr(D.Timings,"6")!=NULL&&start!=10){
								end= 10;
							}
							for(l=start;l<=end;l++){
								app[l][3]=0;
							}
							
						}
					}
				}
				if(j==4){	
					if(strstr(D.Days,"Friday")!=NULL){
						if(app[i][j]==-1){
							if(strstr(D.Timings,"8")!=NULL){
								start= 0;
							}
							else if(strstr(D.Timings,"9")!=NULL){
								start= 1;
							}
							else if(strstr(D.Timings,"10")!=NULL){
								start= 2;
							}else if(strstr(D.Timings,"11")!=NULL){
								start= 3;
							}else if(strstr(D.Timings,"12")!=NULL){
								start= 4;
							}else if(strstr(D.Timings,"1")!=NULL){
								start= 5;
							}else if(strstr(D.Timings,"2")!=NULL){
								start= 6;
							}else if(strstr(D.Timings,"3")!=NULL){
								start= 7;
							}else if(strstr(D.Timings,"4")!=NULL){
								start= 8;
							}else if(strstr(D.Timings,"5")!=NULL){
								start= 9;
							}
							else if(strstr(D.Timings,"6")!=NULL){
								start= 10;
							}
							
							if(strstr(D.Timings,"8")!=NULL&&start!=0){
								end= 0;
							}
							else if(strstr(D.Timings,"9")!=NULL&&start!=1){
								end= 1;
							}
							else if(strstr(D.Timings,"10")!=NULL&&start!=2){
								end= 2;
							}else if(strstr(D.Timings,"11")!=NULL&&start!=3){
								end= 3;
							}else if(strstr(D.Timings,"12")!=NULL&&start!=4){
								end= 4;
							}else if(strstr(D.Timings,"1")!=NULL&&start!=5){
								end= 5;
							}else if(strstr(D.Timings,"2")!=NULL&&start!=6){
								end= 6;
							}else if(strstr(D.Timings,"3")!=NULL&&start!=7){
								end= 7;
							}else if(strstr(D.Timings,"4")!=NULL&&start!=8){
								end= 8;
							}else if(strstr(D.Timings,"5")!=NULL&&start!=9){
								end= 9;
							}
							else if(strstr(D.Timings,"6")!=NULL&&start!=10){
								end= 10;
							}
							for(l=start;l<=end;l++){
								app[l][4]=0;
							}
							
						}
					}
				}
				if(j==5){	
					if(strstr(D.Days,"Saturday")!=NULL){
						if(app[i][j]==-1){
							if(strstr(D.Timings,"8")!=NULL){
								start= 0;
							}
							else if(strstr(D.Timings,"9")!=NULL){
								start= 1;
							}
							else if(strstr(D.Timings,"10")!=NULL){
								start= 2;
							}else if(strstr(D.Timings,"11")!=NULL){
								start= 3;
							}else if(strstr(D.Timings,"12")!=NULL){
								start= 4;
							}else if(strstr(D.Timings,"1")!=NULL){
								start= 5;
							}else if(strstr(D.Timings,"2")!=NULL){
								start= 6;
							}else if(strstr(D.Timings,"3")!=NULL){
								start= 7;
							}else if(strstr(D.Timings,"4")!=NULL){
								start= 8;
							}else if(strstr(D.Timings,"5")!=NULL){
								start= 9;
							}
							else if(strstr(D.Timings,"6")!=NULL){
								start= 10;
							}
							
							if(strstr(D.Timings,"8")!=NULL&&start!=0){
								end= 0;
							}
							else if(strstr(D.Timings,"9")!=NULL&&start!=1){
								end= 1;
							}
							else if(strstr(D.Timings,"10")!=NULL&&start!=2){
								end= 2;
							}else if(strstr(D.Timings,"11")!=NULL&&start!=3){
								end= 3;
							}else if(strstr(D.Timings,"12")!=NULL&&start!=4){
								end= 4;
							}else if(strstr(D.Timings,"1")!=NULL&&start!=5){
								end= 5;
							}else if(strstr(D.Timings,"2")!=NULL&&start!=6){
								end= 6;
							}else if(strstr(D.Timings,"3")!=NULL&&start!=7){
								end= 7;
							}else if(strstr(D.Timings,"4")!=NULL&&start!=8){
								end= 8;
							}else if(strstr(D.Timings,"5")!=NULL&&start!=9){
								end= 9;
							}
							else if(strstr(D.Timings,"6")!=NULL&&start!=10){
								end= 10;
							}
							for(l=start;l<=end;l++){
								app[l][5]=0;
							}
							
						}
					}
				}
				if(j==6){	
					if(strstr(D.Days,"Sunday")!=NULL){
						if(app[i][j]==-1){
							if(strstr(D.Timings,"8")!=NULL){
								start= 0;
							}
							else if(strstr(D.Timings,"9")!=NULL){
								start= 1;
							}
							else if(strstr(D.Timings,"10")!=NULL){
								start= 2;
							}else if(strstr(D.Timings,"11")!=NULL){
								start= 3;
							}else if(strstr(D.Timings,"12")!=NULL){
								start= 4;
							}else if(strstr(D.Timings,"1")!=NULL){
								start= 5;
							}else if(strstr(D.Timings,"2")!=NULL){
								start= 6;
							}else if(strstr(D.Timings,"3")!=NULL){
								start= 7;
							}else if(strstr(D.Timings,"4")!=NULL){
								start= 8;
							}else if(strstr(D.Timings,"5")!=NULL){
								start= 9;
							}
							else if(strstr(D.Timings,"6")!=NULL){
								start= 10;
							}
							
							if(strstr(D.Timings,"8")!=NULL&&start!=0){
								end= 0;
							}
							else if(strstr(D.Timings,"9")!=NULL&&start!=1){
								end= 1;
							}
							else if(strstr(D.Timings,"10")!=NULL&&start!=2){
								end= 2;
							}else if(strstr(D.Timings,"11")!=NULL&&start!=3){
								end= 3;
							}else if(strstr(D.Timings,"12")!=NULL&&start!=4){
								end= 4;
							}else if(strstr(D.Timings,"1")!=NULL&&start!=5){
								end= 5;
							}else if(strstr(D.Timings,"2")!=NULL&&start!=6){
								end= 6;
							}else if(strstr(D.Timings,"3")!=NULL&&start!=7){
								end= 7;
							}else if(strstr(D.Timings,"4")!=NULL&&start!=8){
								end= 8;
							}else if(strstr(D.Timings,"5")!=NULL&&start!=9){
								end= 9;
							}
							else if(strstr(D.Timings,"6")!=NULL&&start!=10){
								end= 10;
							}
							for(l=start;l<=end;l++){
								app[l][6]=0;
							}
							
						}
					}
				}
				historyptr = fopen("historyfile.txt", "r");
				while (fscanf(historyptr, "%d %s %s %s %d %d %d", &h.id, h.time, h.AppointmentOrVisit,h.Date,&h.DocID,&h.timecode,&h.daycode) == 7) {
				if(k==h.DocID && !strcmp(h.Date,"today")){
				app[h.timecode][h.daycode]=h.id;
				}
				}
				printf(" %-4d",app[i][j]);
			}
		}
		getch();
		k++;
	}
	fclose(docfile);
	for (int i = 0; i < 11; i++) {
        free(app[i]);
    }
    free(app);
}
int removeappointment(FILE *historyptr){
	FILE *temp;
	temp=fopen("temp.txt", "w");
	system("cls");
	historyptr = fopen("historyfile.txt", "r");
	int id;
	printf("enter ID of patient: ");
	scanf("%d",&id);
	while (fscanf(historyptr, "%d %s %s %s %d %d %d", &h.id, h.time, h.AppointmentOrVisit,h.Date,&h.DocID,&h.timecode,&h.daycode) == 7) {
		if(id==h.id&&!strcmp(h.Date,"today")){
			
		}
		else{
			fprintf(temp, "%d %s %s %s %d %d %d\n", h.id, h.time, h.AppointmentOrVisit,h.Date,h.DocID,&h.timecode,h.daycode);
		}
	}
	fclose(temp);
	fclose(historyptr);
	remove("historyfile.txt");
	rename("temp.txt","historyfile.txt");
}



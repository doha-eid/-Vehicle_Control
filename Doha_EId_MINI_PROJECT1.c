#include<stdio.h>
#include<string.h>
void System_State();
void Sensor_Set_Menu();
void Set_Traffic_light();
void Room_Temperature_data();
void Engine_Temperature_data();
void print();
int Room_Temp= 15;
int Engine_Temp=135;
int vechile_speed=0;
unsigned  AC;
unsigned  Engine;
unsigned  Engine_Temperature_Controller=0;
#define WITH_ENGINE_TEMP_CONTROLLER 1
 void display_AC (unsigned AC){
	 if (AC==1)
	 {
		 printf("AC is ON \n ");
	 }
	 else
	 {
		 printf("AC is OFF \n");
	 }

 }
 void display_Engine(unsigned Engine )
 {
	 	 if (Engine==1)
	 	 {
	 		 printf("Engine is ON \n");
	 	 }
	 	 else
	 	 {
	 		 printf("Engine is OFF \n");
	 	 }

	  }
#if  ( WITH_ENGINE_TEMP_CONTROLLER==1)
 void display_Engine_Temperature_Controller(unsigned Engine_Temperature_Controller )
 {
	 	 if (Engine_Temperature_Controller==1)
	 	 {
	 		 printf("Engine_Temperature_Controller is ON \n");
	 	 }
	 	 else
	 	 {
	 		 printf("Engine_Temperature_Controller is OFF \n");
	 	 }

	  }

#endif
int main(void)
{
	setvbuf(stdout, NULL, _IONBF, 0);
	setvbuf(stderr, NULL, _IONBF, 0);
	System_State();
}

void System_State(void)
{
/* the function that used to  decide the state of the engine (on-off-quit)  */
	char STATE,State;
	printf("Please enter the state you want :\n");
	printf("a.Turn on the vehicle engine\n");
	printf("b.Turn off the vehicle engine\n");
	printf("c.Quit the system \n");
	scanf(" %c",&STATE);
	switch(STATE)
	{
	case 'a'://if choose turn on the vechile got to sensor_set_menu function to continue in the code
		printf("Turn on the vehicle engine\n");
		Sensor_Set_Menu();
		break;
	case 'b'://if choose turn off go back to the first list to make sure he want to turn off the program
		printf("Turn off the vehicle engine\n");
		printf("a.Turn on the vehicle engine\n");
					printf("b.Turn off the vehicle engine\n");
					printf("c.Quit the system \n");
					scanf(" %c",&State);
					switch(State)
					{
					case 'a'://go to function sensor set menu
						Sensor_Set_Menu();
						break;
					case 'b':// print the statement turn off and turn off the program
						printf("Turn OFF the vehicle engine\n");
						break;
					case 'c'://print the statement and close the program and if he want to use the program again run it again

						printf("Quit the system \n");
						break;
					}
				break;
	case 'c'://print the statement and close the program and if he want to use the program again run it again
		printf("Quit the system \n");
				break;
	default ://if he push down wrong character
		printf("Invalid character \n");
		break;
	}
}
 void Sensor_Set_Menu(void)
 {   // a function to decide what condition you would like to know
	 char OPTION;
     printf("a. Turn off the engine. \n");
	 printf("b. Set the traffic light color. \n");
	 printf("c. Set the room temperature (Temperature Sensor) \n");
	 printf("d. Set the engine temperature (Engine Temperature Sensor)\n");
	 scanf(" %c",&OPTION);
	switch (OPTION)
	{
	case 'a':
		    printf(" Turn OFF the engine. \n");
		    System_State(); // call the function to print the first list to decide what he would like to do
       break;
	case 'b':
			printf("Set The Traffic Light Color. \n");
			 Set_Traffic_light();//go to the function
			 Sensor_Set_Menu();// to print the list to complete the program
			break;
	case 'c':// set the room temperature
			printf("Set The Room Temperature (Temperature Sensor) \n");
			printf("Enter the required room temperature \n");
			scanf(" %d",&Room_Temp);
			print();
			Sensor_Set_Menu();
			break;
	case 'd'://set the engine temperature
#if ( WITH_ENGINE_TEMP_CONTROLLER==1)

		printf("Set The Engine Temperature (Engine Temperature Sensor)\n");
			printf("Enter the required engine temperature \n");
			scanf(" %d",&Engine_Temp);
			print();
			Sensor_Set_Menu();
#endif
			break;
	}

 }
void Set_Traffic_light(void)
{ // function to set traffic light
	char OPTION;
	char Traffic_light;
	 printf("Enter the required color: 'G','O','R' \n");
	 scanf(" %c",&Traffic_light);

	 if(Traffic_light=='G')
	 {

		 vechile_speed=100;
		print();
	 }
	 else if (Traffic_light=='O')
	 {

		 vechile_speed=30;
		 AC=1;
		 display_AC(AC);
		 Room_Temp=Room_Temp*(5/4)+1;
#if ( WITH_ENGINE_TEMP_CONTROLLER==1)

		        Engine=1;
				 display_Engine(Engine);
				 Engine_Temp= Engine_Temp*(5/4)+1;
				 print();
#endif

	 }
	 else if (Traffic_light=='R')
	 	 {

		 vechile_speed=0;
		 print();
	 	 }
	 Sensor_Set_Menu();
}
void  Room_Temperature_data(void)
{ // function to set the room temperature and decide the state of AC

    char OPTION;
	if(Room_Temp<10)
	{
		Room_Temp=20;
	 AC=1;
	 display_AC(AC);
	}
	else if (Room_Temp>30)
	{
		Room_Temp=20;
     AC=1;
     display_AC(AC);
	}
	else if((Room_Temp>10)|(Room_Temp<30))
{
		Room_Temp;
		AC=0;
		display_AC(AC);
}
}
void Engine_Temperature_data(void)
{ // set the engine temperature and set the engine temperature controller
	if(Engine_Temp<100)
	{
		Engine_Temp=125;
		Engine_Temperature_Controller=1;
		display_Engine_Temperature_Controller(Engine_Temperature_Controller);
	}
	else if (Engine_Temp>150)
	{
		Engine_Temp=125;
		 Engine_Temperature_Controller=1;
		 display_Engine_Temperature_Controller(Engine_Temperature_Controller);
	}
	else if ((Engine_Temp>100)|(Engine_Temp<150))
	{
		Engine_Temp;
		 Engine_Temperature_Controller=0;
		 display_Engine_Temperature_Controller(Engine_Temperature_Controller);
	}
}
void print(void)
{ // function to print the states that would apper on the consle
             AC=1;
	         Engine=1;
	         display_Engine(Engine);
			 Room_Temperature_data();
			 printf("Vehicle Speed =%d Km/Hr\n",vechile_speed);
			 printf("Room Temperature = %d c\n",Room_Temp);
#if ( WITH_ENGINE_TEMP_CONTROLLER==1)
				 Engine_Temperature_data();
				 printf("Engine Temperature= %d c\n ",Engine_Temp);
#endif


}

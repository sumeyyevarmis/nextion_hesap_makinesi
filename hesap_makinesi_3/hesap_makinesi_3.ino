#include "Nextion.h"

SoftwareSerial HMISerial(0, 1); // RX, TX

#define NETXION_PAGE_ID 0
#define NETXION_TEXT 1
#define NETXION_BUTTON_1 2
#define NETXION_BUTTON_2 3
#define NETXION_BUTTON_3 4
#define NETXION_BUTTON_4 5
#define NETXION_BUTTON_5 6
#define NETXION_BUTTON_6 7
#define NETXION_BUTTON_7 8
#define NETXION_BUTTON_8 9
#define NETXION_BUTTON_9 10
#define NETXION_BUTTON_0 11
#define NETXION_BUTTON_ENTER 12
#define NETXION_BUTTON_CL 13
#define NETXION_BUTTON_Plus 14
#define NETXION_BUTTON_Moins 15
#define NETXION_BUTTON_Mul 16
#define NETXION_BUTTON_Div 17

NexButton Button_0  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_0, "Btn0");
NexButton Button_1  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_1, "Btn1");
NexButton Button_2  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_2, "Btn2");
NexButton Button_3  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_3, "Btn3");
NexButton Button_4  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_4, "Btn4");
NexButton Button_5  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_5, "Btn5");
NexButton Button_6  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_6, "Btn6");
NexButton Button_7  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_7, "Btn7");
NexButton Button_8  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_8, "Btn8");
NexButton Button_9  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_9, "Btn9");
NexButton Button_CL  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_CL, "BtnCL");
NexButton Button_ENTER  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_ENTER, "BtnEnter");
NexButton Button_Plus  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_Plus, "BtnPlus");
NexButton Button_Moins  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_Moins, "BtnMoins");
NexButton Button_Mul  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_Mul, "BtnMul");
NexButton Button_Div  = NexButton(NETXION_PAGE_ID, NETXION_BUTTON_Div, "BtnDiv");

NexText Text = NexText(NETXION_PAGE_ID, NETXION_TEXT, "Text");

 
NexTouch *nex_listen_list[] = 
{
    &Button_0,
    &Button_1,
    &Button_2,
    &Button_3,
    &Button_4,
    &Button_5,
    &Button_6,
    &Button_7,
    &Button_8,
    &Button_9,
    &Button_CL,
    &Button_ENTER,
    &Button_Plus,
    &Button_Moins,
    &Button_Mul,
    &Button_Div,
    NULL
};

unsigned char N_Str[10]={0}, i=0, Affichage[10];
float Pile[4]={0}, N; 

void button_0_Callback(void *ptr)
{


  N_Str[i]='0';
  Text.setText(N_Str);
  i++;
}

void button_1_Callback(void *ptr)
{
  N_Str[i]='1';
  Text.setText(N_Str);
  i++;
}

void button_2_Callback(void *ptr)
{
  N_Str[i]='2';
  Text.setText(N_Str);
  i++;
}

void button_3_Callback(void *ptr)
{
  N_Str[i]='3';
  Text.setText(N_Str);  
  i++;
}

void button_4_Callback(void *ptr)
{
  N_Str[i]='4';
  Text.setText(N_Str);
  i++;
}

void button_5_Callback(void *ptr)
{
  N_Str[i]='5';
  Text.setText(N_Str);
  i++;
}

void button_6_Callback(void *ptr)
{
  N_Str[i]='6';
  Text.setText(N_Str); 
  i++;
}

void button_7_Callback(void *ptr)
{
  N_Str[i]='7';
  Text.setText(N_Str);
  i++;
}

void button_8_Callback(void *ptr)
{
  N_Str[i]='8';
  Text.setText(N_Str);
  i++;
}

void button_9_Callback(void *ptr)
{
  N_Str[i]='9';
  Text.setText(N_Str); 
  i++;
}


void button_CL_Callback(void *ptr)
{
  Text.setText("");
  
  //Remise à "0" de N_Str
  for(int b=0; b<10 ; b++) N_Str[b]=0;  

  //Remise à "0" de la pile
  for(int b=0; b<4 ; b++) Pile[b]=0; 
}

void button_Plus_Callback(void *ptr)
{
  N=atof(N_Str);
  //Décalage de la pile vers le haut
  if(N!=0)
  {
    Pile[3]=Pile[2];
    Pile[2]=Pile[1];
    Pile[1]=Pile[0];

    Pile[0]=N;
  }

  Pile[0] = Pile[0] + Pile[1];
  dtostrf(Pile[0],6,3, Affichage);
  Text.setText(Affichage); 

  Pile[1]=Pile[2];
  Pile[2]=Pile[3];
  Pile[3]=0;

  for(int b=0; b<10 ; b++) N_Str[b]=0;  
  i=0;
}

void button_Moins_Callback(void *ptr)
{
  N=atof(N_Str);

  if(N!=0)
  {
    Pile[3]=Pile[2];
    Pile[2]=Pile[1];
    Pile[1]=Pile[0];

    Pile[0]=N;
  }

  Pile[0] = Pile[1] - Pile[0];
  dtostrf(Pile[0],6,3, Affichage);
  Text.setText(Affichage); 

  Pile[1]=Pile[2];
  Pile[2]=Pile[3];
  Pile[3]=0;

  for(int b=0; b<10 ; b++) N_Str[b]=0;  
  i=0;
}

void button_Mul_Callback(void *ptr)
{
  N=atof(N_Str);

  if(N!=0)
  {
    Pile[3]=Pile[2];
    Pile[2]=Pile[1];
    Pile[1]=Pile[0];

    Pile[0]=N;
  }

  Pile[0] = Pile[0] * Pile[1];
  dtostrf(Pile[0],6,3, Affichage);
  Text.setText(Affichage); 

  Pile[1]=Pile[2];
  Pile[2]=Pile[3];
  Pile[3]=0;

  for(int b=0; b<10 ; b++) N_Str[b]=0;  
  i=0;
}

void button_Div_Callback(void *ptr)
{
  N=atof(N_Str);
  
  if(N!=0)
  {
    Pile[3]=Pile[2];
    Pile[2]=Pile[1];
    Pile[1]=Pile[0];

    Pile[0]=N;
  }

  Pile[0] = Pile[1] / Pile[0];
  dtostrf(Pile[0],6,3, Affichage);
  Text.setText(Affichage); 

  Pile[1]=Pile[2];
  Pile[2]=Pile[3];
  Pile[3]=0;

  for(int b=0; b<10 ; b++) N_Str[b]=0;  
  i=0;
  
}

void button_Enter_Callback(void *ptr)
{
 
  Pile[3]=Pile[2];
  Pile[2]=Pile[1];
  Pile[1]=Pile[0];


  Pile[0]=atof(N_Str);

  Text.setText("");

  for(int b=0; b<10 ; b++) N_Str[b]=0;  
  i=0;
}



void setup() {

  nexInit();

  Button_0.attachPush(button_0_Callback, &Button_0);
  Button_1.attachPush(button_1_Callback, &Button_1);
  Button_2.attachPush(button_2_Callback, &Button_2);
  Button_3.attachPush(button_3_Callback, &Button_3);
  Button_4.attachPush(button_4_Callback, &Button_4);
  Button_5.attachPush(button_5_Callback, &Button_5);
  Button_6.attachPush(button_6_Callback, &Button_6);
  Button_7.attachPush(button_7_Callback, &Button_7);
  Button_8.attachPush(button_8_Callback, &Button_8);
  Button_9.attachPush(button_9_Callback, &Button_9);
  Button_CL.attachPush(button_CL_Callback, &Button_CL);
  Button_ENTER.attachPush(button_Enter_Callback, &Button_ENTER);
  Button_Plus.attachPush(button_Plus_Callback, &Button_Plus);
  Button_Moins.attachPush(button_Moins_Callback, &Button_Moins);
  Button_Mul.attachPush(button_Mul_Callback, &Button_Mul);
  Button_Div.attachPush(button_Div_Callback, &Button_Div);
  
}

void loop() {
    nexLoop(nex_listen_list);

}

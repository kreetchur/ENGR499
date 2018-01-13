//Code Description

//This was used to figure out how the redboard is configured
//typing the characters 1-9 and a-d in the serial monitor should toggle the corresponding digital pin. 

// Declare global variables up here
int incomingByte;
int testTime = 250;
void setup() {
  // put your setup code here, to run once:

  //Open Serial Communication
  Serial.begin(9600);

  //Pin Setup
  //pins 0 and 1 are used for USB communication. Leave them alone. The rest of these are the digital pins 2-12
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT); // This one links to the bright blue LED on the redboard. Very effective.
}


void loop() {
  // put your main code here, to run repeatedly:

  Serial.println("Hello World");      //Test Serial comm by printing Hello World
  delay(1000);                        //Pause for 1000 ms
  incomingByte = Serial.read();       //Read Serial input

  // If the Serial.read() function finds nothing, it returns -1, which has no pin associated with it. That might be bad.
  if (incomingByte > 0)
  {
    Serial.print("I received: ");     //Print human text
    int pinWrite = asciiTrans(incomingByte);  //Convert ascii to a valid pin
    blink(pinWrite, testTime);                //Blink the pin
    Serial.println(incomingByte, DEC);        //Write stuff
  }
}

//Toggles a pin from high to low for a give amount of time. Does not check if the input is a valid pin. 
void blink(int pin, int time)
{
  digitalWrite(pin, HIGH);
  delay(time);
  digitalWrite(pin, LOW);
  delay(time);
}

//Translates Serial input from Ascii coding to the intended pin code. Very limited, no safety protocols. 
int asciiTrans(int code)
{
  switch(code)
  {
    case 49:
      return 1;
    break;
    case 50:
      return 2;
    break;
    case 51:
      return 3;
    break;
    case 52:
      return 4;
    break;
    case 53:
      return 5;
    break;
    case 54:
      return 6;
    break;
    case 55:
      return 7;
    break;
    case 56:
      return 8;
    break;
    case 57:
      return 9;
    break;
    case 97:
      return 10;
    break;
    case 98:
      return 11;
    break;
    case 99:
      return 12;
    break;
    case 100:
      return 13;
    break;              
  }
}


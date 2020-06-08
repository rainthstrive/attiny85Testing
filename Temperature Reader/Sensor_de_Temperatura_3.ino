int DS_14 = 2;
int STCP_12 = 1;
int SHCP_11 = 0;

int j = 0; // Second Digit

int digit1 = 4; // 1st Digit on Attiny
int digit2 = 5; // 2nd Digit on Attiny

int Digit[10] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103};

int sensor;    // Stores initial value from A3
float temperature;  // First centigrades reading
int finalTemp;   // int temperature reading

short numberTodisplay[2]; // Array that stores individual digits for the 7seg Display

void setup() {
  pinMode(STCP_12, OUTPUT);
  pinMode(DS_14, OUTPUT);
  pinMode(SHCP_11, OUTPUT);
  pinMode(digit1, OUTPUT);
  pinMode(digit2, OUTPUT);
}

void loop() {

  sensor = analogRead(A3);
  temperature = ((sensor * 5000.0) / 1023) / 10;  // Converts reading into a normal value
  
  finalTemp = int(temperature);
  int aux = 0;
  while (finalTemp) {
    numberTodisplay[aux++] = finalTemp % 10;
    finalTemp /= 10;
  }
  
  int i = numberTodisplay[0];
  j = numberTodisplay[1];

  for (int m = 0; m < 65; m++)
  {
    display1();
    digitalWrite(STCP_12, LOW);
    shiftOut(DS_14, SHCP_11, MSBFIRST, Digit[i]);
    digitalWrite(STCP_12, HIGH);
    delay(5);

    display2();
    digitalWrite(STCP_12, LOW);
    shiftOut(DS_14, SHCP_11, MSBFIRST, Digit[j]);
    digitalWrite(STCP_12, HIGH);
    delay(5);
  }
}

void display1()
{
  digitalWrite(digit1, 1);
  digitalWrite(digit2, 0);
}
void display2()
{
  digitalWrite(digit1, 0);
  digitalWrite(digit2, 1);
}

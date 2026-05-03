// C++ code
//
#include <Keypad.h>


const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[ROWS] = {9, 8, 7, 6};
byte colPins[COLS] = {5, 4, 3, 2};

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);


int greenLED = 11;
int redLED = 10;
int buzzer = 12;


String correctPassword = "1234";
String inputPassword = "";


int attempts = 0;
const int maxAttempts = 3;
bool isLocked = false;
unsigned long lockStartTime = 0;
const unsigned long lockDuration = 30000; 

void setup() {
  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  Serial.begin(9600);
  Serial.println("Enter Password:");
}

void loop() {

 
  if (isLocked) {
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);

    if (millis() - lockStartTime >= lockDuration) {
      isLocked = false;
      attempts = 0;

      digitalWrite(redLED, LOW);
      digitalWrite(buzzer, LOW);

      Serial.println("\nSystem Unlocked. Try Again:");
    }
    return;
  }

  char key = keypad.getKey();

  if (key) {

    
    if (key == '*') {
      inputPassword = "";
      Serial.println("\nInput Cleared");
      return;
    }

   
    if (key == '#') {

      if (inputPassword.length() == 0) {
        Serial.println("\nNo Input!");
        return;
      }

      if (inputPassword == correctPassword) {
        Serial.println("\nAccess Granted");

        digitalWrite(greenLED, HIGH);
        delay(2000);
        digitalWrite(greenLED, LOW);

        attempts = 0; 
      } else {
        attempts++;
        Serial.println("\nAccess Denied");
        Serial.print("Attempts: ");
        Serial.println(attempts);

        digitalWrite(redLED, HIGH);

        for (int i = 0; i < 3; i++) {
          digitalWrite(buzzer, HIGH);
          delay(200);
          digitalWrite(buzzer, LOW);
          delay(200);
        }

        digitalWrite(redLED, LOW);

        if (attempts >= maxAttempts) {
          isLocked = true;
          lockStartTime = millis();
          Serial.println("Too many attempts! SYSTEM LOCKED.");
        }
      }

      inputPassword = "";
      Serial.println("\nEnter Password:");
      return;
    }

    
    inputPassword += key;
    Serial.print("*"); 
  }
}
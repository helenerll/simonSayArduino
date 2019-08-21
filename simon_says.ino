int level = 1;


class Test {
  
  public :
    Test() {

    }
    int bonjout;
};

Test t;



const int difficulty = 5;
int sequence[difficulty];
int mySequence[difficulty];
int gameTryied = 0;
int speed = 800;

//setup green light/button
const int greenLed = 8;
const int greenButton = 2;
int greenButtonState = 0;
//end green button setup

//setup red light/button
const int redLed = 9;
const int redButton = 4;
int redButtonState = 0;
//end red light/button setup

//setup yellow light
const int yellowLed = 10;
const int yellowButton = 5;
int yellowButtonState = 0;
//end setup yellow light/button end

//setup white light/button
const int whiteLed = 11;
const int whiteButton = 6;
int whiteButtonState = 0;
//end setup white light/button

void setup() {
  // put your setup code here, to run once:
  pinMode(greenLed, OUTPUT);
  pinMode(greenButton, INPUT);

  pinMode(redLed, OUTPUT);
  pinMode(redButton, INPUT);

  pinMode(yellowLed, OUTPUT);
  pinMode(yellowButton, INPUT);

  pinMode(whiteLed, OUTPUT);
  pinMode(whiteButton, INPUT);

  Serial.begin(9600);

  onStart();
  everythingLow();
  delay(500);
}

void loop() {
  // put your main code here, to run repeatedly:
  greenButtonState = digitalRead(greenButton);
  redButtonState = digitalRead(redButton);
  yellowButtonState = digitalRead(yellowButton);
  whiteButtonState = digitalRead(whiteButton);

  //initButton();
  int gameTryied = 0;
  if (level < 10) {
    generateSequence();
    getSequence();
  }
}

void initButton() {
  Serial.println("init button");
  lightUpLed(greenButtonState, greenLed);
  lightUpLed(redButtonState, redLed);
  lightUpLed(yellowButtonState, yellowLed);
  lightUpLed(whiteButtonState, whiteLed);
}

void lightUpLed(int buttonState, int ledColor) {
  if (buttonState == 1) {
    digitalWrite(ledColor, HIGH);
  }
  else {
    digitalWrite(ledColor, LOW);
  }
}

void onStart() {
  digitalWrite(greenLed, HIGH);
  delay(500);
  digitalWrite(redLed, HIGH);
  delay(500);
  digitalWrite(yellowLed, HIGH);
  delay(500);
  digitalWrite(whiteLed, HIGH);
  delay(500);
}

void generateSequence() {
  randomSeed(analogRead(A0));
  for (int i = 0; i < 5; i++) {
    Serial.println(i);
    int randomNumber = random(8, 12);
    Serial.println(randomNumber);
    sequence[i] = randomNumber;
    Serial.println(sequence[i]);
  }
  for (int s = 0; s < 5; s++) {
    digitalWrite(sequence[s], HIGH);
    delay(speed);
    digitalWrite(sequence[s], LOW);
    delay(speed);
  }

}

void showSequence(int sequence[]) {
  for (int s = 0; s < 5; s++) {
    digitalWrite(sequence[s], HIGH);
    delay(500);
    digitalWrite(sequence[s], LOW);
  }
}

void everythingLow() {
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(whiteLed, LOW);
}

void everythingHigh() {
  digitalWrite(greenLed, HIGH);
  digitalWrite(redLed, HIGH);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(whiteLed, HIGH);
}

void getSequence() {
  int flag = 0;
  Serial.print("try again");
  for (int i = 0; i < 5; i++) {
    flag = 0;
    while (flag == 0) {
      if (digitalRead(greenButton) == 1) {
        digitalWrite(greenLed, HIGH);
        mySequence[i] = greenLed;
        flag = 1;
        delay(200);
        Serial.println("green button");
        if (mySequence[i] != sequence[i]) {
          Serial.println("green wrong");
          wrong_sequence();
          //return;
        }
        digitalWrite(greenLed, LOW);
      }

      if (digitalRead(redButton) == 1) {
        digitalWrite(redLed, HIGH);
        mySequence[i] = redLed;
        flag = 1;
        delay(200);
        Serial.println("red button");
        if (mySequence[i] != sequence[i]) {
          Serial.println("red wrong");
          wrong_sequence();
          //return;
        }
        digitalWrite(redLed, LOW);
      }

      if (digitalRead(yellowButton) == 1) {
        digitalWrite(yellowLed, HIGH);
        mySequence[i] = yellowLed;
        flag = 1;
        delay(200);
        Serial.println("yellow button");
        if (mySequence[i] != sequence[i]) {
          Serial.println("yellow wrong");
          wrong_sequence();
          //return;
        }
        digitalWrite(yellowLed, LOW);
      }

      if (digitalRead(whiteButton) == 1) {
        digitalWrite(whiteLed, HIGH);
        mySequence[i] = whiteLed;
        flag = 1;
        delay(200);
        Serial.println("white button");
        if (mySequence[i] != sequence[i]) {
          Serial.println("white wrong");
          wrong_sequence();
          //return;
        }
        digitalWrite(whiteLed, LOW);
      }
    }
    Serial.println(" ");
    Serial.println(mySequence[i]);
  }
  right_sequence();
}

void right_sequence()
{
  Serial.print("Vous avez gagné");
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(whiteLed, LOW);
  delay(250);

  digitalWrite(greenLed, HIGH);
  digitalWrite(redLed, HIGH);
  digitalWrite(yellowLed, HIGH);
  digitalWrite(whiteLed, HIGH);
  delay(500);
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(whiteLed, LOW);
  delay(500);

  if (level >= 10) {
    level++;
    speed -= 50;
  }
  //  if (level < MAX_LEVEL);
  //  level++;
  //
  //  velocity -= 50; //increase difficulty
}

//void checkResponse(int button, int ledPin) {
//  if (digitalRead(button) == 1) {
//      mySequence[i] = ledPin;
//      digitalWrite(ledPin, HIGH);
//      delay(400);
//      digitalWrite(ledPin, LOW);
//    }
//  }

//boolean compareSequence () {
//  for (int n = 0; n < 5; n++) {
//    if (sequence[n != mySequence[n]]) {
//      return false;
//    }
//    else {
//      return true;
//    }
//  }
//}

void wrong_sequence() {
  for (int i = 0; i < 3; i++) {
    Serial.print("passage par wrong sequence");
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, HIGH);
    digitalWrite(whiteLed, HIGH);
    delay(250);
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(yellowLed, LOW);
    digitalWrite(whiteLed, LOW);
    delay(250);
  }
  gameTryied++;
  if (gameTryied >= 4) {
    Serial.print("Loooooooooooooose");
    return;
  }
  getSequence();
}

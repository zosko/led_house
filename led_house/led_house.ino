// LEDS
const int LED1 = 1;
const int LED2 = 2;
const int LED3 = 3;
const int LED4 = 4;
const int LED5 = 5;
const int LED6 = 6;
const int LED7 = 7;

// RELAYS
const int RELAY1 = 10;
const int RELAY2 = 11;

// BUTTONS
const int BTN_A = 12;
const int BTN_B = 13;

int timer_hours = 1; // 1h
unsigned long timer;

// 0 - manual off
// 1 - manual on
// 2 - manual auto
int manual_states = 0;

int button_b_states = 0;

void setup() {

  // Initialize leds
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
  pinMode(LED7, OUTPUT);

  // Initialize Realys
  pinMode(RELAY1, OUTPUT);
  pinMode(RELAY2, OUTPUT);

  // Initialize buttons
  pinMode(BTN_A, INPUT);
  pinMode(BTN_B, INPUT);

  timer = millis();
}

void loop() {

  if (button_A_pressed()) {
    manual_states++;
    delay(1000);
    if (manual_states > 3) {
      manual_states = 0; // RECYCLE
    }

    switch (manual_states) {
      case 0 : digitalWrite(LED1, HIGH); break; // YELLOW
      case 1 : digitalWrite(LED1, HIGH); break; // GREEN
    }
  }

  if (millis() >= getHours() && manual_states == 0) {
    timer = millis();
  }

  if (manual_states == 2 && button_B_pressed()) {
    button_b_states++;
    delay(1000);
    if (button_b_states > 4) {
      button_b_states = 0; // RECYCLE
    }

    all_off();
    switch (button_b_states) {
      case 0 : {
          digitalWrite(LED2, HIGH);
          digitalWrite(LED3, HIGH);
          break;
        }
      case 1 : {
          digitalWrite(LED4, HIGH);
          digitalWrite(LED5, HIGH);
          break;
        }
      case 2 : {
          digitalWrite(LED1, HIGH);
          digitalWrite(LED2, HIGH);
          digitalWrite(LED3, HIGH);
          digitalWrite(LED4, HIGH);
          digitalWrite(LED5, HIGH);
          digitalWrite(LED6, HIGH);
          digitalWrite(LED7, HIGH);
          break;
        }
      case 3 : {
          digitalWrite(LED1, HIGH);
          digitalWrite(LED2, HIGH);
          digitalWrite(LED3, HIGH);
          digitalWrite(LED4, HIGH);
          digitalWrite(LED5, HIGH);
          digitalWrite(LED6, HIGH);
          digitalWrite(LED7, HIGH);

          digitalWrite(RELAY1, HIGH);
          break;
        }
      case 4 : {
          digitalWrite(LED1, HIGH);
          digitalWrite(LED2, HIGH);
          digitalWrite(LED3, HIGH);
          digitalWrite(LED4, HIGH);
          digitalWrite(LED5, HIGH);
          digitalWrite(LED6, HIGH);
          digitalWrite(LED7, HIGH);

          digitalWrite(RELAY2, HIGH);
          break;
        }
    }
  }

}
long getHours() {
  return 3600L * 1000 * timer_hours;
}
bool button_A_pressed() {
  return digitalRead(BTN_A);
}
bool button_B_pressed() {
  return digitalRead(BTN_B);
}
void all_off() {
  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  digitalWrite(LED3, LOW);
  digitalWrite(LED4, LOW);
  digitalWrite(LED5, LOW);
  digitalWrite(LED6, LOW);
  digitalWrite(LED7, LOW);

  digitalWrite(RELAY1, LOW);
  digitalWrite(RELAY2, LOW);
}

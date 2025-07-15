// ========================================
// PIN DEFINITIONS
// ========================================
int in1 = 9;                    // Motor A direction pin 1
int in2 = 8;                    // Motor A direction pin 2
int in3 = 7;                    // Motor B direction pin 1
int in4 = 6;                    // Motor B direction pin 2
int enA = 10;                   // Motor A speed control (PWM)
int enB = 5;                    // Motor B speed control (PWM)

// ========================================
// SPEED CONFIGURATIONS
// ========================================
int M1_bluetooth = 150;         // Motor 1 speed for bluetooth control
int M2_bluetooth = 150;         // Motor 2 speed for bluetooth control
int M1_Speed = 93;              // Speed of motor right (line following)
int M2_Speed = 93;              // Speed of motor left (line following)
int LeftRotationSpeed = 124;    // Left rotation speed
int RightRotationSpeed = 124;   // Right rotation speed

// ========================================
// GLOBAL VARIABLES
// ========================================
char bluetooth;                 // Variable to store bluetooth command

// ========================================
// SETUP FUNCTION
// ========================================
void setup() {
  // Configure motor control pins as outputs
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  
  // Configure motor speed control pins as outputs
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  
  // Configure sensor pins as inputs
  pinMode(A0, INPUT);           // Initialize left sensor as input
  pinMode(A1, INPUT);           // Initialize right sensor as input
  
  // Initialize serial communication for bluetooth
  Serial.begin(9600);
}

// ========================================
// MAIN LOOP
// ========================================
void loop() {
  // Read sensor values
  int LEFT_SENSOR = digitalRead(A0);
  int RIGHT_SENSOR = digitalRead(A1);
  
  // Check for bluetooth commands
  if (Serial.available()) {
    bluetooth = Serial.read();
    Serial.println(bluetooth);
  }
  
  // Process bluetooth commands
  if (bluetooth == 'f') {
    forwardB();                 // Move forward (bluetooth control)
  } 
  else if (bluetooth == 'b') {
    backwardB();                // Move backward (bluetooth control)
  } 
  else if (bluetooth == 'r') {
    rightB();                   // Turn right (bluetooth control)
  } 
  else if (bluetooth == 'l') {
    leftB();                    // Turn left (bluetooth control)
  } 
  else if (bluetooth == 'm') {
    // Line following mode - sensor-based navigation
    if (RIGHT_SENSOR == 1 && LEFT_SENSOR == 1) {
      forward();                // Both sensors detect line - move forward
    } 
    else if (RIGHT_SENSOR == 1 && LEFT_SENSOR == 0) {
      left();                   // Right sensor detects line - turn left
    } 
    else if (RIGHT_SENSOR == 0 && LEFT_SENSOR == 1) {
      right();                  // Left sensor detects line - turn right
    } 
    else if (RIGHT_SENSOR == 0 && LEFT_SENSOR == 0) {
      // No line detected - execute search pattern
      digitalWrite(in1, HIGH);
      digitalWrite(in2, LOW);
      digitalWrite(in3, LOW);
      digitalWrite(in4, HIGH);
      analogWrite(enA, 250);
      analogWrite(enB, 250);
    }
    else {
      Stop();                   // Default case - stop robot
    }
  } 
  else {
    Stop();                     // No valid command - stop robot
  }
}

// ========================================
// MOVEMENT FUNCTIONS - LINE FOLLOWING
// ========================================

// Move forward during line following
void forward() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, M1_Speed);
  analogWrite(enB, M2_Speed);
}

// Turn right during line following
void right() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, 140);
  analogWrite(enB, 220);
}

// Turn left during line following
void left() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, 220);
  analogWrite(enB, 160);
}

// ========================================
// MOVEMENT FUNCTIONS - BLUETOOTH CONTROL
// ========================================

// Move forward via bluetooth command
void forwardB() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, M1_bluetooth);
  analogWrite(enB, M2_bluetooth);
}

// Move backward via bluetooth command
void backwardB() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  analogWrite(enA, M1_bluetooth);
  analogWrite(enB, M2_bluetooth);
}

// Turn right via bluetooth command
void rightB() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  analogWrite(enA, M1_bluetooth);
  analogWrite(enB, M2_bluetooth);
}

// Turn left via bluetooth command
void leftB() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
  analogWrite(enA, M1_bluetooth);
  analogWrite(enB, M2_bluetooth);
}


// Stop all motors
void Stop() {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, HIGH);
}

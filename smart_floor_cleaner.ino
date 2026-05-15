// =====================================================
// SMART FLOOR CLEANER ROBOT
// Arduino UNO Based Project
// Dust Collector + Obstacle Avoiding Robot
// =====================================================

// ---------------- MOTOR DRIVER PINS ----------------

// Left Motor
int ENA = 5;
int IN1 = 6;
int IN2 = 7;

// Right Motor
int ENB = 9;
int IN3 = 10;
int IN4 = 11;

// ---------------- ULTRASONIC SENSOR ----------------

int trigPin = 2;
int echoPin = 3;

// ---------------- FAN MOTOR ----------------

int fanPin = 4;

// ---------------- VARIABLES ----------------

long duration;
int distance;

// =====================================================

void setup() {

  // Motor Pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);

  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Ultrasonic Sensor
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Fan Pin
  pinMode(fanPin, OUTPUT);

  // Serial Monitor
  Serial.begin(9600);

  // Set Motor Speed
  analogWrite(ENA, 180);
  analogWrite(ENB, 180);

  // Start Fan
  digitalWrite(fanPin, HIGH);
}

// =====================================================

void loop() {

  // Get Distance
  distance = getDistance();

  Serial.print("Distance: ");
  Serial.println(distance);

  // Obstacle Detected
  if (distance < 20) {

    stopRobot();
    delay(500);

    moveBackward();
    delay(700);

    turnRight();
    delay(600);
  }

  // No Obstacle
  else {

    moveForward();
  }
}

// =====================================================
// FUNCTION : GET DISTANCE
// =====================================================

int getDistance() {

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;

  return distance;
}

// =====================================================
// FUNCTION : MOVE FORWARD
// =====================================================

void moveForward() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

// =====================================================
// FUNCTION : MOVE BACKWARD
// =====================================================

void moveBackward() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// =====================================================
// FUNCTION : TURN RIGHT
// =====================================================

void turnRight() {

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

// =====================================================
// FUNCTION : STOP ROBOT
// =====================================================

void stopRobot() {

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

// Robotic Vacuum Cleaner – Autonomous Navigation
// By Mittul Agarwal

#include <Servo.h>

// Motor driver pins (L298N)
int ENA = 5;      // Left motor speed
int IN1 = 6;      // Left motor direction 1
int IN2 = 7;      // Left motor direction 2
int ENB = 9;      // Right motor speed
int IN3 = 10;     // Right motor direction 1
int IN4 = 11;     // Right motor direction 2

// Ultrasonic sensor pins
int trigPin = 2;
int echoPin = 3;

// Suction motor (through relay / MOSFET)
int SUCTION_PIN = 8;

// Servo for sensor / nozzle
Servo headServo;
int SERVO_PIN = 4;

long duration;
int distance;

void setup() {
  Serial.begin(9600);

  // Motor pins
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Ultrasonic
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // Suction motor
  pinMode(SUCTION_PIN, OUTPUT);
  digitalWrite(SUCTION_PIN, HIGH);   // suction ON all the time

  // Servo
  headServo.attach(SERVO_PIN);
  headServo.write(90);               // center position
}

void loop() {
  distance = getDistance();

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance <= 20) {
    // Obstacle very close → stop and decide turn
    stopMotors();
    delay(300);

    // Small servo scan (optional)
    headServo.write(60);
    delay(200);
    int leftDist = getDistance();

    headServo.write(120);
    delay(200);
    int rightDist = getDistance();

    headServo.write(90); // back to center

    // Turn towards side with more space
    if (rightDist > leftDist) {
      turnRight();
    } else {
      turnLeft();
    }

    delay(600);
    stopMotors();
  } else {
    moveForward();
  }

  delay(80);
}

// ---- distance function ----
int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;  // cm
}

// ---- movement functions ----
void moveForward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void moveBackward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void turnRight() {
  // left motor forward, right motor backward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void turnLeft() {
  // left motor backward, right motor forward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 200);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

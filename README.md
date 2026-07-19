# Robotic Vacuum Cleaner

Autonomous robotic vacuum cleaner using Arduino, ultrasonic sensor, and motor driver. This is the enhanced version with servo-based scanning for smarter obstacle avoidance.

## Hardware Components

- Arduino Uno/Nano
- L298N Motor Driver
- 2 × DC Gear Motors + Wheels
- HC-SR04 Ultrasonic Sensor
- High-speed DC Suction Motor
- Servo Motor (sensor scanning)
- Chassis, caster wheel, battery pack

## How It Works

1. Robot moves forward while the ultrasonic sensor measures distance.
2. When an obstacle is detected within 20 cm, the robot stops.
3. A servo motor scans left and right to find the clearest path.
4. The robot turns toward the open direction and resumes forward motion.
5. The suction motor runs continuously for dust collection.

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| Motor ENA | 5 |
| Motor IN1 | 6 |
| Motor IN2 | 7 |
| Motor ENB | 9 |
| Motor IN3 | 10 |
| Motor IN4 | 11 |
| Ultrasonic TRIG | 2 |
| Ultrasonic ECHO | 3 |
| Servo Signal | 12 |
| Suction Motor | 8 |

## Skills Demonstrated

- Embedded C++ (Arduino)
- Sensor interfacing (ultrasonic, servo)
- Motor driver control (L298N)
- Obstacle avoidance algorithms

## Author

**Mittul Agarwal**

# **Crane-Sentia – Intelligent Crane Safety System**

Crane-Sentia is a hardware-based smart safety system designed to enhance on-site crane operations using sensor-driven monitoring, distance detection, and real-time visual feedback.
The word **Sentia** derives from Latin, meaning *“sensing / awareness”*, reflecting the system’s goal of enabling cranes to “sense” their surroundings.
The project integrates **multiple sensing modules** to improve worker safety, reduce collision risks, and provide continuous situational awareness around crane movement areas.


## **System Overview**

Modern construction sites involve heavy machinery, dynamic worker movement, and limited visibility. Crane-Sentia enhances safety by combining:

### **1. Distance Monitoring Module**

Using ultrasonic sensors, the system measures the distance between the crane and nearby workers/objects, triggering alerts based on three safety stages:
**Safe – Attention – Dangerous**

### **2. Visual Monitoring Module**

An OV7670 camera module streams real-time frames to a connected laptop, providing visual confirmation of crane surroundings.

### **3. Weight Monitoring Architecture**

The system design includes a load-cell module within the overall safety architecture for lifting weight estimation.
* The module is fully included in the hardware and circuit design.
* Integration can be finalized after calibration and tuning.
* This ensures the system remains extensible without limiting the current functional prototype.
Together, these modules create a multi-layered safety support system for crane operators and site engineers.

## **Hardware Components**

* Arduino
* Ultrasonic distance sensors
* OV7670 camera module
* Load Cell sensor
* Buzzer (audible alarms)
* Jumper wires & breadboard
* External power source


## **Project Structure**

* **README.md**
* **Codes**
* **Diagrams**
* **Images**

## **Future Enhancements**

* Full activation and calibration of the weight-monitoring module
* Integrating all modules into a unified safety dashboard
* Providing live external view directly to the crane operator
* Adding wireless communication to send alerts to site supervisors
* Implementing AI-based object/worker/PPE recognition
* Enhancing the system using an engineering weight database, enabling AI to analyze whether a crane can safely lift a specific utility load

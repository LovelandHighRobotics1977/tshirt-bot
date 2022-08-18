// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <iostream>
#include <frc/Timer.h>

void Robot::RobotInit() {
}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  timer.Reset();
  timer.Start();
}
void Robot::AutonomousPeriodic() {
  //90 .73 clockwise
  //180 1.46 
 /* if(timer.Get() < .73){
    Drive(1,1); 
  }else{
    Drive(0,0);
  }Z*/
}

void Robot::TeleopInit() {
    m_led.SetLength(300);
    m_led.SetData(m_ledBuffer);
    m_led.Start();
}
void Robot::TeleopPeriodic() {
  if(stage == 0){
    for (int i = 0; i < 300; i++) {
      m_ledBuffer[i].SetRGB(r, g, b);
    }
    m_led.SetData(m_ledBuffer);
    g++;
    if(g == 255){stage = 1;}
  }
  if(stage == 1){
    for (int i = 0; i < 300; i++) {
      m_ledBuffer[i].SetRGB(r, g, b);
    }
    m_led.SetData(m_ledBuffer);
    r--;
    if(r == 0){stage = 2;}
  }
  if(stage == 2){
    for (int i = 0; i < 300; i++) {
      m_ledBuffer[i].SetRGB(r, g, b);
    }
    m_led.SetData(m_ledBuffer);
    b++;
    if(b == 255){stage = 3;}
  }
  if(stage == 3){
    for (int i = 0; i < 300; i++) {
      m_ledBuffer[i].SetRGB(r, g, b);
    }
    m_led.SetData(m_ledBuffer);
    g--;
    if(g == 0){stage = 4;}
  }
  if(stage == 4){
    for (int i = 0; i < 300; i++) {
      m_ledBuffer[i].SetRGB(r, g, b);
    }
    m_led.SetData(m_ledBuffer);
    r++;
    if(r == 255){stage = 5;}
  }
  if(stage == 5){
    for (int i = 0; i < 300; i++) {
      m_ledBuffer[i].SetRGB(r, g, b);
    }
    m_led.SetData(m_ledBuffer);
    b--;
    if(b == 0){stage = 0;}
  }
  Aim(m_driverController.GetRightBumper(),m_driverController.GetLeftBumper());
  Drive(-m_driverController.GetLeftY(),m_driverController.GetRightY());
  if(m_driverController.GetAButton()==1){
    t1.Set(true);
  }else{
    t1.Set(false);
  }

  if(m_driverController.GetBButton()==1){
    t2.Set(true);
  }else{
    t2.Set(false);
  }

  if(m_driverController.GetXButton()==1){
    t3.Set(true);
  }else{
    t3.Set(false);
  }

  if(m_driverController.GetYButton()==1){
    t4.Set(true);
  }else{
    t4.Set(false);
  }
  }

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::Drive(float left, float right){
  m_l1.Set(left);
  m_l2.Set(left);
  m_l3.Set(left);
  m_r1.Set(right);
  m_r2.Set(right);
  m_r3.Set(right);
}

void Robot::Aim(float up, float down){
  
  if(up==1){
    gun.Set(1);
  }else if(down==1){
    gun.Set(-1);
  }else{
    gun.Set(0);
    gun.SetNeutralMode(NeutralMode::Brake);
  }
}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif

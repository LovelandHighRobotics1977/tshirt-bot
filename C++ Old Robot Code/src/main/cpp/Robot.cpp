// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <iostream>
#include <frc/Timer.h>

void Robot::RobotInit() {}
void Robot::RobotPeriodic() {}

void Robot::AutonomousInit() {
  timer.Reset();
  timer.Start();
}
void Robot::AutonomousPeriodic() {
  //90 .73 clockwise
  //180 1.46 
  if(timer.Get() < .73){
    Drive(1,1); 
  }else{
    Drive(0,0);
  }
}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  Aim(m_driverController.GetBumper(frc::GenericHID::JoystickHand::kRightHand),m_driverController.GetBumper(frc::GenericHID::JoystickHand::kLeftHand));
  //Drive(-m_driverController.GetY(frc::GenericHID::JoystickHand::kLeftHand),m_driverController.GetY(frc::GenericHID::JoystickHand::kRightHand));
  }

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::Drive(float left, float right){
 // m_l1.Set(left);
  m_l2.Set(left);
  m_l3.Set(left);
  m_r1.Set(right);
  m_r2.Set(right);
  m_r3.Set(right);
}

void Robot::Aim(float up, float down){
  
  if(up==1){
    gun.Set(.2);
  }else if(down==1){
    gun.Set(-.2);
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

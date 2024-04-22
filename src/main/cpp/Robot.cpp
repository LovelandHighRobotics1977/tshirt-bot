// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

void Robot::RobotInit() 
{
  //sets the robot to brake when it starts
  //this makes it easier to drive as it stops quicker
  m_driveMotorLBack.SetNeutralMode(Brake);
  m_driveMotorLFront.SetNeutralMode(Brake);
  m_driveMotorRBack.SetNeutralMode(Brake);
  m_driveMotorRFront.SetNeutralMode(Brake);
  m_driveMotorLTop.SetNeutralMode(Brake);
  m_driveMotorRTop.SetNeutralMode(Brake);
}
void Robot::RobotPeriodic() {}

//no auto right now
void Robot::AutonomousInit() 
{
  std::cout << "very cool auto :D";
}
void Robot::AutonomousPeriodic() {}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() 
{
  XboxArm();
  XboxDirection();
}


//uses the two Y positions from the Xbox sticks to drive the robot. 
//the right bumper Button changes the speed
void Robot::XboxDirection()
{
  //used to controll the motors based off the joysticks
  drive(-m_XBox.GetLeftY() * DriveSpeed, m_XBox.GetRightY() * (DriveSpeed-(0.01 * DriveSpeed)));

  //lowers the speed while the right bumper is pressed
  if(m_XBox.GetRightBumper())
  {
    DriveSpeed = 0.3;
  }
  else
  {
    DriveSpeed = OGDriveSpeed;
  }
}

//uses the xbox controller to controll the arm
//Letter buttons controll the solanoids for the shooter
//Left and right triggers control the raising and lowering f the arm
void Robot::XboxArm()
{
  m_SolenoidLeft.Set(m_XBox.GetXButton());
  m_SolenoidMidLeft.Set(m_XBox.GetYButton());
  m_SolenoidMidRight.Set(m_XBox.GetAButton());
  m_SolenoidRight.Set(m_XBox.GetBButton());
  if(m_XBox.GetRightBumper())
  {
     m_Angle.Set(ControlMode::PercentOutput, 1);
  }
  else if(m_XBox.GetLeftBumper())
  {
     m_Angle.Set(ControlMode::PercentOutput, -1);
  }
  else
  {
     m_Angle.Set(ControlMode::PercentOutput, 0);
  }
 
}



//sets the motors on either ide to the variables that are sent to it
void Robot::drive(double left, double right)
{
  //checks the current on the PDH channel that each motor is on before letting them drive
  //the maximum amperage is the currentLimit value declared in the header file
  if(m_pdp.GetCurrent(12) < currentLimit && m_pdp.GetCurrent(15) < currentLimit
   && m_pdp.GetCurrent(0) < currentLimit && m_pdp.GetCurrent(3) < currentLimit)
   {
    m_driveMotorLBack.Set(ControlMode::PercentOutput, left);
    m_driveMotorLFront.Set(ControlMode::PercentOutput, left);
    m_driveMotorRBack.Set(ControlMode::PercentOutput, right);
    m_driveMotorRFront.Set(ControlMode::PercentOutput, right);
    m_driveMotorLTop.Set(ControlMode::PercentOutput, left);
    m_driveMotorRTop.Set(ControlMode::PercentOutput, right);
   }
   //if the current is too high, it wont let the motors drive
   else
   {
    m_driveMotorLBack.Set(ControlMode::PercentOutput, 0);
    m_driveMotorLFront.Set(ControlMode::PercentOutput, 0);
    m_driveMotorRBack.Set(ControlMode::PercentOutput, 0);
    m_driveMotorRFront.Set(ControlMode::PercentOutput, 0);
    m_driveMotorLTop.Set(ControlMode::PercentOutput, 0);
    m_driveMotorRTop.Set(ControlMode::PercentOutput, 0);
   }
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}
void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
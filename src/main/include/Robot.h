// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <iostream>
#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include <ctre/phoenix.h>
#include <frc/XboxController.h>
#include <frc/PowerDistribution.h>
#include <frc/PneumaticsControlModule.h>
#include <frc/Solenoid.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;

  void SimulationInit() override;
  void SimulationPeriodic() override;

  //this will never change
  //it is used to add abstraction to the changing drive speed function
  double OGDriveSpeed = 1;

  //sets the robots max drive speed for the Xbox controller with dual stick (Xbox)
  double DriveSpeed = OGDriveSpeed;

  //the maximum amperadge the motors can draw before shutting off
  int currentLimit = 8;
  
  //Controlls the drivetrain with the Xbox controller
  void XboxDirection();

  //Controlls the mech with the Xbox controller
  void XboxArm();

  //Makes it easier to add new controllers
  //also adds a layer of abstraction to the code
  void drive(double left, double right);


  private:
  //declares the motors based on the CAN IDs to allow the roboRio to control them
  //this is used to call these devices to set their speed and break mode


  //drive motors
  TalonFX m_driveMotorRFront{3};
  TalonFX m_driveMotorRBack{4};
  TalonFX m_driveMotorRTop{5};
  TalonFX m_driveMotorLFront{0};
  TalonFX m_driveMotorLBack{1};
  TalonFX m_driveMotorLTop{2};
  //mech motors
  TalonFX m_Angle{6};
  //controllers
  frc::XboxController m_XBox{0};
  //pdh
  frc::PowerDistribution m_pdp{1, frc::PowerDistribution::ModuleType::kCTRE};


  //pneumatics
  //Used for firing the T-shirts by controlling the solanoids on the barel
  frc::Solenoid m_SolenoidLeft{frc::PneumaticsModuleType::CTREPCM, 0};
  frc::Solenoid m_SolenoidMidLeft{frc::PneumaticsModuleType::CTREPCM, 1};
  frc::Solenoid m_SolenoidMidRight{frc::PneumaticsModuleType::CTREPCM, 2};
  frc::Solenoid m_SolenoidRight{frc::PneumaticsModuleType::CTREPCM, 3};
};
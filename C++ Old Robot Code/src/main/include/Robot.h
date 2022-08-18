// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <ctre/Phoenix.h>
#include <frc/TimedRobot.h>

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;

  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;
  void Drive(float left, float right);
  void Aim(float up, float down);


  void DisabledInit() override;
  void DisabledPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;
private:
  frc::XboxController m_driverController{0};
  WPI_TalonSRX m_r1{3};
  WPI_TalonSRX m_r2{4};
  WPI_TalonSRX m_r3{5};
 // WPI_TalonSRX m_l1{0};
  WPI_TalonSRX m_l2{1};
  WPI_TalonSRX m_l3{2};
  WPI_TalonFX gun{0};
  frc::Timer timer;
};

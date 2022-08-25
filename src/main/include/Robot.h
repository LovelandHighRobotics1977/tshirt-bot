// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <frc/TimedRobot.h>
#include <frc/Joystick.h>
#include <frc/XboxController.h>
#include <ctre/Phoenix.h>
#include <frc/TimedRobot.h>
#include <frc/AddressableLED.h>
#include <frc/Solenoid.h>

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

  void ledAnimation(int tube);
  void cooldown();
private:
  frc::AddressableLED m_led{9};
  std::array<frc::AddressableLED::LEDData, 299>m_ledBuffer;
  frc::XboxController m_driverController{0};
  WPI_TalonSRX m_r1{3};
  WPI_TalonSRX m_r2{4};
  WPI_TalonSRX m_r3{5};
  WPI_TalonSRX m_l1{0};
  WPI_TalonSRX m_l2{1};
  WPI_TalonSRX m_l3{2};
  WPI_VictorSPX gun{6};
  frc::Timer timer;
  int r = 0;
  int g = 0;
  int b = 0;
  int stage = 0;
  int trigger = 0;
  int ftube;
  bool active = false;
  bool cdRan = true;
  int stage2 = 0;
  int anRan = false;
  frc::Solenoid t1{frc::PneumaticsModuleType::CTREPCM, 0};
  frc::Solenoid t2{frc::PneumaticsModuleType::CTREPCM, 1};
  frc::Solenoid t3{frc::PneumaticsModuleType::CTREPCM, 2};
  frc::Solenoid t4{frc::PneumaticsModuleType::CTREPCM, 3};
};

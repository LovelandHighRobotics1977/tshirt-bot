// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"
#include <iostream>
#include <frc/Timer.h>
#include <chrono>
#include <thread>
#include <math.h>


void Robot::RobotInit() {
   m_led.SetLength(299);
    m_led.SetData(m_ledBuffer);
    m_led.Start();
    for (int i = 0; i < 299; i++) {
      if(i < 160){
        m_ledBuffer[i].SetRGB(255, 0, 0);
      }else if(i>170){m_ledBuffer[i].SetRGB(0, 0, 0);}
    }
    m_led.SetData(m_ledBuffer);
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

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  // underglow led 0-160
  Aim(m_driverController.GetRightBumper(),m_driverController.GetLeftBumper());
  Drive(-m_driverController.GetLeftY(),m_driverController.GetRightY());
  if(active == false){
    m_led.SetLength(299);
    m_led.SetData(m_ledBuffer);
    m_led.Start();
    for (int i = 0; i < 299; i++) {
      if(i < 160){
        m_ledBuffer[i].SetRGB(255, 0, 0);
      }else{
        m_ledBuffer[i].SetRGB(0, 0, 0);
      }
    }
    m_led.SetData(m_ledBuffer);
    if(m_driverController.GetAButton()==1){
      ftube = 1;
      active = true;
    }

    if(m_driverController.GetBButton()==1){
      ftube = 2;
      active = true;
    }

    if(m_driverController.GetXButton()==1){
      ftube = 3;
      active = true;
    }

    if(m_driverController.GetYButton()==1){
      ftube = 4;
      active = true;
    }
  }

  if(active == true){
    if(anRan == false){
    ledAnimation(ftube);
    }else if(anRan == true){
      cooldown();
    }
  }
}

void Robot::DisabledInit() {}
void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

void Robot::ledAnimation(int tube){
  if(stage == 0){
    for(int i = 0; i < 299; i++){
      if(i < 160){
        m_ledBuffer[i].SetRGB(255, 0, 0);
      }else{m_ledBuffer[i].SetRGB(r, g, b);}
    }
    r+=5;
    m_led.SetData(m_ledBuffer);
    if(r == 255){stage = 1;}
  }

  if(stage == 1){
    for(int i = 0; i < 299; i++){
      if(i < 160){
        m_ledBuffer[i].SetRGB(255, 0, 0);
      }else{m_ledBuffer[i].SetRGB(r, g, b);}
    }
    g+=5;
    m_led.SetData(m_ledBuffer);
    if(g == 255){stage = 2;}
  }

  if(stage == 2){
    for(int i = 0; i < 299; i++){
      if(i < 160){
        m_ledBuffer[i].SetRGB(255, 0, 0);
      }else{m_ledBuffer[i].SetRGB(r, g, b);}
    }
    r-=5;
    m_led.SetData(m_ledBuffer);
    if(r == 0){stage = 3;}
  }

  if(stage == 3){
    switch(tube){
      case 1:
        t1.Set(true);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        t1.Set(false);
        break;
      case 2:
        t2.Set(true);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        t2.Set(false);
        break;
      case 3:
        t3.Set(true);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        t3.Set(false);
        break;
      case 4:
        t4.Set(true);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        t4.Set(false);
        break;
    }
    stage = 4;
  }

  if(stage == 4){
    r = 0;
    g = 255;
    b = 0;
    stage = 0;
    anRan = true;
    //active = false;
  }
  
}

void Robot::cooldown(){
  if(stage2 == 0){
    for(int j = 0; j < 299; j++){
      if(j < 160){
        m_ledBuffer[j].SetRGB(255, 0, 0);
      }else{m_ledBuffer[j].SetRGB(r, g, b);}
    }
    b+=40;
    if(b>255){b = 255;}
    m_led.SetData(m_ledBuffer);
    if(b == 255){stage2 = 1;}
  }

  if(stage2 == 1){
    for(int j = 0; j < 299; j++){
      if(j < 160){
        m_ledBuffer[j].SetRGB(255, 0, 0);
      }else{m_ledBuffer[j].SetRGB(r, g, b);}
    }
    g-=40;
    if(g<0){g = 0;}
    m_led.SetData(m_ledBuffer);
    if(g == 0){stage2 = 2;}
  }

  if(stage2 == 2){
    for(int j = 0; j < 299; j++){
      if(j < 160){
        m_ledBuffer[j].SetRGB(255, 0, 0);
      }else{m_ledBuffer[j].SetRGB(r, g, b);}
    }
    r+=40;
    if(r>255){r = 255;}
    m_led.SetData(m_ledBuffer);
    if(r == 255){stage2 = 3;}
  }

  
  if(stage2 == 3){
    for(int j = 0; j < 299; j++){
      if(j < 160){
        m_ledBuffer[j].SetRGB(255, 0, 0);
      }else{m_ledBuffer[j].SetRGB(r, g, b);}
    }
    b-=40;
    if(b<0){b = 0;}
    m_led.SetData(m_ledBuffer);
    if(b == 0){stage2 = 4;}
  }

  if(stage2 == 4){
    for(int j = 0; j < 299; j++){
      if(j < 160){
        m_ledBuffer[j].SetRGB(255, 0, 0);
      }else{m_ledBuffer[j].SetRGB(r, g, b);}
    }
    r-=40;
    if(r<=0){
      r = 0;
      for(int j = 0; j < 299; j++){
      if(j < 160){
        m_ledBuffer[j].SetRGB(255, 0, 0);
      }else{m_ledBuffer[j].SetRGB(r, g, b);}
      }
    }
    m_led.SetData(m_ledBuffer);
    if(r == 0){
      r = 0; 
      g = 0; 
      b = 0; 
      stage2 = 0;
      active = false;
      anRan = false;
    }
  }
}

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

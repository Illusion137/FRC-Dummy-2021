// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#include <RobotContainer.h>
#include <iostream>
#include <frc/Joystick.h>
#include <frc/PWMSparkMax.h>
#include <frc/TimedRobot.h>
#include <frc/Timer.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/livewindow/LiveWindow.h>
#include <frc/XboxController.h>
#include <frc/GenericHID.h>
#include <cameraserver/CameraServer.h>

#include "Definitions.h"
#include "commands/DriveRobot.h"

class Robot : public frc::TimedRobot {
 public:
  Robot() {
    frc::CameraServer::GetInstance()->StartAutomaticCapture();
    m_robotDrive.SetExpiration(0.1);
    m_timer.Start();
  }

  void AutonomousInit() override {
    m_timer.Reset();
    m_timer.Start();
  }

  void AutonomousPeriodic() override {
    // Drive for 2 seconds
    if (m_timer.Get() < 2.0) {
      // Drive forwards half speed
      m_robotDrive.ArcadeDrive(0.5, -0.2);
    } else {
      // Stop robot
      m_robotDrive.ArcadeDrive(0.0, 0.0);
    }
  }

  void TeleopInit() override {}

  void TeleopPeriodic() override {
    nerds::changeMaxDriveSpeed();
    nerds::DriveRobot();
  }


  void TestInit() override {}

  void TestPeriodic() override {}


 private:
  // Robot drive system
  frc::LiveWindow& m_lw = *frc::LiveWindow::GetInstance();
  frc::Timer m_timer;
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}

#endif

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

#define RightTrigger frc::GenericHID::JoystickHand::kRightHand
#define LeftTrigger frc::GenericHID::JoystickHand::kLeftHand
class Robot : public frc::TimedRobot {
 public:
  Robot() {
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
    // Drive with arcade style (use right stick)
    m_robotDrive.ArcadeDrive(getDriveSpeed(), m_stick.GetX());
  }


  void TestInit() override {}

  void TestPeriodic() override {}

  double getDriveSpeed() {
    if (m_controller.GetTriggerAxis(RightTrigger) > 0 
      && m_controller.GetTriggerAxis(RightTrigger) < 0.5) {
      return m_controller.GetTriggerAxis(RightTrigger);
    } else if (m_controller.GetTriggerAxis(LeftTrigger) > 0 
      && m_controller.GetTriggerAxis(LeftTrigger) < 0.5) {
      return -m_controller.GetTriggerAxis(LeftTrigger);
    }
  }
 private:
  // Robot drive system
  frc::PWMSparkMax m_left{0};
  frc::PWMSparkMax m_right{1};
  frc::DifferentialDrive m_robotDrive{m_left, m_right};
  frc::XboxController m_controller{0};
  frc::Joystick m_stick{0};
  frc::LiveWindow& m_lw = *frc::LiveWindow::GetInstance();
  frc::Timer m_timer;
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}

#endif

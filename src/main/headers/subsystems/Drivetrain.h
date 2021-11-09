/*----------------------------------------------------------------------------*/
/* Copyright (c) 2019 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc2/command/SubsystemBase.h>

#include <ctre/phoenix/motorcontrol/can/WPI_VictorSPX.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/SpeedControllerGroup.h>
#include <AHRS.h>
#include <frc/Encoder.h>

class Drivetrain : public frc2::SubsystemBase {
 public:
  Drivetrain();

  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic();

  /**
   * @brief Move the robot using an arcade drive control scheme.
   * 
   * @param speed The forward/backwards speed.
   * 
   * @param turn The rate at which the robot turns.
   * 
   * @param squared If true, inputs are squared.
   */
  void ArcadeDrive(double speed, double turn, bool squared);

  /**
   * @brief Get the heading of the gyro on the drivetrain
   * 
   * @return double The robot's current heading in degrees from 0 to 360
   */
  double GetHeading();

  /**
   * @brief get the distance the robot has travelled on the left side
   * 
   * @return double how far the robot has gone on the left side
   */
  double GetDistanceLeft();

  /**
   * @brief get the distance the robot has travelled on the right side
   * 
   * @return double how far the robot has gone on the right side
   */
  double GetDistanceRight();

  /**
   * @brief takes the average of the distance the robot has travelled on the left and right sides
   * 
   * @return double how far the robot has gone
   */
  double AverageDistance();

 private:
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX front_left_;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX front_right_;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX back_left_;
  ctre::phoenix::motorcontrol::can::WPI_VictorSPX back_right_;

  frc::SpeedControllerGroup left_;
  frc::SpeedControllerGroup right_;

  frc::DifferentialDrive drive_;

  AHRS gyro;

  frc::Encoder encoder_left;
  frc::Encoder encoder_right;
};

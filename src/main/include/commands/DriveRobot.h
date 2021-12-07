#pragma once
#include <frc/XboxController.h>
#include <frc/GenericHID.h>
#include "../Definitions.h"
#include <frc/Joystick.h>
#include <thread>

frc::PWMSparkMax m_left{0};
frc::PWMSparkMax m_right{1};
frc::DifferentialDrive m_robotDrive{m_left, m_right};

namespace nerds{

    double maxDriveSpeed = 0.5;

    double getDriveSpeed() {
        if (RT_Value > 0) {
        if (RT_Value <= maxDriveSpeed) {
            return RT_Value;
        } else {
            return maxDriveSpeed;
        }
        } else if (LT_Value > 0) {
        if (LT_Value <= maxDriveSpeed) {
            return -LT_Value;
        } else {
            return -maxDriveSpeed;
        }
        }
        return 0;
    }
    void DriveRobot(){
        m_robotDrive.ArcadeDrive(getDriveSpeed(), m_controller.GetX(RightHand), true);
    }
    frc::Timer speedTimer;
    void changeMaxDriveSpeed() {
        speedTimer.Start();
        if (speedTimer.Get() >= 0.1) {
            switch(m_controller.GetPOV()){
                case(0):
                    maxDriveSpeed += 0.05;
                    speedTimer.Reset();
                    break;
                case(180):
                    maxDriveSpeed -= 0.05;
                    speedTimer.Reset();
                    break;
            }
        }
    }
}
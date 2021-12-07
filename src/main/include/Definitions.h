#pragma once
#include <frc/Timer.h>
frc::XboxController m_controller{0};

#define RightHand frc::GenericHID::JoystickHand::kRightHand
#define LeftHand frc::GenericHID::JoystickHand::kLeftHand

#define RT_Value m_controller.GetTriggerAxis(frc::GenericHID::JoystickHand::kRightHand)
#define LT_Value m_controller.GetTriggerAxis(frc::GenericHID::JoystickHand::kLeftHand)
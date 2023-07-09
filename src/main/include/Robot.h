// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once

#include <string>

#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

#include <ctre/Phoenix.h>

#include <frc/XboxController.h>

#include <frc/DoubleSolenoid.h>

#include <frc/Compressor.h>

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

 private:
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;

  WPI_TalonSRX *shooterMotor1;
  WPI_TalonSRX *shooterMotor2;

  WPI_VictorSPX *intakeMotor;

  WPI_TalonSRX *DrivebaseLeft1;
  WPI_TalonSRX *DrivebaseLeft2;
  WPI_TalonSRX *DrivebaseLeft3;

  WPI_TalonSRX *DrivebaseRight1;
  WPI_TalonSRX *DrivebaseRight2;
  WPI_TalonSRX *DrivebaseRight3;


  frc::XboxController *driver;
  frc::XboxController *codriver;

  frc::DoubleSolenoid *drivebaseSpeedToggle;
  frc::Compressor *compressor;

  bool isFast = false;

};

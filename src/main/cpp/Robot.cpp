// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "Robot.h"

#include <fmt/core.h>

#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

  shooterMotor1 = new WPI_TalonSRX(4);
  shooterMotor2 = new WPI_TalonSRX(12);

  intakeMotor = new WPI_VictorSPX(11);

  DrivebaseLeft1 = new WPI_TalonSRX(3);
  DrivebaseLeft2 = new WPI_TalonSRX(7);
  DrivebaseLeft3 = new WPI_TalonSRX(16);

  DrivebaseRight1 = new WPI_TalonSRX(1);
  DrivebaseRight2 = new WPI_TalonSRX(5);
  DrivebaseRight3 = new WPI_TalonSRX(6);

  driver = new frc::XboxController(0);
  codriver = new frc::XboxController(1);

  drivebaseSpeedToggle = new frc::DoubleSolenoid(frc::PneumaticsModuleType::CTREPCM, 0, 1);

  compressor = new frc::Compressor(0, frc::PneumaticsModuleType::CTREPCM);
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  compressor->EnableDigital();

}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  fmt::print("Auto selected: {}\n", m_autoSelected);

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
  if (codriver->GetRightY() > 0.05 || codriver->GetRightY() < -0.05) {
    shooterMotor1->Set(-codriver->GetRightY());
    shooterMotor2->Set(codriver->GetRightY());
  } else {
    shooterMotor1->Set(0);
    shooterMotor2->Set(0);
  }

  if (driver->GetLeftY() > 0.2 || driver->GetLeftY() < -0.2) {
    DrivebaseLeft1->Set(driver->GetLeftY());
    DrivebaseLeft2->Set(driver->GetLeftY());
    DrivebaseLeft3->Set(driver->GetLeftY());
  } else {
    DrivebaseLeft1->Set(0);
    DrivebaseLeft2->Set(0);
    DrivebaseLeft3->Set(0);
  }

  if (driver->GetRightY() > 0.2 || driver->GetRightY() < -0.2) {
    DrivebaseRight1->Set(-driver->GetRightY());
    DrivebaseRight2->Set(-driver->GetRightY());
    DrivebaseRight3->Set(-driver->GetRightY());
  } else {
    DrivebaseRight1->Set(0);
    DrivebaseRight2->Set(0);
    DrivebaseRight3->Set(0);
  }

  if (codriver->GetLeftY() > 0.05 || codriver->GetLeftY() < -0.05) {
    intakeMotor->Set(-codriver->GetLeftY());
  } else {
    //intakeMotor->Set(0.2);
    intakeMotor->Set(0);
  }

  if (driver->GetAButtonPressed()) {
    isFast = !isFast;
  }

  

  if (isFast) {
    drivebaseSpeedToggle->Set(frc::DoubleSolenoid::Value::kForward);
  } else {
    drivebaseSpeedToggle->Set(frc::DoubleSolenoid::Value::kReverse);
  }

  


  
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif

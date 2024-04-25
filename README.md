<h1>UPDATED TO 2024!!</h1>

I just updated this code to the 2024 version of wpilib

**Controlls:**
This code is designed to be controlled with a single XBox 360 controller placed in slot 0 of the drive station.
|Button|function|
|------|--------|
|A, B, X, Y|Fires the indavidual solanoids connected to the cannon|
|Sticks|Each stick controlls one side of the robots drivetrain|
|Bumpers|The bumpers controll the raising and lowering of the barels|
|Triggers|When pressed they will slow the speed of the robot|

**Bot Design:**
This code is designed for a robot with a west-coast drivetrain and 4 barrels to shoot T-shirts. These barels are connected to the CTRE PCM in slots 0-3. The angle of these barels is controlled with a liniar actuator. The drive is made with 3 CIM motors with can IDs as followes.

|ID|Motor|
|--|-----|
|0-2|Left Drive|
|3-5|Right Drive|
|6|Angle|
The PCM and PDH are in the Default slots.

Our version of this robot dosnt have a built in compressor, but instead has a 5 gallon tank that is charged beforehand. This robot was made with parts from FRC, but the robot itself is not FRC compliant.

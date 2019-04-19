# ADAS Sensor Measurement and UART and SPI Communication

1. The project receives duty cycle measurements from a distance sensor over UART protocol.
2. Calculates the distance using the duty cycle.
3. Chooses one of 5 commands based on the calculated distance.
4. Sends the command to another control ECU over SPI along with the distance

The command can be:
1. Fire airbag
2. Brake
3. Decrease speed
4. Maintain speed
5. Error
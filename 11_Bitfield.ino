int32_t encoderField = 0;

/*
 * Encoder field, linked to switchModes[row][col], pushed to joysick axis Z

 Most significant
 16 - Unused because of bug in Joystick library
 15 - Quick switch active
 14 - Dual clutches
 13 - Dual clutches
 12 - Bite point setting
 11 - Bite point setting
 10 - DDS switch
 9 - DDS switch
 8
 7
 6
 5
 4
 3 - 
 2 - Quick switch mode
 1 - Handbrake active
 Least significant

 */

int32_t buttonField = 0;

/*
 * Button field, linked to switchModes[row][col], pushed to joysick axis Y

 Most significant
 16 - Unused because of bug in Joystick library
 15 - Neutral mode
 14 - Presets 4rd bit
 13 - Presets 3nd bit
 12 - Presets 2st bit
 11 - Presets 1st bit
 10 - Magic active
 9 - Throttle hold active
 8 - Neutral active
 7 - Shifters mode
 6 - Left top toggle mode
 5 - Right top toggle mode
 4 - Magic toggle mode
 3 - Left rotary mode
 2 - Right rotary mode
 1 - Radio button mode
 Least significant

 */
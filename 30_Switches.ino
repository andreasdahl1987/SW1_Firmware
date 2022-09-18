//------------------------------
//-----------RUTIME-------------
//------------------------------

void loop()
{

    //-------------------------
    //-----ESSENTIALS----------
    //-------------------------

    globalClock = millis();

    encoderField = 0;
    buttonField = 0;
    matrix();

    //-------------------------
    //---------SWITCHES--------
    //-------------------------

  //WHEEL BUTTONS

    pushButton(1, 3);
    pushButton(1, 4);
    pushButton(1, 6);
    pushButton(3, 1);
    pushButton(3, 2);
    pushButton(3, 3);
    pushButtonM(3, 4, 4);
    pushButton(4, 3);
    pushButton(4, 4);
    pushButton(4, 6);
    pushButton(4, 7);
    pushButton(6, 4);
    pushButtonM(6, 5, 5);
    pushButton(6, 6);
    pushButton(6, 7);
    pushButton(7, 1);
    pushButton(7, 3);

    toggleM(3, 5, 1);
    toggleM(6, 3, 2);
    toggleM(7, 2, 3);

    //SPECIALS

    modButton(1, 3);
    neutralButton(4, 5);
    biteButton(1, 5);


    //ENCODERS

    rotary2Inc(1, 1, true);
    rotary2Inc(4, 1, true);

    rotary2Inc(3, 6, true);
    rotary2Inc(6, 1, false);

    rotary2Inc(7, 4, true);

    //FUNKY SWITCHES
    funkyButtonDDButton(5, 4, 5, 1, 6, 7);
    funkyButtonHybrid(5, 6, 5, 1, 4, 7);
    funkyButton(5, 1, 5, 4, 6, 7);
    funkyButton(5, 7, 5, 1, 4, 6);
    funkyPush(5, 5, 1, 4, 6, 7);

    DDSfunky(5, 2, 3);

    funkyButton(2, 1, 5, 2, 4, 7);
    funkyButton(2, 2, 5, 1, 4, 7);
    funkyButton(2, 4, 5, 1, 2, 7);
    funkyButton(2, 7, 5, 1, 2, 4);
    funkyPush(2, 5, 1, 2, 4, 7);
    funkyRotary(2, 3, 6);

    //ANALOG INPUTS


    rotaryAnalog2Mode(
        A3,                                                           //Analog pin to read
        1,                                                            //Analog switch #
        1,                                                            //Field placement
        16, 107, 200, 291, 383, 474, 566, 657, 749, 841, 932, 1023,   //Switch position values
        false);                                                        //Rotation direction

    rotaryAnalog2Mode(
        A1,                                                           //Analog pin to read
        2,                                                            //Analog switch #
        2,                                                            //Field placement
        16, 107, 200, 291, 383, 474, 566, 657, 749, 841, 932, 1023,   //Switch position values
        false);                                                        //Rotation direction

    dualClutch(
        A2,                                                           //Analog pin to read (Master)
        4,                                                            //Analog switch # (Master)
        571,                                                          //Released value (Master
        169,                                                          //Fully pressed value (Master)
        A5,                                                           //Analog pin to read (Slave)
        6,                                                            //Analog switch # (Slave)
        527,                                                          //Released value (Slave)
        882,                                                          //Fully pressed value (Slave)
        true);                                                        //True = Master/Slave paddle is Throttle/Brake in mode 4. False is opposite.


    Joystick.setZAxis(encoderField - 32767);
    Joystick.setYAxis(buttonField - 32767);

    Joystick.sendState();
}
